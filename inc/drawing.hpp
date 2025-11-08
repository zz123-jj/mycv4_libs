#pragma once

#include <opencv2/opencv.hpp>
#include <string>

namespace Drawing {
    
    class RectangleDrawer {
    private:
        cv::Mat &original_img;      
        cv::Mat temp_img;           
        bool is_drawing;            
        cv::Point start_point;     
        cv::Point end_point;       
        cv::Scalar color;          
        int thickness;              
        static void mouseCallback(int event, int x, int y, int flags, void* userdata);
        
    public:
        
        RectangleDrawer(cv::Mat& img);
        void enable(const std::string& window_name);
    };
}

