#ifndef PROCESSES_H
#define PROCESSES_H
//---------------------------------------------------------
#include <stdio.h>
#include<iostream>
#include<math.h>
#include<qdebug.h>
#include<vector>

#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>

// add salt and pepper noise to the image
void fn_swcAddSaltAndPepper(const cv::Mat &inputim, cv::Mat& outputim, int npixels);

// reduce the number of colors
void fn_swcReduceColors(const cv::Mat &inputim, cv::Mat& outputim, int graystep);

// sharpen image by convolving with laplacian kernel
void fn_swcSharpenUsingLaplacian_3by3(const cv::Mat& inputim, cv::Mat& outputim);


//----------------------------------------------------------
#endif // PROCESSES_H
