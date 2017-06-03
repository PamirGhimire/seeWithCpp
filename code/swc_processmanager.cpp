#include "swc_processmanager.h"

swc_processManager::swc_processManager()
{

}


//-----------------------------------------------
// Return process name when queried with one-view process code word

// Remaining:
//("Detect Edges using Canny");  //oneviewPcode 12
//("Extract lines and Circles using Hough");     //oneviewPcode 13
//("Find contours of connected components");     //oneviewPcode 14

// one-view process codes
//enum{addSaltAndPepper = 0,
//     showLogo = 1,
//     convertToNewCspace = 2,
//     equalizeHistogram = 3,
//     dilate = 4,
//     erode = 5,
//     open_morph = 6,
//     close_morph = 7,
//     blur = 8,
//     sobel = 9,
//     laplacian = 10,
//     customKernel = 11,
//     showHistogram = 15,
//     identity = -100};

std::__cxx11::string swc_processManager::mf_getProcessName(int processcode)
{
    switch (processcode){
    case addSaltAndPepper:
        return "Add salt and pepper";
        break;
    case showLogo:
        return "Show Logo";
        break;
    case convertToNewCspace:
        return "Convert Colorspace";
        break;
    case equalizeHistogram:
        return "Equalize histogram";
        break;
    case dilate:
        return "Dilate BW image";
        break;
    case erode:
        return "Erode BW image";
        break;
    case open_morph:
        return "Open BW image";
        break;
    case close_morph:
        return "Close BW image";
        break;
    case blur:
        return "Gaussian blur";
        break;
    case sobel:
        return "Sobel Edges";
        break;
    case laplacian:
        return "Laplacian";
        break;
    case customKernel:
        return "Custom Kernel";
        break;
    case cannyedge:
        return "Edges using Canny";
        break;
    case houghlines:
        return "Hough Lines";
        break;
    case houghcircles:
        return "Hough Circles";
        break;
    case conCompContours:
        return "Connected Components";
        break;
    case conCompMinEnCircle:
        return "Min. Enclosing Circles of Shapes";
        break;
    case conCompBoundingBoxes:
        return "Bounding Boxes of Shapes";
        break;
    case harrisCorners:
        return "Harris Corners";
        break;
    case fastKeypoints:
        return "Fast Keypoints";
        break;
    case surfKeypoints:
        return "SURF Keypoints";
        break;
    case siftKeypoints:
        return "SIFT Keypoints";
        break;
    default:
        return "Not an active Process";
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
    case addSaltAndPepper:
    {
        int npixels = controller->mf_getInputImage().rows * controller->mf_getInputImage().cols;
        controller->addNoiseSaltAndPepper_set_NcorruptedPixels(0.05*npixels);
        controller->addNoiseSaltAndPepper_process();
        return true;
    }

        //--------------------------------
        // code 1: add logo
        //--------------------------------
    case showLogo:
        // add logo
        controller->addLogo_process_addLogoTo();
        return true;

        //--------------------------------
        // code 2: convert colorspace
        //--------------------------------
    case convertToNewCspace:
        // add load image allows loading color images
        return true;

        //--------------------------------
        // code 3: equalize histogram
        //--------------------------------
    case equalizeHistogram:
        controller->computeHistogram_process_computeHistogramNormalizedImage();
        return true;

        //--------------------------------
        // code 4: dilate
        //--------------------------------
    case dilate:
        controller->morphology_setStructuringElement(processComm->sel_dilation);
        controller->morphology_dilate();
        return true;

        //--------------------------------
        // code 5: erode
        //--------------------------------
    case erode:
        controller->morphology_setStructuringElement(processComm->sel_erosion);
        controller->morphology_erode();
        return true;
        //--------------------------------
        // code 6: open
        //--------------------------------
    case open_morph:
        controller->morphology_setStructuringElement(processComm->sel_erosion);
        controller->morphology_open();
        return true;
        //--------------------------------
        // code 7: close
        //--------------------------------
    case close_morph:
        controller->morphology_setStructuringElement(processComm->sel_dilation);
        controller->morphology_close();
        return true;
        //--------------------------------
        // code 8: gaussian blur
        //--------------------------------
    case blur:
        controller->kernel_gaussianBlur();
        return true;
        //--------------------------------
        // code 9: sobel
        //--------------------------------
    case sobel:
        controller->kernel_filterSobel();
        return true;
        //--------------------------------
        // code 10: laplacian
        //--------------------------------
    case laplacian:
        controller->kernel_filterLaplacian();
        return true;
        //--------------------------------
        // code 11: custom kernel
        //--------------------------------
    case customKernel:
        controller->kernel_setKernel(processComm->customKernel);
        controller->kernel_filterCustomKernel();
        return true;
        //--------------------------------
        // code 12: Canny edge detection
        //--------------------------------
    case cannyedge:
        controller->kernel_setCannyLowerThresh(processComm->cannyLowerThresh);
        controller->kernel_setCannyUpperThresh(processComm->cannyUpperThresh);
        controller->kernel_filterCanny();
        return true;
        //--------------------------------
        // code 13: Probabilistic Hough Lines
        //--------------------------------
    case houghlines:
        controller->structure_findLines();
        controller->structure_drawHoughLinesP();
        return true;
        //--------------------------------
        // code 14: Probabilistic Hough Circles
        //--------------------------------
    case houghcircles:
        controller->structure_findCircles();
        controller->structure_drawHoughCircles();
        return true;
        //--------------------------------
        // code 15: connected components
        //--------------------------------
    case conCompContours:
        controller->structure_findContours();
        controller->structure_drawContours();
        return true;
        //--------------------------------
        // code 16: Min. Enclosing Circles of Connected Components
        //--------------------------------
    case conCompMinEnCircle:
        controller->structure_findContours();
        controller->structure_drawMinEnclosingCirclesUsingContours();
        return true;
        //--------------------------------
        // code 17: Bounding boxes of Connected Components
        //--------------------------------
    case conCompBoundingBoxes:
        controller->structure_findContours();
        controller->structure_drawBoundingBoxUsingContours();
        return true;
        //--------------------------------
        // code 18: Harris Corners
        //--------------------------------
    case harrisCorners:
        controller->interestPoints_drawHarrisCornersOnImage();
        return true;
        //--------------------------------
        // code 19: FAST Keypoints
        //--------------------------------
    case fastKeypoints:
        controller->interestPoints_detectFastKeypoints();
        controller->interestPoints_drawFastKeypoints();
        return true;
        //--------------------------------
        // code 20: SURF Keypoints
        //--------------------------------
    case surfKeypoints:
        controller->interestPoints_detectSurfKeypoints();
        controller->interestPoints_drawSurftKeypoints();
        return true;
        //--------------------------------
        // code 21: SIFT Keypoints
        //--------------------------------
    case siftKeypoints:
        controller->interestPoints_detectSiftKeypoints();
        controller->interestPoints_drawSiftKeypoints();
        return true;
        //--------------------------------
        // unrecognized code: do nothing
        //--------------------------------
    default:
        return false;
    }
}
