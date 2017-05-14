#include "swc_morphology.h"

swc_morphology::swc_morphology()
{
    // Initialize member variables: arbitrary initializations

    // threshold for binarizing image, non-sense initialization,
    // if not changed, use otsu's thresholding
    mv_bwThreshold = -100;

    // binarized input image
    mv_inputImBinarized = cv::Mat(cv::Size(100, 100), CV_8UC1, cv::Scalar(0));

    // structuring element: initialized as a 5x5 diamond
    mv_structuringElement = cv::Mat(cv::Size(5, 5), CV_8UC1, cv::Scalar(1));
    mv_structuringElement.at<uchar>(0,0)= 0;
    mv_structuringElement.at<uchar>(0,1)= 0;
    mv_structuringElement.at<uchar>(1,0)= 0;
    mv_structuringElement.at<uchar>(4,4)= 0;
    mv_structuringElement.at<uchar>(3,4)= 0;
    mv_structuringElement.at<uchar>(4,3)= 0;
    mv_structuringElement.at<uchar>(4,0)= 0;
    mv_structuringElement.at<uchar>(4,1)= 0;
    mv_structuringElement.at<uchar>(3,0)= 0;
    mv_structuringElement.at<uchar>(0,4)= 0;
    mv_structuringElement.at<uchar>(0,3)= 0;
    mv_structuringElement.at<uchar>(1,4)= 0;

}

//-------------------------------------------------
// Binarize input image using otsu's threshold, save result to mv_inputImBinarized
//-------------------------------------------------

bool swc_morphology::mf_binarizeInputIm(const cv::Mat& inputIm){

    // otsu's thresholding if non-sense initialization of threshold was not changed
    if (mv_bwThreshold < 0){
        cv::threshold(inputIm, mv_inputImBinarized, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    }
    // else, threshold at specified gray level
    else{
        cv::threshold(inputIm, mv_inputImBinarized, mv_bwThreshold, 255, CV_THRESH_BINARY);
    }

    return true;
}

//-------------------------------------------------
// get mv_bwThreshold
//-------------------------------------------------
int swc_morphology::mf_getbwThreshold() const{
    return mv_bwThreshold;
}

//-------------------------------------------------
// set mv_bwThreshold
//-------------------------------------------------
bool swc_morphology::mf_setbwThreshold(int bwThreshold){
    mv_bwThreshold = bwThreshold;
    return true;
}

//-------------------------------------------------
// get structuring element
//-------------------------------------------------
cv::Mat swc_morphology::mf_getStructuringElement() const{
    return mv_structuringElement;
}

//-------------------------------------------------
// set structuring element
//-------------------------------------------------
bool swc_morphology::mf_setStructuringElement(const cv::Mat& structuringElement){
    structuringElement.copyTo(mv_structuringElement);
    return true;
}

//-------------------------------------------------
// get binarized image
//-------------------------------------------------
cv::Mat swc_morphology::mf_getBinarizedInputIm() const{
    return mv_inputImBinarized;
}

//-------------------------------------------------
// get dilated input image
//-------------------------------------------------
bool swc_morphology::mf_dilate(const cv::Mat& inputIm, cv::Mat& outputIm) {
    // binarize the input image
    mf_binarizeInputIm(inputIm);

    // perform dilation on the binarized image
    cv::dilate(mv_inputImBinarized, outputIm, mv_structuringElement);

    return true;
}

//-------------------------------------------------
// get eroded input image
//-------------------------------------------------
bool swc_morphology::mf_erode(const cv::Mat& inputIm, cv::Mat& outputIm){
    // binarize the input image
    mf_binarizeInputIm(inputIm);

    // perform erosion on the binarized image
    cv::erode(mv_inputImBinarized, outputIm, mv_structuringElement);

    return true;
}

//-------------------------------------------------
// get opened input image
//-------------------------------------------------
bool swc_morphology::mf_open(const cv::Mat& inputIm, cv::Mat& outputIm){

    // binarize
    mf_binarizeInputIm(inputIm);
    cv::Mat mv_temp;

    // erode
    mf_erode(mv_inputImBinarized, mv_temp);

    // dilate
    mf_dilate(mv_temp, outputIm);

    return true;
}

//-------------------------------------------------
// get closed input image
//-------------------------------------------------
bool swc_morphology::mf_close(const cv::Mat& inputIm, cv::Mat& outputIm){

    // binarize
    mf_binarizeInputIm(inputIm);
    cv::Mat mv_temp;

    // dilate
    mf_dilate(mv_inputImBinarized, mv_temp);

    // erode
    mf_erode(mv_temp, outputIm);

    return true;
}
