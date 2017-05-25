#ifndef SWC_INTERESTPOINTS_H
#define SWC_INTERESTPOINTS_H

#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/features2d/features2d.hpp>


class swc_interestPoints
{
private:
    //----------------------------
    // HARRIS CORNERS:
    //----------------------------
    // harris neighbourhood size
    int mv_harrisNeighbourhoodSize;

    // harris aperture size
    int mv_harrisApertureSize;

    // harris parameter
    float mv_harrisParameter;

    // harris corner map
    cv::Mat mv_harrisCornerStrengthMap;

    // non-maxima suppressed corner map
    cv::Mat mv_cornerMap;

    // global maximum of harris corner strength map
    double mv_maxStrength;

    // map of local maxima after processing strength map
    cv::Mat mv_localMax;

    // used for specifying threshold for thresholding cornerStrength map
    double mv_qualityLevel;

    // thresholded corner strength map
    cv::Mat mv_thCornerStrengthMap;

    // harris corner map threshold
    double mv_harrisCornerThreshold;

    // detected locations of Harris corner points
    std::vector<cv::Point> mv_harrisCornerPoints;
    //----------------------------
    // HARRIS CORNERS ENDS:
    //----------------------------

    //----------------------------
    // FAST:
    //----------------------------
    cv::FastFeatureDetector* mv_fastDetector;

    // vector containing fast keypoints
    std::vector<cv::KeyPoint> mv_fastKeypoints;

    //----------------------------
    // SURF:
    //----------------------------



public:
    // default constructor
    swc_interestPoints();

    // detect fast keypoints
    bool mf_detectFastKeypoints(const cv::Mat& inputim);

    // draw detected fast keypoints
    bool mf_drawFastKeypointsOnImage(const cv::Mat& inputim, cv::Mat& outputim);

    // detect corner points in input, plot them in output
    void mf_drawHarrisCornersOnImage(const cv::Mat &inputim, cv::Mat& outputim);

    // get locations of corner points from the corner map
    void mf_computeCornerPoints();

    // get corner map from computed harris values
    bool mf_computeCornerMap();

    // compute harris values at all pixel locations
    bool mf_computeHarrisValues(const cv::Mat& inputim);

    // get harris neighbourhood size
    int mf_getHarrisNeighbourhoodSize() const;

    // set harris neighbourhood size
    bool mf_setHarrisNeighbourhoodSize(int nsize);

    // get harris aperture size
    int mf_getHarrisApertureSize() const;

    // set harris aperture size
    bool mf_serHarrisApertureSize(int apertureSize);

    // get harris parameter
    float mf_getHarrisParameter() const;

    // set harris parameter
    bool mf_setHarrisParameter(float hparameter);

    // get threshold for harris corner map
    double mf_getHarrisCornerThreshold() const;

    // set threshold for harris corner map
    bool mf_setHarrisCornerThreshold(double hcornerThresh);


};

#endif // SWC_INTERESTPOINTS_H
