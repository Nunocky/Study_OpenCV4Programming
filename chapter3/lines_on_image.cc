#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::line(img, cv::Point(50, 50), cv::Point(200, 50), cv::Scalar(255, 0, 0));
    cv::line(img, cv::Point(50, 100), cv::Point(200, 100), cv::Scalar(0, 255, 0), 5);

    cv::imwrite("LinesOnImage.jpg", img);
    cv::imshow("img1", img);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
