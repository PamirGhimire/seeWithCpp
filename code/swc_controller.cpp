#include "swc_controller.h"

//---------------------------------------------------------------------
// Controller : default constructor
swc_controller::swc_controller()
{
    // Initialize controller member variables
    mv_inputim = cv::Mat(640, 480, CV_8UC1, cv::Scalar(200));
    mv_inputim.copyTo(mv_outputim);

    // Initialize pointers to different models:
    // Salt and Pepper noise model
    mod_addNoiseSaltAndPepper = new swc_addNoiseSaltAndPepper();
    // Add Logo Model
    mod_addLogo = new swc_addLogo();
}

//---------------------------------------------------------------------
// Controller : destructor
swc_controller::~swc_controller()
{
    // Release pointers to different modules
    delete mod_addNoiseSaltAndPepper;

}

//---------------------------------------------------------------------
// Controller : set input image
bool swc_controller::mf_setInputImage(std::string filename)
{

    cv::Mat inputim = cv::imread(filename, 0);

    // reallocate mv_inputim so that it is of same size and type as the read image
    mv_inputim.create(inputim.size(), inputim.type());
    mv_inputim = inputim;

    // return false if the image was not loaded
    if (!mv_inputim.data){
        return false;
    }else{
        return true;
    }
}

//---------------------------------------------------------------------
// Controller : get input image
cv::Mat swc_controller::mf_getInputImage() const
{
    return mv_inputim;
}

//---------------------------------------------------------------------
// Controller : get output image
cv::Mat swc_controller::mf_getOutputImage() const
{
    return mv_outputim;
}

//---------------------------------------------------------------------
// Module : Add salt and pepper noise : process image
void swc_controller::addNoiseSaltAndPepper_process()
{
    mod_addNoiseSaltAndPepper->mf_addSaltAndPepper(mv_inputim, mv_outputim);
}

//---------------------------------------------------------------------
// Module : Add salt and pepper noise : get how many pixels the module is corrupting
int swc_controller::addNoiseSaltAndPepper_get_NcorruptedPixels()
{
    return mod_addNoiseSaltAndPepper->mf_getNPixels2Corrput();
}

//---------------------------------------------------------------------
// Module : Add salt and pepper noise : set how many pixels the module is to corrupt
void swc_controller::addNoiseSaltAndPepper_set_NcorruptedPixels(int n)
{
    mod_addNoiseSaltAndPepper->mf_setNPixels2Corrupt(n);
}

//---------------------------------------------------------------------
// Module : Add Logo
// get logo
cv::Mat swc_controller::addLogo_getLogo() const{
    return mod_addLogo->mf_getLogo();
}
//---------------------------------------------------------------------
// Module : Add Logo
// set logo image
bool swc_controller::addLogo_setLogo(std::string logoFilename){
    return mod_addLogo->mf_setLogo(logoFilename);
}
//---------------------------------------------------------------------
// Module : Add Logo
// add logo to a given image
void swc_controller::addLogo_process_addLogoTo(const cv::Mat& inputim, cv::Mat& outputim){
    mod_addLogo->mf_addLogoTo(inputim, outputim);
}
//---------------------------------------------------------------------
// Module : Add Logo
// get logo width
int swc_controller::addLogo_getLogoWidth() const{
    return mod_addLogo->mf_getLogoWidth();
}

//---------------------------------------------------------------------
// Module : Add Logo
// set logo width
void swc_controller::addLogo_setLogoWidth(int logoWidth){
    mod_addLogo->mf_setLogoWidth(logoWidth);
}

//---------------------------------------------------------------------
// Module : Add Logo
// get logo height
int swc_controller::addLogo_getLogoHeight() const{
    return mod_addLogo->mf_getLogoHeight();
}
//---------------------------------------------------------------------
// Module : Add Logo
// set logo height
void swc_controller::addLogo_setLogoHeight(int logoHeight) const{
    mod_addLogo->mf_setLogoHeight(logoHeight);
}



