#ifndef SWC_STRUCTURE_H
#define SWC_STRUCTURE_H
#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#define PI 3.14159


class swc_structure
{
private:


    // vector containing lines
    std::vector <cv::Vec4i> mv_linesvec;

    // vector containing circles
    std::vector <cv::Vec3f> mv_circlesVec;

    // vector of vectors containing contours
    std::vector<std::vector<cv::Point>> mv_contoursvec;

    // accumulator resolution parameters:
    double mv_deltaRho;
    double mv_deltaTheta;

    // minimum votes a line must have
    int mv_minVoteForLine;

    // minimum length for a line
    double mv_minLengthForLine;

    // maximum allowed gap along the line
    double mv_maxGap;


public:
    // default constructor
    swc_structure();

    // get lines vec
    std::vector<cv::Vec4i> mf_getLinesVec();

    // get circlesvec
    std::vector<cv::Vec3f> mf_getCirclesVec();

    // get contoursvec
    std::vector<std::vector<cv::Point>> mf_getContoursVec();

    // get min vote for line
    int mf_getMinVoteForLine() const;

    // get lines, the result of probabilistic hough transform
    bool mf_findLines(const cv::Mat& inputim);

    // get circles using probabilistic hough transform
    bool mf_findCircles(const cv::Mat& inputim);

    // get contours of connected components
    bool mf_findContours(const cv::Mat inputim);

    // draw estimated lines on the supplied image
    bool mf_drawHoughLinesP(cv::Mat &outputim, cv::Scalar color);

    // draw estimated circles on the supplied image
    bool mf_drawHoughCircles(cv::Mat& outputim, cv::Scalar color);

    // draw estimated contours on the supplied image
    bool mf_drawContours(cv::Mat& outputim);

    // draw bounding box
    bool mf_drawBoundingBoxUsingContours(cv::Mat& outputim);

    // draw minimum enclosing circle
    bool mf_drawMinEnclosingCirclesUsingContours(cv::Mat& outputim);

    // set min vote for line
    bool mf_setMinVoteForLine(const int minVote);

    // get min length for line
    double mf_getMinLineLength() const;

    // set min length for line
    bool mf_setMinLineLength(const double lineLength);

    // set accumulator resolution deltaRho
    bool mf_setDeltaRho(const double deltaRho);

    //get delta Rho
    double mf_getDeltaRho() const;

    // set delta Theta
    bool mf_setDeltaTheta(const double deltaTheta);

    // get delta Theta
    double mf_getDeltaTheta() const;

};

#endif // SWC_STRUCTURE_H
