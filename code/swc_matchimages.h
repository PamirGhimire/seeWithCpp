#ifndef SWC_MATCHIMAGES_H
#define SWC_MATCHIMAGES_H

#include<opencv2/core/core.hpp>
#include<opencv2/features2d/features2d.hpp>
#include<opencv2/xfeatures2d/nonfree.hpp>

class swc_matchImages
{

private:

    // surf detector
    cv::Ptr<cv::xfeatures2d::SurfFeatureDetector> mv_surfDetector;

    // surf descriptor
    cv::Ptr<cv::xfeatures2d::SurfDescriptorExtractor> mv_surfDescEx;

    // sift detector
    cv::Ptr<cv::xfeatures2d::SiftFeatureDetector> mv_siftDetector;

    // sift descriptor
    cv::Ptr<cv::xfeatures2d::SiftDescriptorExtractor> mv_siftDescEx;

    // brute force matcher
    cv::BFMatcher mv_matcher;


public:
    swc_matchImages();

    // match im1 and im2, descriptor = 1(sift) or 2(surf)
    bool mf_drawMatchesBwIm1and2(const cv::Mat& im1, const cv::Mat& im2, cv::Mat& outputim, int descriptor = 1);
};

#endif // SWC_MATCHIMAGES_H
