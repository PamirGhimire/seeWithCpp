#include "swc_controller.h"

//---------------------------------------------------------------------
// Controller : default constructor
//---------------------------------------------------------------------
swc_controller::swc_controller()
{
    // Initialize controller member variables

    // I/O images for one-view processes
    mv_inputim = cv::Mat(640, 480, CV_8UC1, cv::Scalar(200));
    mv_inputim.copyTo(mv_outputim);

    // I/O images for multi-view processes
    mv_im1 = cv::Mat(500, 500, CV_8UC1, cv::Scalar(0));
    mv_im2 = cv::Mat(500, 500, CV_8UC1, cv::Scalar(0));

    // Initialize pointers to different models:
    //---------------------------------------------------------------------
    // Salt and Pepper noise model
    mod_addNoiseSaltAndPepper = new swc_addNoiseSaltAndPepper();
    //---------------------------------------------------------------------
    // Add Logo Model
    mod_addLogo = new swc_addLogo();
    //---------------------------------------------------------------------
    // Compute Histogram Model
    mod_computeHistogram = new swc_computeHistogram();
    //---------------------------------------------------------------------
    // Morphology Model
    mod_morphology = new swc_morphology();
    //---------------------------------------------------------------------
    // Kernel Model
    mod_kernel =  new swc_kernelProcess();
    //---------------------------------------------------------------------
    // Structure Model (hough lines, connected components)
    mod_structure = new swc_structure();
    //---------------------------------------------------------------------
    // Interest Points model (harris, sift, surf)
    mod_interestPoints = new swc_interestPoints();
    //---------------------------------------------------------------------
    // Image matching model
    mod_matchImages = new swc_matchImages();
    //---------------------------------------------------------------------


}

//---------------------------------------------------------------------
// Controller : destructor
//---------------------------------------------------------------------
swc_controller::~swc_controller()
{
    // Release pointers to different modules
    delete mod_addNoiseSaltAndPepper;

}

//---------------------------------------------------------------------
// Controller : set input image
//---------------------------------------------------------------------
bool swc_controller::mf_setInputImage(std::string filename)
{

    cv::Mat inputim = cv::imread(filename, 0);

    // reallocate mv_inputim so that it is of same size and type as the read image
    mv_inputim.create(inputim.size(), inputim.type());
    inputim.copyTo(mv_inputim);

    // return false if the image was not loaded
    if (!mv_inputim.data){
        qDebug() << "failed loading image";
        return false;
    }else{
        qDebug() << "Loaded selected image";
        return true;
    }
}
//---------------------------------------------------------------------
// Set im1 (for matching between im1 and im2)
//---------------------------------------------------------------------
bool swc_controller::mf_setIm1(std::string filename){

    cv::Mat im1 = cv::imread(filename, 0);

    // reallocate mv_im1 so that it is of same size and type as the read image
    mv_im1.create(im1.size(), im1.type());
    im1.copyTo(mv_im1);

    // return false if the image was not loaded
    if (!mv_im1.data){
        qDebug() << "failed loading image";
        return false;
    }else{
        qDebug() << "Loaded selected image";
        return true;
    }
    return true;
}

//---------------------------------------------------------------------
// Set im2 (for matching between im1 and im2)
//---------------------------------------------------------------------
bool swc_controller::mf_setIm2(std::string filename){
    cv::Mat im2 = cv::imread(filename, 0);

    // reallocate mv_im1 so that it is of same size and type as the read image
    mv_im2.create(im2.size(), im2.type());
    im2.copyTo(mv_im2);

    // return false if the image was not loaded
    if (!mv_im2.data){
        qDebug() << "failed loading image";
        return false;
    }else{
        qDebug() << "Loaded selected image";
        return true;
    }

    return true;
}

//---------------------------------------------------------------------
// Controller : get input image
//---------------------------------------------------------------------
cv::Mat swc_controller::mf_getInputImage() const
{
    return mv_inputim;
}

//---------------------------------------------------------------------
// Controller : get output image
//---------------------------------------------------------------------
cv::Mat swc_controller::mf_getOutputImage() const
{
    return mv_outputim;
}


//---------------------------------------------------------------------
// Module : Add salt and pepper noise : process image
//---------------------------------------------------------------------
void swc_controller::addNoiseSaltAndPepper_process()
{
    mod_addNoiseSaltAndPepper->mf_addSaltAndPepper(mv_inputim, mv_outputim);
}

//---------------------------------------------------------------------
// Module : Add salt and pepper noise : get how many pixels the module is corrupting
//---------------------------------------------------------------------
int swc_controller::addNoiseSaltAndPepper_get_NcorruptedPixels()
{
    return mod_addNoiseSaltAndPepper->mf_getNPixels2Corrput();
}

//---------------------------------------------------------------------
// Module : Add salt and pepper noise : set how many pixels the module is to corrupt
//---------------------------------------------------------------------
void swc_controller::addNoiseSaltAndPepper_set_NcorruptedPixels(int n)
{
    mod_addNoiseSaltAndPepper->mf_setNPixels2Corrupt(n);
}

//---------------------------------------------------------------------
// Module : Add Logo
//---------------------------------------------------------------------
// get logo
cv::Mat swc_controller::addLogo_getLogo() const{
    return mod_addLogo->mf_getLogo();
}
//---------------------------------------------------------------------
// Module : Add Logo
//---------------------------------------------------------------------
// set logo image
bool swc_controller::addLogo_setLogo(std::string logoFilename){
    return mod_addLogo->mf_setLogo(logoFilename);
}
//---------------------------------------------------------------------
// Module : Add Logo
//---------------------------------------------------------------------
// add logo to a given image
void swc_controller::addLogo_process_addLogoTo(){
    mod_addLogo->mf_addLogoTo(mv_inputim, mv_outputim);
}
//---------------------------------------------------------------------
// Module : Add Logo
//---------------------------------------------------------------------
// get logo width
int swc_controller::addLogo_getLogoWidth() const{
    return mod_addLogo->mf_getLogoWidth();
}

//---------------------------------------------------------------------
// Module : Add Logo
//---------------------------------------------------------------------
// set logo width
void swc_controller::addLogo_setLogoWidth(int logoWidth){
    mod_addLogo->mf_setLogoWidth(logoWidth);
}

//---------------------------------------------------------------------
// Module : Add Logo
//---------------------------------------------------------------------
// get logo height
int swc_controller::addLogo_getLogoHeight() const{
    return mod_addLogo->mf_getLogoHeight();
}
//---------------------------------------------------------------------
// Module : Add Logo
//---------------------------------------------------------------------
// set logo height
void swc_controller::addLogo_setLogoHeight(int logoHeight) const{
    mod_addLogo->mf_setLogoHeight(logoHeight);
}

//---------------------------------------------------------------------
// Module : Compute Histogram
//---------------------------------------------------------------------
// Compute histogram normalized image
void swc_controller::computeHistogram_process_computeHistogramNormalizedImage(){
    mod_computeHistogram->mf_computeHistogramNormalizedImage(mv_inputim, mv_outputim);
}
//---------------------------------------------------------------------
// Module : Compute Histogram
//---------------------------------------------------------------------
// Returns histogram array of cv::Mat image
cv::Mat swc_controller::computeHistogram_process_computeHistogram(){
    return mod_computeHistogram->mf_computeHistogram(mv_inputim);
}

//---------------------------------------------------------------------
// Module : Compute Histogram
//---------------------------------------------------------------------
// compute image bar graph of 1D histogram of input image
cv::Mat swc_controller::computeHistogram_computeHistogramInput(){
    cv::Mat histImage(300, 200, CV_8UC1);
    mod_computeHistogram->mf_computeHistogramImage(mv_inputim, histImage);
    return histImage;
}

// histogram of output
cv::Mat swc_controller::computeHistogram_computeHistogramOutput(){
    cv::Mat histImage(300, 200, CV_8UC1);
    mod_computeHistogram->mf_computeHistogramImage(mv_outputim, histImage);
    return histImage;
}
//---------------------------------------------------------------------
// Module : Compute Histogram
//---------------------------------------------------------------------
// get number of histogram bins
int swc_controller::computeHistogram_getnHistBins(){
    return mod_computeHistogram->mf_getnHistBins();
}

//---------------------------------------------------------------------
// Module : Compute Histogram
//---------------------------------------------------------------------
// set number of histogram bins
void swc_controller::computeHistogram_setnHistBins(int nHistBins){
    mod_computeHistogram->mf_setnHistBins(nHistBins);
}
//---------------------------------------------------------------------
// Module : Compute Histogram
//---------------------------------------------------------------------
// get current intensity range for which hist is computed
float* swc_controller::computeHistogram_getIntensityRange(){
    return mod_computeHistogram->mf_getIntensityRange();
}
//---------------------------------------------------------------------
// Module : Compute Histogram
//---------------------------------------------------------------------
// set intensity range
void swc_controller::computeHistogram_setIntensityRange(float minIntensity, float maxIntensity){
    mod_computeHistogram->mf_setIntensityRange(minIntensity, maxIntensity);
}

//------------------------------------------------------------
// Module : Morphology
//------------------------------------------------------------
// get mv_bwThreshold
int swc_controller::morphology_getbwThreshold() const{
    return mod_morphology->mf_getbwThreshold();
}

//------------------------------------------------------------
// Module : Morphology
//------------------------------------------------------------
// set mv_bwThreshold
bool swc_controller::morphology_setbwThreshold(int bwThreshold){
    mod_morphology->mf_setbwThreshold(bwThreshold);
    return true;
}

//------------------------------------------------------------
// Module : Morphology
//------------------------------------------------------------
// get structuring element
cv::Mat swc_controller::morphology_getStructuringElement() const{
    return mod_morphology->mf_getStructuringElement();
}

//------------------------------------------------------------
// Module : Morphology
//------------------------------------------------------------
// set structuring element
bool swc_controller::morphology_setStructuringElement(const cv::Mat &structuringElement){
    mod_morphology->mf_setStructuringElement(structuringElement);
    return true;
}

//------------------------------------------------------------
// Module : Morphology
//------------------------------------------------------------
// get binarized image
cv::Mat swc_controller::morphology_getBinarizedInputIm() const{
    return mod_morphology->mf_getBinarizedInputIm();
}

//------------------------------------------------------------
// Module : Morphology
//------------------------------------------------------------
// get dilated input image
bool swc_controller::morphology_dilate(){
    mod_morphology->mf_dilate(mv_inputim, mv_outputim);
    return true;
}

//------------------------------------------------------------
// Module : Morphology
//------------------------------------------------------------
// get eroded input image
bool swc_controller::morphology_erode(){
    mod_morphology->mf_erode(mv_inputim, mv_outputim);
    return true;
}

//------------------------------------------------------------
// Module : Morphology
//------------------------------------------------------------
// get opened input image
bool swc_controller::morphology_open() {
    mod_morphology->mf_open(mv_inputim, mv_outputim);
    return true;
}

//------------------------------------------------------------
// Module : Morphology
//------------------------------------------------------------
// get closed input image
bool swc_controller::morphology_close(){
    mod_morphology->mf_close(mv_inputim, mv_outputim);
    return true;
}

//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// get lower threshold for canny
double swc_controller::kernel_getCannyLowerThresh() const{
    return mod_kernel->mf_getCannyLowerThresh();
}
//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// set lower threshold for canny
bool swc_controller::kernel_setCannyLowerThresh(const double lowerThresh){
    mod_kernel->mf_setCannyLowerThresh(lowerThresh);
    return true;
}
//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// get upper threshold for canny
double swc_controller::kernel_getCannyUpperThresh() const{
    return mod_kernel->mf_getCannyUpperThresh();
}

//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// set upper threshold for canny
bool swc_controller::kernel_setCannyUpperThresh(const double upperThresh){
    mod_kernel->mf_setCannyUpperThresh(upperThresh);
    return true;
}

//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// get the current size of Gaussian kernel
int swc_controller::kernel_getGaussKernelSize() const{
    return mod_kernel->mf_getGaussKernelSize();
}

//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// set the size of Gaussian kernel
bool swc_controller::kernel_setGaussKernelSize(int gsize){
    mod_kernel->mf_setGaussKernelSize(gsize);
    return true;
}
//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// get the variance of Gaussian Kernel
int swc_controller::kernel_getGaussSigma() const{
    return mod_kernel->mf_getGaussSigma();
}

//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// set the variance of Gaussian Kernel
bool swc_controller::kernel_setGaussSigma(int gSigma){
    mod_kernel->mf_setGaussSigma(gSigma);
    return true;
}

//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// returns current kernel
cv::Mat swc_controller::kernel_getKernel(){
    return mod_kernel->mf_getKernel();
}

//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// set kernel for filtering
bool swc_controller::kernel_setKernel(const cv::Mat& kernel){
    mod_kernel->mf_setKernel(kernel);
    return true;
}

//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// blur image using gaussian smoothing
bool swc_controller::kernel_gaussianBlur() {
    mod_kernel->mf_gaussianBlur(mv_inputim, mv_outputim);
    return true;
}

//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// filter image using sobel operator
bool swc_controller::kernel_filterSobel(){
    mod_kernel->mf_filterSobel(mv_inputim, mv_outputim);
    return true;
}
//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// apply laplacian operator to the image
bool swc_controller::kernel_filterLaplacian(){
    mod_kernel->mf_filterLaplacian(mv_inputim, mv_outputim);
    return true;
}

//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// sharpen image using laplacian
bool swc_controller::kernel_filterLaplacianSharpen(){
    mod_kernel->mf_filterLaplacianSharpen(mv_inputim, mv_outputim);
    return true;
}

//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// apply a custom kernel
bool swc_controller::kernel_filterCustomKernel(){
    mod_kernel->mf_filterCustomKernel(mv_inputim, mv_outputim);
    return true;
}

//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// detect edges using canny
bool swc_controller::kernel_filterCanny(){
    mod_kernel->mf_filterCanny(mv_inputim, mv_outputim);
    return true;
}
//------------------------------------------------------------
// Kernel model
//------------------------------------------------------------
// apply median filter
bool swc_controller::kernel_filterMedian(){
    mod_kernel->mf_filterMedian(mv_inputim, mv_outputim);
    return true;
}
//------------------------------------------------------------
// Structure model
//------------------------------------------------------------
// find lines, the result of probabilistic hough transform
bool swc_controller::structure_findLines(){
    mod_structure->mf_findLines(mv_inputim);
    return true;
}
//------------------------------------------------------------
// Structure model
//------------------------------------------------------------
// get circles using probabilistic hough transform
bool swc_controller::structure_findCircles(){
    mod_structure->mf_findCircles(mv_inputim);
    return true;
}

//------------------------------------------------------------
// Structure model
//------------------------------------------------------------
// get contours of connected components
bool swc_controller::structure_findContours(){
    mod_structure->mf_findContours(mv_inputim);
    return true;
}
//------------------------------------------------------------
// Structure model
//------------------------------------------------------------
// draw estimated lines on the supplied image
bool swc_controller::structure_drawHoughLinesP(){
    mv_inputim.copyTo(mv_outputim, cv::Mat());
    mod_structure->mf_drawHoughLinesP(mv_outputim);
    return true;
}
//------------------------------------------------------------
// Structure model
//------------------------------------------------------------
// draw estimated circles on the supplied image
bool swc_controller::structure_drawHoughCircles(){
    mv_inputim.copyTo(mv_outputim, cv::Mat());
    mod_structure->mf_drawHoughCircles(mv_outputim);
    return true;
}

//------------------------------------------------------------
// Structure model
//------------------------------------------------------------
// draw estimated contours on the supplied image
bool swc_controller::structure_drawContours(){
    mv_inputim.copyTo(mv_outputim, cv::Mat());
    mod_structure->mf_drawContours(mv_outputim);
    return true;
}

//------------------------------------------------------------
// Structure model
//------------------------------------------------------------
// draw bounding box
bool swc_controller::structure_drawBoundingBoxUsingContours(){
    mv_inputim.copyTo(mv_outputim, cv::Mat());
    mod_structure->mf_drawBoundingBoxUsingContours(mv_outputim);
    return true;
}
//------------------------------------------------------------
// Structure model
//------------------------------------------------------------
// draw minimum enclosing circle
bool swc_controller::structure_drawMinEnclosingCirclesUsingContours(){
    mv_inputim.copyTo(mv_outputim);
    mod_structure->mf_drawMinEnclosingCirclesUsingContours(mv_outputim);
    return true;
}

//------------------------------------------------------------
// Interest Points Model
//------------------------------------------------------------
// detect corner points in input, plot them in output
void swc_controller::interestPoints_drawHarrisCornersOnImage(){
    mv_inputim.copyTo(mv_outputim);
    mod_interestPoints->mf_drawHarrisCornersOnImage(mv_inputim, mv_outputim);
}
//------------------------------------------------------------
// Interest Points Model
//------------------------------------------------------------
// draw detected keypoints, keyPointCode = 1 (fast), 2(surf), 3(sift)
bool swc_controller::interestPoints_drawFastKeypoints(){
    mv_inputim.copyTo(mv_outputim);
    mod_interestPoints->mf_drawKeypointsOnImage(mv_inputim, mv_outputim, 1); //1 fast
    return true;
}

bool swc_controller::interestPoints_drawSurftKeypoints(){
    mv_inputim.copyTo(mv_outputim);
    mod_interestPoints->mf_drawKeypointsOnImage(mv_inputim, mv_outputim, 2); //2 surf
    return true;
}

bool swc_controller::interestPoints_drawSiftKeypoints(){
    mv_inputim.copyTo(mv_outputim);
    mod_interestPoints->mf_drawKeypointsOnImage(mv_inputim, mv_outputim, 3); //3 sift
    return true;
}
//------------------------------------------------------------
// Interest Points Model
//------------------------------------------------------------
// detect fast keypoints
bool swc_controller::interestPoints_detectFastKeypoints(){
    mod_interestPoints->mf_detectFastKeypoints(mv_inputim);
    return true;
}

//------------------------------------------------------------
// Interest Points Model
//------------------------------------------------------------
// detect surf keypoints
bool swc_controller::interestPoints_detectSurfKeypoints(){
    mod_interestPoints->mf_detectSurfKeypoints(mv_inputim);
    return true;
}
//------------------------------------------------------------
// Interest Points Model
//------------------------------------------------------------
// detect sift keypoints
bool swc_controller::interestPoints_detectSiftKeypoints(){
    mod_interestPoints->mf_detectSiftKeypoints(mv_inputim);
    return true;
}

//------------------------------------------------------------
// Model : match images
//------------------------------------------------------------
// match im1 and im2, descriptor = 1(sift) or 2(surf)
bool swc_controller::matchImages_drawMatchesBwIm1and2(int descriptor){
    mod_matchImages->mf_drawMatchesBwIm1and2(mv_im1, mv_im2, mv_matchesIm1and2, descriptor);

    cv::namedWindow("matches");
    cv::imshow("matches", mv_matchesIm1and2);

    return true;
}
