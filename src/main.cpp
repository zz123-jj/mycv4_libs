#include <opencv2/opencv.hpp>
#include <iostream>
#include "drawing.hpp"
#include "disp.hpp"
using namespace cv;
using namespace std;

Mat g_p1;
Mat g_p2;
vector<Mat> channels;
vector<Mat> result_channels(3);
int bar_valsRect = 0;
int bar_valsCircle = 0;

void rectColor_cb(int, void*);
void circleColor_cb(int, void*);


int main() {
    namedWindow("Original Image");
    
    g_p1 = imread("/Users/Shared/CLion_Workspace_C++/OpenCV4/OpenCV_Code_Demo/Demo1/p1.jpeg");
    if(g_p1.empty()){
        cerr << "Error loading image" << endl;
        return -1;
    }
    
    imshow("Original Image", g_p1);
    
    disp3channel(g_p1);
    
    waitKey(0);
    return 0;
}




// void rectColor_cb(int, void*) {
   
//     rectangle(g_p1,Rect(100,100,824,824), Scalar(bar_valsRect, 0, bar_valsRect), 24);
//     split(g_p1, channels);
//     imshow("OpenCV Test", g_p1);
//     imshow("channel 0", channels[0]);
//     imshow("channel 1", channels[1]);
//     imshow("channel 2", channels[2]);
// }
// void circleColor_cb(int, void*){
//      circle(g_p1, Point(512, 512), 256, Scalar(0, bar_valsCircle, bar_valsCircle), 32); 
//      split(g_p1, channels);
//      imshow("OpenCV Test", g_p1);
//      imshow("channel 0", channels[0]);
//      imshow("channel 1", channels[1]);
//      imshow("channel 2", channels[2]);
// }



