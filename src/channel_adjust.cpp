#include "channel_adjust.hpp"

// 全局变量（用于 Trackbar）
static cv::Mat g_src_copy;
static cv::Mat g_result;
static int g_blue_gain = 100;
static int g_green_gain = 100;
static int g_red_gain = 100;

// Trackbar 回调函数
void adjustChannelsCallback(int, void*) {
    std::vector<cv::Mat> channels;
    cv::split(g_src_copy, channels);
    
    // 调整各通道
    cv::multiply(channels[0], g_blue_gain / 100.0, channels[0]);
    cv::multiply(channels[1], g_green_gain / 100.0, channels[1]);
    cv::multiply(channels[2], g_red_gain / 100.0, channels[2]);
    
    cv::merge(channels, g_result);
    cv::imshow("Adjusted Channels", g_result);
}

void adjust_channels(cv::Mat& src) {
    // 复制源图像
    g_src_copy = src.clone();
    
    // 创建窗口
    cv::namedWindow("Adjusted Channels");
    
    // 创建滑动条
    cv::createTrackbar("Blue Gain", "Adjusted Channels", &g_blue_gain, 200, adjustChannelsCallback);
    cv::createTrackbar("Green Gain", "Adjusted Channels", &g_green_gain, 200, adjustChannelsCallback);
    cv::createTrackbar("Red Gain", "Adjusted Channels", &g_red_gain, 200, adjustChannelsCallback);
    
    // 初始调用以显示图像
    adjustChannelsCallback(0, nullptr);
    
    std::cout << "Channel adjustment controls:" << std::endl;
    std::cout << "  Blue/Green/Red Gain: 100 = original, >100 = enhance, <100 = reduce" << std::endl;
}
