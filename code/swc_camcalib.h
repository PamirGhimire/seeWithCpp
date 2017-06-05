#ifndef SWC_CAMCALIB_H
#define SWC_CAMCALIB_H

#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/calib3d/calib3d.hpp>

#include<string>
#include<vector>


class swc_camCalib
{
    // input points:
    // the points in world coordinates
    std::vector<std::vector<cv::Point3f>> mv_objectPoints;

    // the point positions in pixels
    std::vector<std::vector<cv::Point2f>> mv_imagePoints;

    // output Matrices
    cv::Mat mv_cameraMatrix;
    cv::Mat mv_distCoeffs;

    // flag to specify how calibration is done
    int mv_flag;

    // used in image undistortion (x and y distortion maps)
    cv::Mat mv_map1, mv_map2;
    bool mv_mustInitUndistort;

    // list of file names of images to use for calibration
    std::vector<std::string> mv_fileList;

    // size of the chessboard in images (arbitrary units)
    cv::Size mv_boardSize;

    // size of chessboard images
    cv::Size mv_inputimSize;


public:
    // default constructor
    swc_camCalib();

    // get camera matrix
    cv::Mat mf_getCamMatrix();

    // get boardSize
    cv::Size mf_getBoardSize();

    // set boardSize
    bool mf_setBoardSize(const cv::Size& boardSize);

    // get list of file names of images to use for calibration
    std::vector<std::string> mf_getFileList();

    // set list of file names of images to use for calibration
    bool mf_setFileList(const std::vector<std::string>& fileList);

    // open chessboard images and extract corner points
    int mf_addChessboardPoints();

    // adds scene points and corresponding image points
    void mf_addPoints(const std::vector<cv::Point2f> & imageCorners, const std::vector<cv::Point3f>& objectCorners);

    // calibrates camera, returns re-projection error
    double mf_calibrate();

    // removes distortion in an image given corresponding camera matrix
    bool mf_remap(const cv::Mat &inputim, cv::Mat &outputim);


};

#endif // SWC_CAMCALIB_H
