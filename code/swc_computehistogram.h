#ifndef SWC_COMPUTEHISTOGRAM_H
#define SWC_COMPUTEHISTOGRAM_H

#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<vector>

// Algorithm for computing histogram of a uni-channel image
class swc_computeHistogram
{
private:
    // number of histogram bins
    int mv_nHistBins;

    // min and max intensity values
    float mv_intensityRange[2];


public:
    // Default constructor
    swc_computeHistogram();

    // Compute histogram normalized image
    void mf_computeHistogramNormalizedImage(const cv::Mat& inputim, cv::Mat& outputIm);

    // Returns histogram array of cv::Mat image
    cv::Mat mf_computeHistogram(const cv::Mat& inputim);

    // compute image bar graph of 1D histogram of input image
    void mf_computeHistogramImage(const cv::Mat& inputim, cv::Mat &histImage);

    // get number of histogram bins
    int mf_getnHistBins();

    // set number of histogram bins
    void mf_setnHistBins(int nHistBins);

    // get current intensity range for which hist is computed
    float *mf_getIntensityRange();

    // set intensity range
    void mf_setIntensityRange(float minIntensity, float maxIntensity);

};

#endif // SWC_COMPUTEHISTOGRAM_H
