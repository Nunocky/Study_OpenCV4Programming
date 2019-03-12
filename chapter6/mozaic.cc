#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    const double SCALE = 0.2;
    const int height = img.rows;
    const int width  = img.cols;
    
    cv::Mat dst;
    cv::resize(img, dst, cv::Size(), SCALE, SCALE, cv::INTER_NEAREST);
    cv::resize(dst, dst, cv::Size(), 1/SCALE, 1/SCALE, cv::INTER_NEAREST);

    cv::imwrite("mozaic.jpg", dst);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
