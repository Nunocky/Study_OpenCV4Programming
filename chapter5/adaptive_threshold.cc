#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::Mat dst;
    
    cv::adaptiveThreshold(img, dst, 200, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 7, 8);
    cv::imwrite("adaptiveThreshold.jpg", dst);
    cv::imshow("dst1", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
