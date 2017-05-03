#include "swc_processmanager.h"

swc_processManager::swc_processManager()
{

}


//-----------------------------------------------
// Return process name when queried with one-view process code word
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
std::__cxx11::string swc_processManager::mf_getProcessName(int processcode)
{
    switch (processcode){
    case 0:
        return "Add salt and pepper";
        break;

    case 1:
        return "Show Logo";
        break;
    case 2:
        return "Convert Colorspace";
        break;
    case 3:
        return "Equalize histogram";
        break;
    default:
        return "Not an available Process";
    }
}


//-----------------------------------------------
// Execute process described by the gui
//----------------------------------------------------
bool swc_processManager::mf_executeProcess(int processcode, swc_controller *controller, swc_processcommunicator *processComm)
{
    switch (processcode){
        //--------------------------------
        // code 0: add salt and pepper
        //--------------------------------
    case 0:
    {
        int npixels = controller->mf_getInputImage().rows * controller->mf_getInputImage().cols;
        controller->addNoiseSaltAndPepper_set_NcorruptedPixels(0.05*npixels);
        controller->addNoiseSaltAndPepper_process();
        return true;
    }

        //--------------------------------
        // code 1: add logo
        //--------------------------------
    case 1:
        // add logo
        controller->addLogo_process_addLogoTo();
        return true;

        // code 2: convert colorspace
    case 2:

        return true;
        // code 3: equalize histogram
    case 3:

        return true;
    default:
        return false;
    }
}
