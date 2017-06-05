#include "swc_camcalib.h"

//-------------------------------------------------------
// default constructor
//-------------------------------------------------------
swc_camCalib::swc_camCalib() : mv_flag(0), mv_mustInitUndistort(true){
    mv_boardSize = cv::Size(6, 4);

}

//-------------------------------------------------------
// get camera matrix
//-------------------------------------------------------
cv::Mat swc_camCalib::mf_getCamMatrix()
{
    return mv_cameraMatrix;
}


//-------------------------------------------------------
// get boardSize
//-------------------------------------------------------
cv::Size swc_camCalib::mf_getBoardSize(){
    return mv_boardSize;
}

//-------------------------------------------------------
// set boardSize
//-------------------------------------------------------
bool swc_camCalib::mf_setBoardSize(const cv::Size& boardSize){
    mv_boardSize = boardSize;
    return true;
}

//-------------------------------------------------------
// get list of file names of images to use for calibration
//-------------------------------------------------------
std::vector<std::string> swc_camCalib::mf_getFileList(){
    return mv_fileList;
}

//-------------------------------------------------------
// set list of file names of images to use for calibration
//-------------------------------------------------------
bool swc_camCalib::mf_setFileList(const std::vector<std::string>& fileList){
    mv_fileList = fileList;
    return true;
}

//-------------------------------------------------------
// open chessboard images and extract corner points
//-------------------------------------------------------
int swc_camCalib::mf_addChessboardPoints(){


    // the points on the chessboard
    std::vector<cv::Point2f> imageCorners;
    std::vector<cv::Point3f> objectCorners;

    // 3D Scene Points:
    // Initialize the chessboard corners
    // in the chessboard reference frame
    // The corners are at 3D location (X,Y,Z)= (i,j,0)
    for (int i=0; i< mv_boardSize.height; i++) {
        for (int j=0; j< mv_boardSize.width; j++) {
            // corners are : height (row), width (col), 0
            objectCorners.push_back(cv::Point3f(i, j, 0.0f));
        }
    }

    // 2D Image points:
    cv::Mat cbimage; // to contain chessboard image
    int successes = 0;

    // for all viewpoints (images)
    for (int i=0; i< mv_fileList.size(); i++) {
        // Open the image
        cbimage = cv::imread(mv_fileList[i],0);

        // Get the chessboard corners
        bool found = cv::findChessboardCorners(
                    cbimage, mv_boardSize, imageCorners);
        if (found){
            // Get subpixel accuracy on the corners
            cv::cornerSubPix(cbimage, imageCorners,
                             cv::Size(5,5),
                             cv::Size(-1,-1),
                             cv::TermCriteria(cv::TermCriteria::MAX_ITER +
                                              cv::TermCriteria::EPS,
                                              30,  // max number of iterations
                                              0.1)); // min accuracy

            //If we have a good board, add it to our data
            if (imageCorners.size() == mv_boardSize.area()) {
                // Add image and scene points from one view
                mf_addPoints(imageCorners, objectCorners);
                successes++;
            }
        }
    }

    // size of images used for calibration
    mv_inputimSize = cbimage.size();

    return successes;

}
//-------------------------------------------------------
// adds scene points and corresponding image points
//-------------------------------------------------------
void swc_camCalib::mf_addPoints(const std::vector<cv::Point2f> & imageCorners, const std::vector<cv::Point3f>& objectCorners){
    // 2D image points from one view
    mv_imagePoints.push_back(imageCorners);

    // corresponding 3D scene points
    mv_objectPoints.push_back(objectCorners);
}

//-------------------------------------------------------
// calibrates camera, returns re-projection error
//-------------------------------------------------------
double swc_camCalib::mf_calibrate(){

    // undistorter must be reinitialized
    mv_mustInitUndistort= true;

    // Output rotations and translations
    std::vector<cv::Mat> rvecs, tvecs;

    // start calibration
    return
            cv::calibrateCamera(mv_objectPoints, // the 3D points
                                mv_imagePoints, // the image points
                                mv_inputimSize, // image size
                                mv_cameraMatrix, // output camera matrix
                                mv_distCoeffs, // output distortion matrix
                                rvecs, tvecs, // Rs, Ts
                                mv_flag); // set options

}

//-------------------------------------------------------
// removes distortion in an image given corresponding camera matrix
//-------------------------------------------------------
bool swc_camCalib::mf_remap(const cv::Mat &inputim, cv::Mat& outputim){

    if (mv_mustInitUndistort) { // called once per calibration
        cv::initUndistortRectifyMap(
                    mv_cameraMatrix, // computed camera matrix
                    mv_distCoeffs,   // computed distortion matrix
                    cv::Mat(),       // optional rectification (none)
                    cv::Mat(),       // camera matrix to generate undistorted
                    inputim.size(),    // size of undistorted
                    CV_32FC1,        // type of output map
                    mv_map1, mv_map2);     // the x and y mapping functions

        mv_mustInitUndistort= false;
    }

    // Apply mapping functions
    cv::remap(inputim, outputim, mv_map1, mv_map2,
              cv::INTER_LINEAR); // interpolation type

    return true;

}
