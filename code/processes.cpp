#include<processes.h>


void fn_swcAddSaltAndPepper(cv::Mat &inputim, int npixels){

    // for specified number of pixels that are to be corrupted
    for (int i = 0; i<npixels; i++){

        // pick at random an image location
        int u = rand() % inputim.cols;
        int v = rand() % inputim.rows;

        // make random choice for salt or pepper
        int sp = rand() % 2;

        // corrupt the location; discriminate between uni and multichannel images
        if (inputim.channels() == 1){
            // uni-channel image
            if (sp == 0){
                // add salt
                inputim.at<uchar>(v, u) = 255;
            }else{
                // add pepper
                inputim.at<uchar>(v, u) = 0;
            }
        }
        else if (inputim.channels() == 3){
            // multi-channel image
            if (sp == 0){
                // add salt
                inputim.at<cv::Vec3b>(v, u) [0] = 255;
                inputim.at<cv::Vec3b>(v, u) [1] = 255;
                inputim.at<cv::Vec3b>(v, u) [2] = 255;

            }else{
                // add pepper
                inputim.at<cv::Vec3b>(v, u) [0] = 0;
                inputim.at<cv::Vec3b>(v, u) [1] = 0;
                inputim.at<cv::Vec3b>(v, u) [2] = 0;
            }

        }
    }
}
