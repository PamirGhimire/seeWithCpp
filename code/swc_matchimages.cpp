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
// Find matches between images 1 and 2, descriptor = 1(sift) or 2(surf)
//----------------------------------------------------------
bool swc_matchImages::mf_matchImage1and2(const cv::Mat& im1, const cv::Mat& im2, int descriptor){

    // keypoints and descriptors for im1
    cv::Mat im1descs;

    // keypoints and descriptors for im2
    cv::Mat im2descs;

    if (descriptor == 1){ // surf

        // extract keypoints and descriptors from image 1
        mv_surfDetector->detect(im1, mv_im1kps);
        mv_surfDescEx->compute(im1, mv_im1kps, im1descs);

        // extract keypoints and descriptors from image 2
        mv_surfDetector->detect(im2, mv_im2kps);
        mv_surfDescEx->compute(im2, mv_im2kps, im2descs);

    }

    else{ // sift, so default to sift if invalid

        // extract keypoints and descriptors from image 1
        mv_siftDetector->detect(im1, mv_im1kps);
        mv_siftDescEx->compute(im1, mv_im1kps, im1descs);

        // extract keypoints and descriptors from image 2
        mv_siftDetector->detect(im2, mv_im2kps);
        mv_siftDescEx->compute(im2, mv_im2kps, im2descs);

    }


    // match keypoints
    mv_matcher.match(im1descs, im2descs, mv_matches_Im12);

    std::nth_element(mv_matches_Im12.begin(),    // initial position
                     mv_matches_Im12.begin()+24, // position of the sorted element
                     mv_matches_Im12.end());     // end position

    // remove all elements after the 25th
    mv_matches_Im12.erase(mv_matches_Im12.begin()+25, mv_matches_Im12.end());

    return true;
}


//----------------------------------------------------------
// draw matches between im1 and im2, descriptor = 1(sift) or 2(surf)
//----------------------------------------------------------
bool swc_matchImages::mf_drawMatchesBwIm1and2(const cv::Mat& im1, const cv::Mat& im2, cv::Mat& outputim, int descriptor){
    mf_matchImage1and2(im1, im2, descriptor);
    cv::drawMatches(im1, mv_im1kps, im2, mv_im2kps, mv_matches_Im12, outputim, cv::Scalar::all(-1));
    return true;
}

//----------------------------------------------------------
// find fundamental matrix between im1 and im2
//----------------------------------------------------------
bool swc_matchImages::mf_findFundamentalIm1and2(cv::Mat& outfunmat12){

    // corresponding points from im1 and im2
    std::vector<cv::Point2f>imgpts1,imgpts2;

    for( unsigned int i = 0; i<mv_matches_Im12.size(); i++ ){

        // query the left image
        imgpts1.push_back(mv_im1kps[mv_matches_Im12[i].queryIdx].pt);
        // query the right image
        imgpts2.push_back(mv_im2kps[mv_matches_Im12[i].trainIdx].pt);

        outfunmat12 = cv::findFundamentalMat(imgpts1,imgpts2,cv::FM_RANSAC,0.1,0.99);

    }

    return true;
}



