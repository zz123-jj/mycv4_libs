#include "drawing.hpp"
namespace Drawing {
    
    RectangleDrawer::RectangleDrawer(cv::Mat& img)
        : original_img(img), is_drawing(false), color(cv::Scalar(0, 255, 0)), thickness(1) {
        original_img.copyTo(temp_img);
    }
    
    void RectangleDrawer::enable(const std::string& window_name) {
        cv::setMouseCallback(window_name, mouseCallback, this);
    }
    
    void RectangleDrawer::mouseCallback(int event, int x, int y, int flags, void* userdata) {
        RectangleDrawer* drawer = static_cast<RectangleDrawer*>(userdata);
        switch(event) {
            case cv::EVENT_LBUTTONDOWN:
                
                drawer->is_drawing = true;
                drawer->start_point = cv::Point(x, y);
                drawer->end_point = cv::Point(x, y);
                break;
                
            case cv::EVENT_MOUSEMOVE:
                
                if (drawer->is_drawing) {
                    
                    drawer->original_img.copyTo(drawer->temp_img);
                    drawer->end_point = cv::Point(x, y);
                    
                    cv::rectangle(drawer->temp_img, drawer->start_point, drawer->end_point, 
                                drawer->color, drawer->thickness);
                    cv::imshow("OpenCV Test", drawer->temp_img);
                }
                break;
                
            case cv::EVENT_LBUTTONUP:
                
                if (drawer->is_drawing) {
                    drawer->is_drawing = false;
                    drawer->end_point = cv::Point(x, y);
                   
                    cv::rectangle(drawer->original_img, drawer->start_point, drawer->end_point, 
                                drawer->color, drawer->thickness);
                    drawer->original_img.copyTo(drawer->temp_img);
                    cv::imshow("OpenCV Test", drawer->original_img);
                    
                    std::cout << "Rectangle: (" << drawer->start_point.x << "," 
                             << drawer->start_point.y << ") -> (" 
                             << drawer->end_point.x << "," << drawer->end_point.y << ")" 
                             << std::endl;
                }
                break;
        }
    }
}