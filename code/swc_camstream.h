#ifndef SWC_CAMSTREAM_H
#define SWC_CAMSTREAM_H

#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/video/video.hpp>
#include<opencv2/videoio.hpp>

#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include <QObject>
#include<qthread.h>
#include<qdebug.h>

#include <QTime>


class swc_camstream : public QObject
{
    Q_OBJECT
private:
    // current frame
    cv::Mat mv_currFrame;

    // capture device
    cv::VideoCapture* md_cam;

    // true if thread is active
    bool mv_threadIsActive;

    // delay method to limit frame rate
    void delay( int millisecondsToWait );

public:
    explicit swc_camstream(QObject *parent = 0);
    ~swc_camstream();


signals:
    // signal availability of frame
    void ms_frameAvailable();

public slots:
    // capture from camera
    void mf_camcapture();

    // release camera
    void mf_releaseCam();

    // return current frame
    cv::Mat mf_getCurrentFrame();
};

#endif // SWC_CAMSTREAM_H
