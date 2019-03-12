#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::Mat dst;
    cv::boxFilter(img, dst, -1, cv::Size(5, 5));

    cv::imwrite("BoxFilter.jpg", dst);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
