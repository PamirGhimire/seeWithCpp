#include "swc_processcommunicator.h"

swc_processcommunicator::swc_processcommunicator()
{
    // some good initializations

    // for canny edge detector
    cannyLowerThresh = 215;
    cannyUpperThresh = 350;

    // custom kernel (3x3, identity transform)
    customKernel = cv::Mat(3, 3, CV_32F, cv::Scalar(0));
    customKernel.at<float>(1, 1) = 1;


}
