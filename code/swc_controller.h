#ifndef SWC_CONTROLLER_H
#define SWC_CONTROLLER_H

#include<stdio.h>
#include<string>

#include <opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include"swc_addnoisesaltandpepper.h"
#include"swc_addlogo.h"


class swc_controller
{

private:
    // Models:
    // Salt and pepper noise model
    swc_addNoiseSaltAndPepper* mod_addNoiseSaltAndPepper;

    // Add logo model
    swc_addLogo* mod_addLogo;

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
    // Salt and pepper noise model:
    // add noise to input image in controller
    void addNoiseSaltAndPepper_process();

    // get the number of pixels that the algorithm corrupts
    int addNoiseSaltAndPepper_get_NcorruptedPixels();

    // set the number of pixels that the algorithm is to corrupt
    void addNoiseSaltAndPepper_set_NcorruptedPixels(int n);


    //------------------------------------------------------------
    // Add Logo model:
    // get logo
    cv::Mat addLogo_getLogo() const;

    // set logo image
    bool addLogo_setLogo(std::string logoFilename);

    // add logo to a given image
    void addLogo_process_addLogoTo(const cv::Mat& inputim, cv::Mat& outputim);

    // get logo width
    int addLogo_getLogoWidth() const;

    // set logo width
    void addLogo_setLogoWidth(int logoWidth);

    // get logo height
    int addLogo_getLogoHeight() const;

    // set logo height
    void addLogo_setLogoHeight(int logoHeight) const;
};

#endif // SWC_CONTROLLER_H
