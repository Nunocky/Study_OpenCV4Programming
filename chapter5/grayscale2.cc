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
    cv::cvtColor(img, dst, cv::COLOR_RGB2GRAY);

    cv::imwrite("grayscale.jpg", dst);
    cv::imshow("img", dst);


    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
