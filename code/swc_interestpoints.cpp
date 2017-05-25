#include "swc_interestpoints.h"

swc_interestPoints::swc_interestPoints()
{

    // harris neighbourhood size
    mv_harrisNeighbourhoodSize = 3;

    // harris aperture size
    mv_harrisApertureSize = 3;

    // harris parameter
    mv_harrisParameter = 0.2;

    // harris corner map threshold
    mv_harrisCornerThreshold = 0.001;

    // picking threshold for corner strength map
    mv_qualityLevel = 0.85;

    // FAST
    mv_fastDetector->create(40);

}


//-----------------------------------------------------
// detect fast keypoints
//-----------------------------------------------------
bool swc_interestPoints::mf_detectFastKeypoints(const cv::Mat& inputim){

    // detect fast keypoints on the input image
    mv_fastDetector->detect(inputim, mv_fastKeypoints);
    return true;
}

//-----------------------------------------------------
// detect fast keypoints on input, draw them on input, return in output
//-----------------------------------------------------
// draw detected fast keypoints
bool swc_interestPoints::mf_drawFastKeypointsOnImage(const cv::Mat& inputim, cv::Mat& outputim){

    // detect keypoints on inputim
    mf_detectFastKeypoints(inputim);

    cv::drawKeypoints(inputim,
                      mv_fastKeypoints,
                      outputim,
                      cv::Scalar(255, 255, 255),
                      cv::DrawMatchesFlags::DRAW_OVER_OUTIMG);
    return true;
}


//-----------------------------------------------------
// Draw circles at feature point locations on an image
//-----------------------------------------------------

void swc_interestPoints::mf_drawHarrisCornersOnImage(const cv::Mat &inputim, cv::Mat& outputim){

    // compute harris values
    mf_computeHarrisValues(inputim);

    // detect harris corners
    mf_computeCornerPoints();

    // draw harris corners
    cv::Scalar color= cv::Scalar(255,255,255);
    int radius = 3;
    int thickness = 2;

    // copy the input image to outputimage location
    inputim.copyTo(outputim);

    std::vector<cv::Point>::const_iterator it=
            mv_harrisCornerPoints.begin();
    // for all corners
    while (it!=mv_harrisCornerPoints.end()) {
        // draw a circle at each corner location
        cv::circle(outputim,*it,radius,color,thickness);
        ++it;
    }
}

//-----------------------------------------------------
// Compute harris values at all pixel locations
//-----------------------------------------------------
bool swc_interestPoints::mf_computeHarrisValues(const cv::Mat& inputim) {

    // dilation replaces map strength at each location with maximum
    // value in a neighbourhood centered at the location
    // compare returns true for a location only if it is a local
    // maximum

    // harris values at all locations
    cv::cornerHarris(inputim,
                     mv_harrisCornerStrengthMap,
                     mv_harrisNeighbourhoodSize, // neighborhood size
                     mv_harrisApertureSize, // aperture size
                     mv_harrisParameter); // Harris parameter

    // get global maximum of the corner strength map
    double minStrength; // not used
    cv::minMaxLoc(mv_harrisCornerStrengthMap,
                  &minStrength,&mv_maxStrength);

    // local maxima detection
    cv::Mat dilated; // temporary image
    cv::dilate(mv_harrisCornerStrengthMap,dilated,cv::Mat());

    // result in mv_localMax
    cv::compare(mv_harrisCornerStrengthMap,dilated,
                mv_localMax,cv::CMP_EQ);

    return true;
}

//-----------------------------------------------------
// Get corner map from the computed Harris values
//-----------------------------------------------------
bool swc_interestPoints::mf_computeCornerMap() {

    // thresholding the corner strength
    mv_harrisCornerThreshold = mv_qualityLevel*mv_maxStrength;

    cv::threshold(mv_harrisCornerStrengthMap,
                  mv_thCornerStrengthMap,
                  mv_harrisCornerThreshold,255,cv::THRESH_BINARY);

    // convert thresholded to 8-bit image -> cornerMap
    mv_thCornerStrengthMap.convertTo(mv_cornerMap,CV_8U);

    // non-maxima suppression (mv_localMax = 1 for local maxima)
    cv::bitwise_and(mv_cornerMap, mv_localMax, mv_cornerMap);

    return true;
}

//-----------------------------------------------------
// Get feature points from computed corner map
//-----------------------------------------------------
void swc_interestPoints::mf_computeCornerPoints() {

    // Get the corner map
    mf_computeCornerMap();

    // Iterate over the pixels to obtain all features
    for( int y = 0; y < mv_cornerMap.rows; y++ ) {
        const uchar* rowPtr = mv_cornerMap.ptr<uchar>(y);
        for( int x = 0; x < mv_cornerMap.cols; x++ ) {
            // if it is a feature point
            if (rowPtr[x]) {
                mv_harrisCornerPoints.push_back(cv::Point(x,y));
            }
        }
    }
}

//-----------------------------------------------------
// get harris neighbourhood size
//-----------------------------------------------------
int swc_interestPoints::mf_getHarrisNeighbourhoodSize() const{
    return mv_harrisNeighbourhoodSize;
}

//-----------------------------------------------------
// set harris neighbourhood size
//-----------------------------------------------------
bool swc_interestPoints::mf_setHarrisNeighbourhoodSize(int nsize){
    mv_harrisNeighbourhoodSize = nsize;
    return true;
}

//-----------------------------------------------------
// get harris aperture size
//-----------------------------------------------------
int swc_interestPoints::mf_getHarrisApertureSize() const{
    return mv_harrisApertureSize;
}

//-----------------------------------------------------
// set harris aperture size
//-----------------------------------------------------
bool swc_interestPoints::mf_serHarrisApertureSize(int apertureSize){
    mv_harrisApertureSize = apertureSize;
    return true;
}
//-----------------------------------------------------
// get harris parameter
//-----------------------------------------------------
float swc_interestPoints::mf_getHarrisParameter() const{
    return mv_harrisParameter;
}
//-----------------------------------------------------
// set harris parameter
//-----------------------------------------------------
bool swc_interestPoints::mf_setHarrisParameter(float hparameter){
    mv_harrisParameter = hparameter;
    return true;
}

//-----------------------------------------------------
// get threshold for harris corner map
//-----------------------------------------------------
double swc_interestPoints::mf_getHarrisCornerThreshold() const{
    return mv_harrisCornerThreshold;
}

//-----------------------------------------------------
// set threshold for harris corner map
//-----------------------------------------------------
bool swc_interestPoints::mf_setHarrisCornerThreshold(double hcornerThresh){
    mv_harrisCornerThreshold = hcornerThresh;
    return true;
}
