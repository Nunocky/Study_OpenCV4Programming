#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Parrots.bmp");

    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    int height = img.rows;
    int width = img.cols;
    cv::Mat blue = cv::Mat::zeros(cv::Size(width, height), CV_8UC3);
    blue = cv::Scalar(128, 0, 0);

    cv::Mat dst;
    
    cv::add(img, blue, dst);

    cv::imwrite("addScalar.jpg", dst);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
