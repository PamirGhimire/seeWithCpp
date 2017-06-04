#include "swc_matchimages.h"

//----------------------------------------------------------
// Default constructor
//----------------------------------------------------------
swc_matchImages::swc_matchImages()
{
    // surf detector
    mv_surfDetector = cv::xfeatures2d::SurfFeatureDetector::create();

    // surf descriptor
    mv_surfDescEx = cv::xfeatures2d::SurfDescriptorExtractor::create();

    // sift detector
    mv_siftDetector = cv::xfeatures2d::SiftFeatureDetector::create();

    // sift descriptor
    mv_siftDescEx = cv::xfeatures2d::SiftDescriptorExtractor::create();

    // brute force matcher
    mv_matcher = cv::BFMatcher();
}



//----------------------------------------------------------
// match im1 and im2, descriptor = 1(sift) or 2(surf)
//----------------------------------------------------------
bool swc_matchImages::mf_drawMatchesBwIm1and2(const cv::Mat& im1, const cv::Mat& im2, cv::Mat& outputim, int descriptor){

    if (descriptor == 1){ // surf

        // extract keypoints and descriptors from image 1
        std::vector<cv::KeyPoint> im1kps;
        mv_surfDetector->detect(im1, im1kps);

        cv::Mat im1descs;
        mv_surfDescEx->compute(im1, im1kps, im1descs);

        // extract keypoints and descriptors from image 2
        std::vector<cv::KeyPoint> im2kps;
        mv_surfDetector->detect(im2, im2kps);

        cv::Mat im2descs;
        mv_surfDescEx->compute(im2, im2kps, im2descs);

        // match keypoints
        std::vector<cv::DMatch> matches;
        mv_matcher.match(im1descs, im2descs, matches);


    }
    else{ // sift, so default to sift if invalid

        // extract keypoints and descriptors from image 1
        std::vector<cv::KeyPoint> im1kps;
        mv_siftDetector->detect(im1, im1kps);

        cv::Mat im1descs;
        mv_siftDescEx->compute(im1, im1kps, im1descs);

        // extract keypoints and descriptors from image 2
        std::vector<cv::KeyPoint> im2kps;
        mv_siftDetector->detect(im2, im2kps);

        cv::Mat im2descs;
        mv_siftDescEx->compute(im2, im2kps, im2descs);

        // match keypoints
        std::vector<cv::DMatch> matches;
        mv_matcher.match(im1descs, im2descs, matches);

    }


    cv::drawMatches(im1, im1kps, im2, im2kps, matches, outputim, cv::Scalar::all(-1));

    return true;
}
