#include "swc_kernelprocess.h"

//---------------------------------------------------
// Default constructor
//---------------------------------------------------
swc_kernelProcess::swc_kernelProcess()
{
    // initialize member variables

    // initialize kernel as 3x3 identity transform
    mv_kernel = cv::Mat(3, 3, CV_32F, cv::Scalar(0));
    mv_kernel.at<float>(1, 1) = 1;

    // default gaussian kernel is 3x3
    mv_gaussKernelSize = 3;

    // default gaussian kernel's sigma is 0.5
    mv_gaussSigma = 0.5;

    // default lower threshold for canny is 125
    mv_cannyLowerThresh = 125;

    // default upper threshold for canny is 350
    mv_cannyUpperThresh = 350;

    // default aperture size for canny is 3
    mv_cannyAperture = 3;

}

//---------------------------------------------------
// return current kernel
//---------------------------------------------------
cv::Mat swc_kernelProcess::mf_getKernel(){
    return mv_kernel;
}

//---------------------------------------------------
// set kernel for filtering
//---------------------------------------------------
bool swc_kernelProcess::mf_setKernel(const cv::Mat& kernel){
    // reallocate mv_kernel so that it can accept input kernel
    mv_kernel.create(kernel.size(), kernel.type());

    // copy the input kernel to mv_kernel
    kernel.copyTo(mv_kernel);

    return true;
}
//---------------------------------------------------
// blur image using gaussian smoothing
//---------------------------------------------------
bool swc_kernelProcess::mf_gaussianBlur(const cv::Mat& inputIm, cv::Mat& outputIm) const{
    cv::GaussianBlur(inputIm, outputIm, cv::Size(mv_gaussKernelSize, mv_gaussKernelSize), mv_gaussSigma);
    return true;
}
//---------------------------------------------------
// get the current size of Gaussian kernel
//---------------------------------------------------
int swc_kernelProcess::mf_getGaussKernelSize() const{
    return mv_gaussKernelSize;
}
//---------------------------------------------------
// set the size of Gaussian kernel
//---------------------------------------------------
bool swc_kernelProcess::mf_setGaussKernelSize(int gsize){
    mv_gaussKernelSize = gsize;
    return true;
}
//---------------------------------------------------
// get the variance of Gaussian Kernel
//---------------------------------------------------
int swc_kernelProcess::mf_getGaussSigma() const{
    return mv_gaussSigma;
}

//---------------------------------------------------
// set the variance of Gaussian Kernel
//---------------------------------------------------
bool swc_kernelProcess::mf_setGaussSigma(int gSigma){
    mv_gaussSigma = gSigma;
    return true;
}
//---------------------------------------------------
// apply median filter
//---------------------------------------------------
bool swc_kernelProcess::mf_filterMedian(const cv::Mat& inputIm, cv::Mat& outputIm) const{
    cv::medianBlur(inputIm, outputIm, 5);
    return true;
}
//---------------------------------------------------
// filter image using sobel operator
//---------------------------------------------------
bool swc_kernelProcess::mf_filterSobel(const cv::Mat& inputIm, cv::Mat& outputIm) const{

    // declare variables to contain intensity derivatives
    cv::Mat sobelx, sobely, sobeledge;

    // compute derivatives
    cv::Sobel(inputIm, sobelx, CV_16SC1, 1, 0);
    cv::Sobel(inputIm, sobely, CV_16SC1, 0, 1);

    // use l1 norm to approximate true derivative
    sobeledge = cv::abs(sobelx) + cv::abs(sobely);
    sobeledge.convertTo(outputIm, CV_8UC1);

    return true;
}

//---------------------------------------------------
// apply laplacian operator to the image
//---------------------------------------------------
bool swc_kernelProcess::mf_filterLaplacian(const cv::Mat& inputIm, cv::Mat& outputIm) const{
    // create matrix to contain the laplacian
    cv::Mat laplacianIm;

    // compute the laplacian
    cv::Laplacian(inputIm, laplacianIm, CV_16SC1, 5);

    // I x aplha + beta
    laplacianIm = 0.5*laplacianIm + 128;

    // output 8 bit conversion
    laplacianIm.convertTo(outputIm, CV_8UC1);

    return true;
}

//---------------------------------------------------
// sharpen image using laplacian
//---------------------------------------------------
bool swc_kernelProcess::mf_filterLaplacianSharpen(const cv::Mat& inputIm, cv::Mat& outputIm) const{
    // get laplacian of input image
    cv::Mat laplacianIm;
    mf_filterLaplacian(inputIm, laplacianIm);

    // subtract laplacian from the input
    cv::subtract(inputIm, laplacianIm, outputIm);

    return true;
}
//---------------------------------------------------
// apply a custom kernel
//---------------------------------------------------
bool swc_kernelProcess::mf_filterCustomKernel(const cv::Mat& inputIm, cv::Mat& outputIm) const{
    cv::filter2D(inputIm, outputIm, CV_8UC1, mv_kernel);
    return true;
}

//---------------------------------------------------
// detect edges using canny
bool swc_kernelProcess::mf_filterCanny(const cv::Mat& inputIm, cv::Mat& outputIm) const{
    cv::Canny(inputIm, outputIm, mv_cannyLowerThresh, mv_cannyUpperThresh, mv_cannyAperture);
    return true;
}
//---------------------------------------------------
// get lower threshold for canny
//---------------------------------------------------
double swc_kernelProcess::mf_getCannyLowerThresh() const{
    return mv_cannyLowerThresh;
}
//---------------------------------------------------
// set lower threshold for canny
//---------------------------------------------------
bool swc_kernelProcess::mf_setCannyLowerThresh(const double lowerThresh){
    mv_cannyLowerThresh = lowerThresh;
    return true;
}

//---------------------------------------------------
// get upper threshold for canny
//---------------------------------------------------
double swc_kernelProcess::mf_getCannyUpperThresh() const{
    return mv_cannyUpperThresh;
}

//---------------------------------------------------
// set upper threshold for canny
//---------------------------------------------------
bool swc_kernelProcess::mf_setCannyUpperThresh(const double upperThresh){
    mv_cannyUpperThresh = upperThresh;
    return true;
}

