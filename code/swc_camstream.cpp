#include "swc_camstream.h"

swc_camstream::swc_camstream(QObject *parent) : QObject(parent)
{
    // initialize current frame as zeros
    mv_currFrame = cv::Mat(320, 240, CV_8UC1, cv::Scalar(0));

    // initialize the camera as attached webcam
    md_cam = new cv::VideoCapture();
    md_cam->open(0);

    mv_threadIsActive = false;

}

//-----------------------------------
// slot : capture from camera
//-----------------------------------
void swc_camstream::mf_camcapture(){

    mv_threadIsActive = true;

    while (1){
        qDebug() << "trying to capture";

        // get camera if it is not available
        if (!md_cam->isOpened()){
            md_cam->open(0);
        }

        cv::Mat frame;
        md_cam->read(frame);
        if (!frame.empty()){
            cv::cvtColor(frame, mv_currFrame, CV_RGB2GRAY);
            emit ms_frameAvailable();

        }

        if(!mv_threadIsActive){
            break;
        }

        delay(33);
    }
}
//------------------------------------------------------------

// release camera
void swc_camstream::mf_releaseCam(){
    qDebug() << "streaming thread finished";
    if(md_cam->isOpened()){
        md_cam->release();
    }
    mv_threadIsActive = false;
}
//------------------------------------------------------------
cv::Mat swc_camstream::mf_getCurrentFrame(){
    return mv_currFrame;
}

//------------------------------------------------------------
void swc_camstream::delay( int millisecondsToWait ){
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {}
}

//------------------------------------------------------------
// Destructor : release camera
swc_camstream::~swc_camstream(){
    md_cam->release();
    mv_threadIsActive = false;
}
