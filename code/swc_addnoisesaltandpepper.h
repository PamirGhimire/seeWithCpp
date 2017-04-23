#ifndef SWC_ADDNOISESALTANDPEPPER_H
#define SWC_ADDNOISESALTANDPEPPER_H

// opencv headers
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class swc_addNoiseSaltAndPepper
{
private:
    // number of pixels to which salt and pepper noise is to be added
    int mv_nPixels2Corrupt;

public:
    // default constructor
    swc_addNoiseSaltAndPepper();

    // add salt and pepper noise to inputim and write the result to outputim
    void mf_addSaltAndPepper(const cv::Mat &inputim, cv::Mat& outputim);

    // get& set number of pixels to corrupt
    int mf_getNPixels2Corrput() const;

    void mf_setNPixels2Corrupt(int n);
};

#endif // SWC_ADDNOISESALTANDPEPPER_H
