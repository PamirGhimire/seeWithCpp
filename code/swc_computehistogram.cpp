#include "swc_computehistogram.h"

// default constructor
swc_computeHistogram::swc_computeHistogram()
{
    // initialize histogram with 256 bins
    mv_nHistBins = 256;

    // histogram considers intensities 0 <= i <= 255
    mv_intensityRange[0] = 0.0;
    mv_intensityRange[1] = 255.0;

}

//----------------------------------------------------------
// Method for computing histogram: uses mv_defaultChannel
cv::Mat swc_computeHistogram::mf_computeHistogram(const cv::Mat &inputim)
{
    const float* ptr_IntensityRange = {mv_intensityRange};
    bool uniform = true;
    bool accumulate = false;
    cv::Mat histArray;

    calcHist( &inputim,             // input image
              1,                    // number of channels in inputim
              0,                    // channel # to be considered
              cv::Mat(),            // mask
              histArray,            // destination array of histogram
              1,                    // dimensionality of histogram
              &mv_nHistBins,        // number of histogram bins
              &ptr_IntensityRange,  // min and max intensity limits
              uniform,              // define uniform histogram bins
              accumulate );         // no accumulation

    return histArray;

}

//----------------------------------------------------------
// Returns as an image bar graph of 1D histogram of input image
void swc_computeHistogram::mf_computeHistogramImage(const cv::Mat &inputim, cv::Mat& histImage)
{

    // Compute histogram first
    cv::Mat hist= mf_computeHistogram(inputim);

    // Get min and max bin values
    double maxVal=0;
    double minVal=0;
    cv::minMaxLoc(hist, &minVal, &maxVal, 0, 0);

    // Prepare image on which to display histogram
    histImage.create(cv::Size(mv_nHistBins, mv_nHistBins), CV_8U);
    histImage.setTo(cv::Scalar(255));

    // set highest point at 90% of nbins
    int hpt = static_cast<int>(0.9*mv_nHistBins);

    // Draw a vertical line for each bin
    for( int h = 0; h < mv_nHistBins; h++ ) {
        float binVal = hist.at<float>(h);
        int intensity = static_cast<int>(binVal*hpt/maxVal);

        // This function draws a line between 2 points
        cv::line(histImage,cv::Point(h,mv_nHistBins),
                cv::Point(h,mv_nHistBins-intensity),
                cv::Scalar::all(0));
    }

}
//----------------------------------------------------------
// get number of histogram bins
int swc_computeHistogram::mf_getnHistBins(){
    return mv_nHistBins;
}

//----------------------------------------------------------
// set number of histogram bins
void swc_computeHistogram::mf_setnHistBins(int nHistBins){
    mv_nHistBins = nHistBins;
}

//----------------------------------------------------------
// get current intensity range for which hist is computed
// Note to self: implementations like this can result in security issues
// since returning address of private member variable
float* swc_computeHistogram::mf_getIntensityRange(){
    return mv_intensityRange;
}

//----------------------------------------------------------
// set intensity range
void swc_computeHistogram::mf_setIntensityRange(float minIntensity, float maxIntensity){
    mv_intensityRange[0] = minIntensity;
    mv_intensityRange[1] = maxIntensity;
}

//----------------------------------------------------------
// Compute histogram normalized image
void swc_computeHistogram::mf_computeHistogramNormalizedImage(const cv::Mat& inputim, cv::Mat& outputim){
    // reallocate outputim if size and type not the same as input image
    outputim.create(inputim.size(), inputim.type());

    cv::equalizeHist(inputim, outputim);

}
