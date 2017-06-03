#ifndef SWC_PROCESSMANAGER_H
#define SWC_PROCESSMANAGER_H
#include<string>
#include<swc_controller.h>
#include<swc_processcommunicator.h>

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
//("Lines using P.Hough");     //oneviewPcode 13
//("Circles using P.Hough");   //oneviewPcode 14
//("Contours of connected components");     //oneviewPcode 15

//----------------------------------------------------
class swc_processManager
{

private:
    // one-view process codes
    enum{addSaltAndPepper = 0,
         showLogo = 1,
         convertToNewCspace = 2,
         equalizeHistogram = 3,
         dilate = 4,
         erode = 5,
         open_morph = 6,
         close_morph = 7,
         blur = 8,
         sobel = 9,
         laplacian = 10,
         customKernel = 11,
         cannyedge = 12,
         houghlines = 13,
         houghcircles = 14,
         conCompContours = 15,
         conCompMinEnCircle = 16,
         conCompBoundingBoxes = 17,
         harrisCorners = 18,
         fastKeypoints = 19,
         surfKeypoints = 20,
         siftKeypoints = 21,
         showHistogram = 22,
         showHistogramOut = 23,
         identity = -100};

public:
    swc_processManager();

    // return name of the process corresponding to the one-view process code word
    std::string mf_getProcessName(int processcode);

    // execute the process described by the gui, using the passed parameters
    bool mf_executeProcess(int processcode, swc_controller* controller, swc_processcommunicator* processComm);

};

#endif // SWC_PROCESSMANAGER_H
