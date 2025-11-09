#include <opencv2/opencv.hpp>
#include <iostream>
#include "drawing.hpp"
#include "disp.hpp"
#include "channel_adjust.hpp"
using namespace cv;
using namespace std;

Mat g_p1;



void rectColor_cb(int, void*);
void circleColor_cb(int, void*);


int main() {
    namedWindow("Original Image");
    
    g_p1 = imread("/Users/Shared/CLion_Workspace_C++/OpenCV4/OpenCV_Code_Demo/Demo1/p1.jpeg");
    if(g_p1.empty()){
        cerr << "Error loading image" << endl;
        return -1;
    }

    adjust_channels(g_p1);
    
    imshow("Original Image", g_p1);
    
    
    
    waitKey(0);
    return 0;
}







