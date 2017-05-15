#ifndef SWC_KERNELPROCESS_H
#define SWC_KERNELPROCESS_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class swc_kernelProcess
{
private:
    // 2D kernel for filtering images
    cv::Mat mv_kernel;

    // size of the gaussian kernel (for smoothing)
    int mv_gaussKernelSize;
    // variance of the gaussian kernel (for smoothing)
    int mv_gaussSigma;

    // lower threshold for canny
    int mv_cannyLowerThresh;

    // upper threshold for canny
    int mv_cannyUpperThresh;

    // aperture size for canny
    int mv_cannyAperture;

public:
    // default constructor
    swc_kernelProcess();

    // get lower threshold for canny
    double mf_getCannyLowerThresh() const;

    // set lower threshold for canny
    bool mf_setCannyLowerThresh(const double lowerThresh);

    // get upper threshold for canny
    double mf_getCannyUpperThresh() const;

    // set upper threshold for canny
    bool mf_setCannyUpperThresh(const double upperThresh);

    // get the current size of Gaussian kernel
    int mf_getGaussKernelSize() const;

    // set the size of Gaussian kernel
    bool mf_setGaussKernelSize(int gsize);

    // get the variance of Gaussian Kernel
    int mf_getGaussSigma() const;

    // set the variance of Gaussian Kernel
    bool mf_setGaussSigma(int gSigma);

    // returns current kernel
    cv::Mat mf_getKernel();

    // set kernel for filtering
    bool mf_setKernel(const cv::Mat& kernel);

    // blur image using gaussian smoothing
    bool mf_gaussianBlur(const cv::Mat& inputIm, cv::Mat& outputIm) const;

    // filter image using sobel operator
    bool mf_filterSobel(const cv::Mat& inputIm, cv::Mat& outputIm) const;

    // apply laplacian operator to the image
    bool mf_filterLaplacian(const cv::Mat& inputIm, cv::Mat& outputIm) const;

    // sharpen image using laplacian
    bool mf_filterLaplacianSharpen(const cv::Mat& inputIm, cv::Mat& outputIm) const;

    // apply a custom kernel
    bool mf_filterCustomKernel(const cv::Mat& inputIm, cv::Mat& outputIm) const;

    // detect edges using canny
    bool mf_filterCanny(const cv::Mat& inputIm, cv::Mat& outputIm) const;

    // apply median filter
    bool mf_filterMedian(const cv::Mat& inputIm, cv::Mat& outputIm) const;

};

#endif // SWC_KERNELPROCESS_H
