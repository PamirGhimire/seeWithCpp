#include "swc_stereogeometry.h"

//------------------------------------------
// default constructor
//------------------------------------------
swc_stereoGeometry::swc_stereoGeometry()
{
    // default method for estimating fundamental matrix is 8point alg.
    mv_methodFlag = 8;
}

//------------------------------------------
// get method flag
//------------------------------------------
int swc_stereoGeometry::mf_getFMethodFlag(){
    return mv_methodFlag;
}

//------------------------------------------
// set method flag
//------------------------------------------
bool swc_stereoGeometry::mf_setFMethodFlag(int mflag){

    if (mflag == 7 || mflag == 8){
        mv_methodFlag = mflag;
        return true;
    }else{
        return false;
    }
}

//------------------------------------------
// estimates fundamental matrix from 7 matches, takes type cv::keypoint
//------------------------------------------
cv::Mat swc_stereoGeometry::mf_getFundamentalMatrix(const std::vector<cv::Point2f>& selPoints1, const std::vector<cv::Point2f>& selPoints2){
    // Compute F matrix from 7/8 matches
    cv::Mat fundamental= cv::findFundamentalMat(
                cv::Mat(selPoints1), // points in first image
                cv::Mat(selPoints2), // points in second image
                mv_methodFlag == 7?CV_FM_7POINT:CV_FM_8POINT); // 7/8-point method

    return fundamental;
}

//------------------------------------------
// estimates fundamental matrix from point correspondences type cv::point2f
//------------------------------------------
cv::Mat swc_stereoGeometry::mf_getFundamentalMatrix(const std::vector<cv::KeyPoint>& keypoints1, const std::vector<cv::KeyPoint>& keypoints2){

    // convert keypoints to point2f
    std::vector<cv::Point2f> selPoints1, selPoints2;

    // assumes that corresponding points are in same order in two vectors
    cv::KeyPoint::convert(keypoints1,selPoints1);
    cv::KeyPoint::convert(keypoints2,selPoints2);

    // Compute F matrix from 7 matches
    cv::Mat fundamental= cv::findFundamentalMat(
                cv::Mat(selPoints1), // points in first image
                cv::Mat(selPoints2), // points in second image
                mv_methodFlag == 7?CV_FM_7POINT:CV_FM_8POINT);       // 7-point method

    return fundamental;
}

//------------------------------------------
// draw epipolar lines
//------------------------------------------
bool swc_stereoGeometry::mf_drawEpipolarLines(const cv::Mat fundamental, const std::vector<cv::Point2f> selPoints, const cv::Mat& inputim, int imindex){

    // draw the left/right points corresponding epipolar
    // lines in right/left image
    std::vector<cv::Vec3f> lines;

    cv::computeCorrespondEpilines(
                cv::Mat(selPoints), // image points
                imindex, // in image 1 (can also be 2)
                fundamental, // F matrix
                lines);

    // vector of epipolar lines
    // for all epipolar lines
    for (std::vector<cv::Vec3f>::const_iterator it= lines.begin();
         it!=lines.end(); ++it) {
        // draw the line between first and last column
        cv::line(inputim,
                 cv::Point(0,-(*it)[2]/(*it)[1]),
                cv::Point(inputim.cols,-((*it)[2]+
                          (*it)[0]*inputim.cols)/(*it)[1]),
                cv::Scalar(255,255,255));
    }


    return true;

}
