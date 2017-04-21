#ifndef PROCESSES_H
#define PROCESSES_H
//---------------------------------------------------------
#include <stdio.h>
#include<iostream>
#include<qdebug.h>

#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>

// add salt and pepper noise to the image
void fn_swcAddSaltAndPepper(cv::Mat &inputim, int npixels);




//----------------------------------------------------------
#endif // PROCESSES_H
