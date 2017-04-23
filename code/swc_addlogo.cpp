#include "swc_addlogo.h"

// default constructor
swc_addLogo::swc_addLogo()
{
    // some good initializations
    mv_logoWidth = 32;
    mv_logoHeight = 32;

    mv_logoim = cv::Mat(mv_logoWidth, mv_logoHeight, CV_8UC1, cv::Scalar(100));
}

//------------------------------------------------------------------
// get logo
cv::Mat swc_addLogo::mf_getLogo() const{
    return mv_logoim;
}

//------------------------------------------------------------------
// set logo image
bool swc_addLogo::mf_setLogo(std::string logoFilename){
    // load the logo image file from disk
    cv::Mat logoim_ondisk = cv::imread(logoFilename, 0);

    // resize it to logo width and height, and place it in member variable 'logoim'
    mv_logoim.create(cv::Size(mv_logoWidth, mv_logoHeight), logoim_ondisk.type());
    cv::resize(logoim_ondisk, mv_logoim, cv::Size(mv_logoWidth, mv_logoHeight));

    // return false if logo was not loaded from disk
    if(!logoim_ondisk.data){
        return false;
    }else{ // else, return true
        return true;
    }
}

//------------------------------------------------------------------
// add logo to a given image
void swc_addLogo::mf_addLogoTo(const cv::Mat& inputim, cv::Mat& outputim){
    // if input and output locations are different, copy input to output
    if(&inputim != &outputim){
        outputim.create(inputim.size(), inputim.type());
        inputim.copyTo(outputim);
    }

    // define a region of the output image as ROI
    int roi_topleft_u = outputim.cols - mv_logoHeight - 2;
    int roi_topleft_v = outputim.rows - mv_logoWidth - 2;
    cv::Mat outputim_roi = outputim(cv::Rect(roi_topleft_u, roi_topleft_v, mv_logoWidth, mv_logoHeight));

    // add the logo to the ROI
    cv::addWeighted(outputim_roi, 0.5, mv_logoim, 0.5, 0, outputim_roi);

}

//------------------------------------------------------------------
// get logo width
int swc_addLogo::mf_getLogoWidth() const{
    return mv_logoWidth;
}

//------------------------------------------------------------------
// set logo width
void swc_addLogo::mf_setLogoWidth(int logoWidth){
    mv_logoWidth = logoWidth;
}

//------------------------------------------------------------------
// get logo height
int swc_addLogo::mf_getLogoHeight() const{
    return mv_logoHeight;
}

//------------------------------------------------------------------
// set logo height
void swc_addLogo::mf_setLogoHeight(int logoHeight){
    mv_logoHeight = logoHeight;
}
//------------------------------------------------------------------
