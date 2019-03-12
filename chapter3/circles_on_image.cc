#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::circle(img, cv::Size(50, 50), 40, cv::Scalar(0, 255, 0), 2);
    cv::circle(img, cv::Size(150, 150), 80, cv::Scalar(255, 255, 0), 6);
    cv::circle(img, cv::Size(200, 200), 50, cv::Scalar(0, 255, 255), -1);

    cv::imwrite("CirclesOnImage.jpg", img);
    cv::imshow("img1", img);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
