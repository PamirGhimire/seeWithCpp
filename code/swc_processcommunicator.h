#ifndef SWC_PROCESSCOMMUNICATOR_H
#define SWC_PROCESSCOMMUNICATOR_H

#include<string>
#include<opencv2/core/core.hpp>

// class for communicating parameters between the gui = receiver of parameters
//                            and the process manager = executer of processes

class swc_processcommunicator
{
public:
    swc_processcommunicator();

    // some reference:
    //----------------------------------------------------
    // One-view process code words:
    //----------------------------------------------------
    // Identity Transformation           //oneviewPcode -100
    //("Add salt and pepper noise");     //oneviewPcode 0
    //("Show Logo at top left corner");  //oneviewPcode 1
    //("Convert to new colorspace");     //oneviewPcode 2
    //("Equalize histogram");            //oneviewPcode 3
    //("Dilate");        //oneviewPcode 4
    //("Erode");         //oneviewPcode 5
    //("Open");          //oneviewPcode 6
    //("Close");         //oneviewPcode 7
    //("Blur");          //oneviewPcode 8
    //("Apply Sobel");   //oneviewPcode 9
    //("Apply Laplacian");           //oneviewPcode 10
    //("Apply custom kernel");       //oneviewPcode 11
    //("Detect Edges using Canny");  //oneviewPcode 12
    //("Extract lines and Circles using Hough");     //oneviewPcode 13
    //("Find contours of connected components");     //oneviewPcode 14

    // for adding salt and pepper noise
    double nPercentPixelsToCorrupt;

    // for adding logo
    std::string logoFilename;

    // for defining a structuring element
    // dilation
    cv::Mat sel_dilation;

    // erosion
    cv::Mat sel_erosion;

};

#endif // SWC_PROCESSCOMMUNICATOR_H
