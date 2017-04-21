#include<processes.h>

// add salt and pepper noise
void fn_swcAddSaltAndPepper(const cv::Mat &inputim, cv::Mat& outputim, int npixels){

    // clone the input image to the output location, only if locations are different
    if (&inputim != &outputim){
        outputim = inputim.clone();
    }

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

//--------------------------------------------------------------------------
// reduce number of colors, new unit = graystep (instead of unit = 1)
// image traversed using pointers

void fn_swcReduceColors(const cv::Mat &inputim, cv::Mat& outputim, int graystep)
{
    // clone the input image to the output location, only if locations are different
    if (&inputim != &outputim){
        outputim = inputim.clone();
    }

    // number of columns in the image
    int ncols = inputim.cols * inputim.channels();

    // for each row in the image
    for (int nrow = 0; nrow < inputim.rows; nrow++){
        // get the pointer to the first element of the row
        uchar* rowdata = outputim.ptr<uchar>(nrow);

        // for each column in the row
        for (int ncol = 0; ncol < ncols; ncol++){
            // apply process
            rowdata[ncol] = nearbyint ( (1.00 * (rowdata[ncol])) / graystep ) * graystep;
        }
    }

}

