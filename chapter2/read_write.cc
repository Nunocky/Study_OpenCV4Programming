#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    cv::imwrite("ReadWrite.jpg", img);
    return 0;
}
