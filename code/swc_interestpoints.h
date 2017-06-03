#ifndef SWC_INTERESTPOINTS_H
#define SWC_INTERESTPOINTS_H

#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/features2d/features2d.hpp>
#include<opencv2/xfeatures2d/nonfree.hpp>

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
    // fast detector
    cv::FastFeatureDetector* mv_fastDetector;

    // vector containing fast keypoints
    std::vector<cv::KeyPoint> mv_fastKeypoints;

    //----------------------------
    // SURF:
    //----------------------------
    // surf detector
    cv::xfeatures2d::SurfFeatureDetector* mv_surfDetector;
    //cv::Ptr<cv::xfeatures2d::SURF> mv_surfDetector;

    // vector containing surf keypoints
    std::vector<cv::KeyPoint> mv_surfKeypoints;

    // surf descriptors
    cv::xfeatures2d::SurfDescriptorExtractor* mv_surfDescEx;
    //cv::Ptr<cv::xfeatures2d::SurfDescriptorExtractor> mv_surfDescEx;
    cv::Mat mv_surfDescriptors;

    //----------------------------
    // SIFT:
    //----------------------------
    // sift detector
    cv::xfeatures2d::SIFT* mv_siftDetector;

    // vector containing sift keypoints
    std::vector<cv::KeyPoint> mv_siftKeypoints;

    // sift descriptors
    cv::xfeatures2d::SiftDescriptorExtractor* mv_siftDescEx;
    cv::Mat mv_siftDescriptors;

public:
    // default constructor
    swc_interestPoints();

    // detect sift keypoints
    bool mf_detectSiftKeypoints(const cv::Mat& inputim);

    // extract sift description at sift keypoints
    bool mf_extractSiftDescriptors(const cv::Mat& inputim);

    // get sift keypoints
    std::vector<cv::KeyPoint> mf_getSiftKeypoints();

    // detect surf keypoints
    bool mf_detectSurfKeypoints(const cv::Mat& inputim);

    // extract surf description at surf keypoints
    bool mf_extractSurfDescriptors(const cv::Mat& inputim);

    // get surf keypoints
    std::vector<cv::KeyPoint> mf_getSurfKeypoints();

    // detect fast keypoints
    bool mf_detectFastKeypoints(const cv::Mat& inputim);

    // get fast keypoints
    std::vector<cv::KeyPoint> mf_getFastKeypoints();

    // draw detected keypoints, keyPointCode = 1 (fast), 2(surf), 3(sift)
    bool mf_drawKeypointsOnImage(const cv::Mat& inputim, cv::Mat& outputim, int keyPointCode);

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
