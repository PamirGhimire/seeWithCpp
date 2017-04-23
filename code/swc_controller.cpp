#include "swc_controller.h"

//---------------------------------------------------------------------
// Controller : default constructor
swc_controller::swc_controller()
{
    // Initialize controller member variables
    mv_inputim = cv::Mat(640, 480, CV_8UC1, cv::Scalar(200));
    mv_inputim.copyTo(mv_outputim);

    // Initialize pointers to different modules
    mod_addNoiseSaltAndPepper = new swc_addNoiseSaltAndPepper();
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




