#ifndef SWC_CONTROLLER_H
#define SWC_CONTROLLER_H

#include<stdio.h>
#include<string>

#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<qdebug.h>

#include"swc_addnoisesaltandpepper.h"
#include"swc_addlogo.h"
#include "swc_computehistogram.h"
#include "swc_morphology.h"
#include "swc_kernelprocess.h"

class swc_controller
{

private:

    // Internal Variables:
    cv::Mat mv_inputim;
    cv::Mat mv_outputim;

    //------------------------------------------------------------
    // MODELS:
    //------------------------------------------------------------
    // Salt and pepper noise model
    //------------------------------------------------------------
    swc_addNoiseSaltAndPepper* mod_addNoiseSaltAndPepper;

    //------------------------------------------------------------
    // Add logo model
    //------------------------------------------------------------
    swc_addLogo* mod_addLogo;

    //------------------------------------------------------------
    // Compute Histogram model
    //------------------------------------------------------------
    swc_computeHistogram* mod_computeHistogram;

    //------------------------------------------------------------
    // Morphology model
    //------------------------------------------------------------
    swc_morphology* mod_morphology;

    //------------------------------------------------------------
    // Kernel model
    //------------------------------------------------------------
    swc_kernelProcess* mod_kernel;

    //------------------------------------------------------------
    //
    //------------------------------------------------------------
public:
    // Controller : Default constructor:
    swc_controller();

    // Controller : Default Destructor:
    ~swc_controller();

    //------------------------------------------------------------
    // Controller:
    //------------------------------------------------------------

    // Set input image;
    bool mf_setInputImage(std::string filename);

    // Get the current input image
    cv::Mat mf_getInputImage() const;

    // Get the current output image (latest result of processing)
    cv::Mat mf_getOutputImage() const;


    //------------------------------------------------------------
    // MODELS:
    //------------------------------------------------------------

    //------------------------------------------------------------
    // Salt and pepper noise model:
    //------------------------------------------------------------

    // add noise to input image in controller
    void addNoiseSaltAndPepper_process();

    // get the number of pixels that the algorithm corrupts
    int addNoiseSaltAndPepper_get_NcorruptedPixels();

    // set the number of pixels that the algorithm is to corrupt
    void addNoiseSaltAndPepper_set_NcorruptedPixels(int n);


    //------------------------------------------------------------
    // Add Logo model:
    //------------------------------------------------------------

    // get logo
    cv::Mat addLogo_getLogo() const;

    // set logo image
    bool addLogo_setLogo(std::string logoFilename);

    // add logo to a given image
    void addLogo_process_addLogoTo();

    // get logo width
    int addLogo_getLogoWidth() const;

    // set logo width
    void addLogo_setLogoWidth(int logoWidth);

    // get logo height
    int addLogo_getLogoHeight() const;

    // set logo height
    void addLogo_setLogoHeight(int logoHeight) const;

    //------------------------------------------------------------
    // Compute Histogram model:
    //------------------------------------------------------------

    // Compute histogram normalized image
    void computeHistogram_process_computeHistogramNormalizedImage();

    // Returns histogram array of cv::Mat image
    cv::Mat computeHistogram_process_computeHistogram();

    // compute image bar graph of 1D histogram of input image
    cv::Mat computeHistogram_process_computeHistogramImage();

    // get number of histogram bins
    int computeHistogram_getnHistBins();

    // set number of histogram bins
    void computeHistogram_setnHistBins(int nHistBins);

    // get current intensity range for which hist is computed
    float *computeHistogram_getIntensityRange();

    // set intensity range
    void computeHistogram_setIntensityRange(float minIntensity, float maxIntensity);

    //------------------------------------------------------------
    // Process manager model:
    //------------------------------------------------------------
    std::string getOneViewProcessName(int oneViewProcessCode);



    //------------------------------------------------------------
    // Morphology model:
    //------------------------------------------------------------
    // get mv_bwThreshold
    int morphology_getbwThreshold() const;

    // set mv_bwThreshold
    bool morphology_setbwThreshold(int bwThreshold);

    // get structuring element
    cv::Mat morphology_getStructuringElement() const;

    // set structuring element
    bool morphology_setStructuringElement(const cv::Mat &structuringElement);

    // get binarized image
    cv::Mat morphology_getBinarizedInputIm() const;

    // get dilated input image
    bool morphology_dilate();

    // get eroded input image
    bool morphology_erode();

    // get opened input image
    bool morphology_open() ;

    // get closed input image
    bool morphology_close() ;


    //------------------------------------------------------------
    // Kernel model
    //------------------------------------------------------------
    // get lower threshold for canny
    double kernel_getCannyLowerThresh() const;

    // set lower threshold for canny
    bool kernel_setCannyLowerThresh(const double lowerThresh);

    // get upper threshold for canny
    double kernel_getCannyUpperThresh() const;

    // set upper threshold for canny
    bool kernel_setCannyUpperThresh(const double upperThresh);

    // get the current size of Gaussian kernel
    int kernel_getGaussKernelSize() const;

    // set the size of Gaussian kernel
    bool kernel_setGaussKernelSize(int gsize);

    // get the variance of Gaussian Kernel
    int kernel_getGaussSigma() const;

    // set the variance of Gaussian Kernel
    bool kernel_setGaussSigma(int gSigma);

    // returns current kernel
    cv::Mat kernel_getKernel();

    // set kernel for filtering
    bool kernel_setKernel(const cv::Mat& kernel);

    // blur image using gaussian smoothing
    bool kernel_gaussianBlur();

    // filter image using sobel operator
    bool kernel_filterSobel();

    // apply laplacian operator to the image
    bool kernel_filterLaplacian();

    // sharpen image using laplacian
    bool kernel_filterLaplacianSharpen();

    // apply a custom kernel
    bool kernel_filterCustomKernel();

    // detect edges using canny
    bool kernel_filterCanny();

    // apply median filter
    bool kernel_filterMedian();

    //------------------------------------------------------------
    //
    //------------------------------------------------------------

};

#endif // SWC_CONTROLLER_H
