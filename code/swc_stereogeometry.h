#ifndef SWC_STEREOGEOMETRY_H
#define SWC_STEREOGEOMETRY_H

#include<opencv2/core/core.hpp>
#include<opencv2/calib3d/calib3d.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class swc_stereoGeometry
{
private:
    // method to be used for estimating fundamental matrix
    int mv_methodFlag;

public:
    // default constructor
    swc_stereoGeometry();

    // get method flag
    int mf_getFMethodFlag();

    // set method flag
    bool mf_setFMethodFlag(int mflag);

    // estimates fundamental matrix from point correspondences type cv::keypoint
    cv::Mat mf_getFundamentalMatrix(const std::vector<cv::Point2f>& selPoints1, const std::vector<cv::Point2f>& selPoints2);

    // estimates fundamental matrix from point correspondences type cv::point2f
    cv::Mat mf_getFundamentalMatrix(const std::vector<cv::KeyPoint>& keypoints1, const std::vector<cv::KeyPoint>& keypoints2);

    // draw epipolar lines, if imindex == 1, selPoints come from left image
    bool mf_drawEpipolarLines(const cv::Mat fundamental, const std::vector<cv::Point2f> selPoints, const cv::Mat& inputim, int imindex);

};

#endif // SWC_STEREOGEOMETRY_H
