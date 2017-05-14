#ifndef SWC_MORPHOLOGY_H
#define SWC_MORPHOLOGY_H

#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>


class swc_morphology
{

private:
    // threshold for binarizing image before applying morphological operators
    int mv_bwThreshold;

    // array to hold binarized input image
    cv::Mat mv_inputImBinarized;

    // structuring element
    cv::Mat mv_structuringElement;

    // binarize input image using otsu's threshold, save result to mv_inputImBinarized
    bool mf_binarizeInputIm(const cv::Mat& inputIm);

public:
    // default constructor
    swc_morphology();

    // get mv_bwThreshold
    int mf_getbwThreshold() const;

    // set mv_bwThreshold
    bool mf_setbwThreshold(int bwThreshold);

    // get structuring element
    cv::Mat mf_getStructuringElement() const;

    // set structuring element
    bool mf_setStructuringElement(const cv::Mat &structuringElement);

    // get binarized image
    cv::Mat mf_getBinarizedInputIm() const;

    // get dilated input image
    bool mf_dilate(const cv::Mat& inputIm, cv::Mat& outputIm);

    // get eroded input image
    bool mf_erode(const cv::Mat& inputIm, cv::Mat& outputIm);

    // get opened input image
    bool mf_open(const cv::Mat& inputIm, cv::Mat& outputIm) const;

    // get closed input image
    bool mf_close(const cv::Mat& inputIm, cv::Mat& outputIm) const;

};

#endif // SWC_MORPHOLOGY_H
