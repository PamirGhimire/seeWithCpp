#include "swc_structure.h"

// default constructor
swc_structure::swc_structure(): mv_deltaRho(1), mv_deltaTheta(PI/180),
    mv_minVoteForLine(10), mv_minLengthForLine(0.), mv_maxGap(0.)
{

}

//-------------------------------------------------------
// get min vote for line
//-------------------------------------------------------
int swc_structure::mf_getMinVoteForLine() const{
    return mv_minVoteForLine;
}

//-------------------------------------------------------
// set min vote for line
//-------------------------------------------------------
bool swc_structure::mf_setMinVoteForLine(const int minVote){
    mv_minVoteForLine = minVote;
    return true;
}

//-------------------------------------------------------
// get min length for line
//-------------------------------------------------------
double swc_structure::mf_getMinLineLength() const{
    return mv_minLengthForLine;
}

//-------------------------------------------------------
// set min length for line
//-------------------------------------------------------
bool swc_structure::mf_setMinLineLength(const double lineLength){
    mv_minLengthForLine = lineLength;
    return true;
}

//-------------------------------------------------------
// get linesVec, the result of probabilistic hough transform
//-------------------------------------------------------
bool swc_structure::mf_findLines(const cv::Mat& inputim) {

    // clear vector containing probabilistic hough lines
    mv_linesvec.clear();

    // binarize the input image
    cv::Mat binary_inputim;
    cv::threshold(inputim, binary_inputim, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

    // calculate hough lines
    cv::HoughLinesP(binary_inputim, mv_linesvec, mv_deltaRho, mv_deltaTheta, mv_minVoteForLine, mv_minLengthForLine, mv_maxGap);

    // return the calculated lines
    return true;
}

//-------------------------------------------------------
// set accumulator resolution deltaRho
//-------------------------------------------------------
bool swc_structure::mf_setDeltaRho(const double deltaRho){
    mv_deltaRho = deltaRho;
    return true;
}

//-------------------------------------------------------
//get delta Rho
//-------------------------------------------------------
double swc_structure::mf_getDeltaRho() const{
    return mv_deltaRho;
}

//-------------------------------------------------------
// set delta Theta
//-------------------------------------------------------
bool swc_structure::mf_setDeltaTheta(const double deltaTheta){
    mv_deltaTheta = deltaTheta;
    return true;
}

//-------------------------------------------------------
// get delta Theta
//-------------------------------------------------------
double swc_structure::mf_getDeltaTheta() const{
    return mv_deltaTheta;
}

//-------------------------------------------------------
// draw estimated lines on the supplied image
//-------------------------------------------------------
bool swc_structure::mf_drawHoughLinesP(cv::Mat& outputim, cv::Scalar color){

    // Draw the lines
    std::vector<cv::Vec4i>::const_iterator it2=
            mv_linesvec.begin();

    while (it2!=mv_linesvec.end()) {
        cv::Point pt1((*it2)[0],(*it2)[1]);
        cv::Point pt2((*it2)[2],(*it2)[3]);
        cv::line(outputim, pt1, pt2, color);
        ++it2;
    }

    return true;
}
//-------------------------------------------------------
// get circles using probabilistic hough transform
//-------------------------------------------------------
bool swc_structure::mf_findCircles(const cv::Mat& inputim){
    cv::Mat blurredInputim;
    cv::GaussianBlur(inputim, blurredInputim, cv::Size(5, 5), 1.5);

    cv::HoughCircles(blurredInputim, mv_circlesVec, CV_HOUGH_GRADIENT,
                     2,   // accumulator resolution (size of the image / 2)
                     50,  // minimum distance between two circles
                     200, // Canny high threshold
                     100, // minimum number of votes
                     25, 100); // min and max radius

    return true;
}
//-------------------------------------------------------
// draw estimated circles on the supplied image
//-------------------------------------------------------
bool swc_structure::mf_drawHoughCircles(cv::Mat& inputim, cv::Scalar color) {


    std::vector<cv::Vec3f>::const_iterator itc= mv_circlesVec.begin();

    while (itc!=mv_circlesVec.end()) {
        cv::circle(inputim,
                   cv::Point((*itc)[0], (*itc)[1]), // circle centre
                (*itc)[2],                          // circle radius
                color,                    // color
                2);                                 // thickness
        ++itc;
    }

    return true;
}

//-------------------------------------------------------
// get contours of connected components
//-------------------------------------------------------
bool swc_structure::mf_findContours(const cv::Mat inputim){

    cv::Mat binary_inputim;
    cv::threshold(inputim, binary_inputim, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

    cv::findContours(binary_inputim,
                     mv_contoursvec, // a vector of contours
                     CV_RETR_EXTERNAL, // retrieve the external contours
                     CV_CHAIN_APPROX_NONE); // all pixels of each contours

    return true;
}

//-------------------------------------------------------
// draw estimated contours on the supplied image
//-------------------------------------------------------
bool swc_structure::mf_drawContours(cv::Mat& outputim){

    // Draw black contours on a white image
    outputim = cv::Mat(outputim.size(), CV_8U,cv::Scalar(255));


    cv::drawContours(outputim,
                     mv_contoursvec, // vector containing all contours
                     -1, // draw all contours
                     cv::Scalar(0), // in black
                     2); // with a thickness of 2
    return true;
}

//-------------------------------------------------------
// get lines vec
//-------------------------------------------------------
std::vector<cv::Vec4i> swc_structure::mf_getLinesVec(){
    return mv_linesvec;
}

//-------------------------------------------------------
// get circlesvec
//-------------------------------------------------------
std::vector<cv::Vec3f> swc_structure::mf_getCirclesVec(){
    return mv_circlesVec;
}

//-------------------------------------------------------
// get contoursvec
//-------------------------------------------------------
std::vector<std::vector<cv::Point>> swc_structure::mf_getContoursVec(){
    return mv_contoursvec;
}

//-------------------------------------------------------
// draw bounding box
//-------------------------------------------------------
bool swc_structure::mf_drawBoundingBoxUsingContours(cv::Mat& outputim){

    mf_drawContours(outputim);

    std::vector<std::vector<cv::Point>>::const_iterator itc = mv_contoursvec.begin();

    // draw bounding boxes
    while (itc != mv_contoursvec.end()){
        cv::Rect ri = cv::boundingRect(cv::Mat((*itc)));
        cv::rectangle(outputim,ri,cv::Scalar(0),2);
        itc++;
    }

    return true;
}

//-------------------------------------------------------
// draw minimum enclosing circle
//-------------------------------------------------------
bool swc_structure::mf_drawMinEnclosingCirclesUsingContours(cv::Mat& outputim){

    mf_drawContours(outputim);

    // draw minimum enclosing circle
    std::vector<std::vector<cv::Point>>::const_iterator itc = mv_contoursvec.begin();

    // centres and radii of circles
    float radius;
    cv::Point2f center;

    while (itc != mv_contoursvec.end()){
        cv::minEnclosingCircle( cv::Mat((*itc)), center, radius );

        cv::circle(outputim,cv::Point(center),
                   static_cast<int>(radius),cv::Scalar(0),2);

        itc++;
    }

    return true;
}
