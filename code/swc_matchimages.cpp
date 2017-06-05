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

    if (descriptor == 2){ // surf

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


    }

    mv_funmat12 = cv::findFundamentalMat(imgpts1,imgpts2,cv::FM_RANSAC,0.1,0.99);
    outfunmat12 = mv_funmat12;
    return true;
}
//----------------------------------------------------------
// draw epipolar lines in im1 and im2 using the estimated fundamental mat
//----------------------------------------------------------
bool swc_matchImages::mf_drawEpipolarLinesIm1and2(const cv::Mat& im1, const cv::Mat& im2, cv::Mat& outputim){

    // Convert keypoints into Point2f
    std::vector<cv::Point2f> selPoints1, selPoints2;
    std::vector<int> pointIndexes1 = {1, 2, 3, 4, 5};
    std::vector<int> pointIndexes2 = {1, 2, 3, 4, 5};

    cv::KeyPoint::convert(mv_im1kps,selPoints1,pointIndexes1);
    cv::KeyPoint::convert(mv_im2kps,selPoints2,pointIndexes2);

    // Initialize images for drawing epipolar lines
    cv::Mat im2_el; im2.copyTo(im2_el, cv::Mat());
    cv::Mat im1_el; im1.copyTo(im1_el, cv::Mat());
    outputim.create(im1.cols + im2.cols, im1.rows + im2.rows, im1.type());


    // left points lines in right = lines1
    std::vector<cv::Vec3f> lines1;

    cv::computeCorrespondEpilines(
                cv::Mat(selPoints1), // image points
                1,                   // in image 1 (can also be 2)
                mv_funmat12,         // F matrix
                lines1);             // vector of epipolar lines

    // right points lines in left = lines2
    std::vector<cv::Vec3f> lines2;
    cv::computeCorrespondEpilines(
                cv::Mat(selPoints2), // image points
                2,                   // in image 2 (can also be 1)
                mv_funmat12,         // F matrix
                lines2);             // vector of epipolar lines


    // for all epipolar lines (in right image)
    for (std::vector<cv::Vec3f>::const_iterator it= lines1.begin();
         it!=lines1.end(); ++it) {

        // draw the line between first and last column
        cv::line(im2_el,
                 cv::Point(0,-(*it)[2]/(*it)[1]),
                cv::Point(im2_el.cols,-((*it)[2]+
                          (*it)[0]*im2_el.cols)/(*it)[1]),
                cv::Scalar(255,255,255));
    }


    // for all epipolar lines (in left image)
    for (std::vector<cv::Vec3f>::const_iterator it= lines2.begin();
         it!=lines2.end(); ++it) {

        // draw the line between first and last column
        cv::line(im1_el,
                 cv::Point(0,-(*it)[2]/(*it)[1]),
                cv::Point(im1_el.cols,-((*it)[2]+
                          (*it)[0]*im1_el.cols)/(*it)[1]),
                cv::Scalar(255,255,255));
    }

    cv::hconcat(im1_el, im2_el, outputim);

    return true;
}


