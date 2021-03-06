#ifndef MYLIB_H
#define MYLIB_H

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "opencv2/opencv.hpp"

// Prototype
using namespace cv;
Mat detect_cv(Mat din);
Mat seuillage_cv(Mat vin);
Mat moyenne(Mat rin);
Mat glitch(Mat zin);
Mat sobel(Mat sin);
#endif



