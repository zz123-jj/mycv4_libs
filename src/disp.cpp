#include "disp.hpp"

void disp3channel(cv::Mat& src){
    if(src.channels() != 3){
        std::cerr << "Input image must have 3 channels." << std::endl;
        return;
    }
    
    std::vector<std::string> windows_name = {"Blue Channel", "Green Channel", "Red Channel"};
    //mat vector to hold splitted channels
    std::vector<cv::Mat> channels;
    cv::Mat zeros = cv::Mat::zeros(src.size(), CV_8UC1);
    cv::split(src, channels);

    for(int i = 0; i < src.channels(); i++){
        std::vector<cv::Mat> merged_channels = {zeros, zeros, zeros};
        cv::namedWindow(windows_name[i]);
        merged_channels[i] = channels[i];
        cv::Mat result;
        cv::merge(merged_channels, result);
        cv::imshow(windows_name[i], result);
    }
}