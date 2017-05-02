#ifndef SWC_PROCESSMANAGER_H
#define SWC_PROCESSMANAGER_H
#include<string>
#include<swc_controller.h>

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


class swc_processManager
{

private:
    // ove-view process codes
    enum{addSaltAndPepper,
        showLogo,
        convertToNewCspace,
        equalizeHistogram,
        identity = -100};

public:
    swc_processManager();

    // return name of the process corresponding to the one-view process code word
    std::string mf_getProcessName(int processcode);

    // execute the process described by the gui
    bool mf_executeProcess(int processcode, swc_controller* controller);

};

#endif // SWC_PROCESSMANAGER_H