#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::putText(img, "Hello OpenCV", cv::Point(50, 50), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(50, 60, 80), 2);

    cv::imwrite("puttext.jpg", img);
    cv::imshow("img", img);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
