#ifndef SWC_CONTROLLER_H
#define SWC_CONTROLLER_H

#include<stdio.h>
#include<string>

#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include"swc_addnoisesaltandpepper.h"


class swc_controller
{

private:
    // Models:
    // Salt and pepper noise model
    swc_addNoiseSaltAndPepper* mod_addNoiseSaltAndPepper;

    // ...

    // Internal Variables:
    cv::Mat mv_inputim;
    cv::Mat mv_outputim;

public:
    // Controller : Default constructor:
    swc_controller();

    // Controller : Default Destructor:
    ~swc_controller();

    //------------------------------------------------------------
    // Controller:
    // Set input image;
    bool mf_setInputImage(std::string filename);

    // Get the current input image
    cv::Mat mf_getInputImage() const;

    // Get the current output image (latest result of processing)
    cv::Mat mf_getOutputImage() const;


    //------------------------------------------------------------
    // Salt and pepper noise module:
    void addNoiseSaltAndPepper_process();

    int addNoiseSaltAndPepper_get_NcorruptedPixels();

    void addNoiseSaltAndPepper_set_NcorruptedPixels(int n);


    //------------------------------------------------------------
    //
};

#endif // SWC_CONTROLLER_H
