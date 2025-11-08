#include <opencv2/opencv.hpp>
#include <iostream>
#include "drawing.hpp"
using namespace cv;
using namespace std;

Mat g_p1;
int bar_valsRect = 0;
int bar_valsCircle = 0;

void rectColor_cb(int, void*);
void circleColor_cb(int, void*);


int main() {
    namedWindow("OpenCV Test");
    g_p1 = Mat(1024, 1024, CV_8UC3); 
    

    createTrackbar( "Rectangle color", "OpenCV Test", &bar_valsRect, 255, rectColor_cb);
    createTrackbar("Circle color", "OpenCV Test", &bar_valsCircle, 255, circleColor_cb);
    Drawing::RectangleDrawer drawer(g_p1);
    drawer.enable("OpenCV Test");
    
    imshow("OpenCV Test", g_p1);
    waitKey(0);
    return 0;
}
void rectColor_cb(int, void*) {
   
    rectangle(g_p1,Rect(100,100,824,824), Scalar(bar_valsRect, 0, bar_valsRect), 24);
    imshow("OpenCV Test", g_p1);
}
void circleColor_cb(int, void*){
     circle(g_p1, Point(512, 512), 256, Scalar(0, bar_valsCircle, bar_valsCircle), 32); 
     imshow("OpenCV Test", g_p1);
}

