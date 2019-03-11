#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("lenna.jpg");
    cv::imwrite("ReadWrite.jpg", img);
    return 0;
}
