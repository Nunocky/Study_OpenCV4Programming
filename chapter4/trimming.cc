#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::imshow("src", img);

    int height = img.rows;
    int width = img.cols;

    cv::Mat dst = img(cv::Range(40, height), cv::Range(40,width));

    cv::imshow("dst", dst);


    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
