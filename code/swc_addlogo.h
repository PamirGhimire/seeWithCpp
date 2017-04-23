#ifndef SWC_ADDLOGO_H
#define SWC_ADDLOGO_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class swc_addLogo
{
private:
    cv::Mat mv_logoim;
    int mv_logoWidth;
    int mv_logoHeight;

public:
    swc_addLogo();

    // get logo
    cv::Mat mf_getLogo() const;

    // set logo image
    bool mf_setLogo(std::string logoFilename);

    // add logo to a given image
    void mf_addLogoTo(const cv::Mat& inputim, cv::Mat& outputim);

    // get logo width
    int mf_getLogoWidth() const;

    // set logo width
    void mf_setLogoWidth(int logoWidth);

    // get logo height
    int mf_getLogoHeight() const;

    // set logo height
    void mf_setLogoHeight(int logoHeight);
};

#endif // SWC_ADDLOGO_H
