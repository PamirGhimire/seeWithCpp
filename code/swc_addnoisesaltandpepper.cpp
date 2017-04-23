#include "swc_addnoisesaltandpepper.h"

// default constructor
swc_addNoiseSaltAndPepper::swc_addNoiseSaltAndPepper()
{
    // if not specified how many pixels to corrupt, corrupt none
    mv_nPixels2Corrupt = 0;

}

// ---------------------------------------------------------------------------------------------
// function for adding noise to inputim and storing the result in outputim
void swc_addNoiseSaltAndPepper::mf_addSaltAndPepper(const cv::Mat &inputim, cv::Mat &outputim)
{
    // reallocate outputim if it is not the same size and type as inputim
    outputim.create(inputim.size(), inputim.type());

    // clone the input image to the output location, only if locations are different
    if (&inputim != &outputim){
        outputim = inputim.clone();
    }
    outputim.create(inputim.size(), inputim.type());

    // for specified number of pixels that are to be corrupted
    for (int i = 0; i<mv_nPixels2Corrupt; i++){

        // pick at random an image location
        int u = rand() % inputim.cols;
        int v = rand() % inputim.rows;

        // make random choice for salt or pepper
        int sp = rand() % 2;

        // corrupt the random location; discriminate between uni and multichannel images
        if (inputim.channels() == 1){
            // uni-channel image
            if (sp == 0){
                // add salt
                outputim.at<uchar>(v, u) = 255;
            }else{
                // add pepper
                outputim.at<uchar>(v, u) = 0;
            }
        }
        else if (inputim.channels() == 3){
            // multi-channel image
            if (sp == 0){
                // add salt
                outputim.at<cv::Vec3b>(v, u) [0] = 255;
                outputim.at<cv::Vec3b>(v, u) [1] = 255;
                outputim.at<cv::Vec3b>(v, u) [2] = 255;

            }else{
                // add pepper
                outputim.at<cv::Vec3b>(v, u) [0] = 0;
                outputim.at<cv::Vec3b>(v, u) [1] = 0;
                outputim.at<cv::Vec3b>(v, u) [2] = 0;
            }

        }
    }
}

// ---------------------------------------------------------------------------------------------
// Get number of pixels to be corrupted
int swc_addNoiseSaltAndPepper::mf_getNPixels2Corrput() const{
    return mv_nPixels2Corrupt;
}

// ---------------------------------------------------------------------------------------------
// Set number of pixels to be corrupted
void swc_addNoiseSaltAndPepper::mf_setNPixels2Corrupt(int n){
    mv_nPixels2Corrupt = n;
}

// ---------------------------------------------------------------------------------------------
