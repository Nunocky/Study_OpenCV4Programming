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

    cv::flip(img, dst, 0);
    cv::imwrite("flip0.jpg", img);
    cv::imshow("dst1", dst);

    cv::flip(img, dst, 1);
    cv::imwrite("flip1.jpg", img);
    cv::imshow("dst2", dst);

    cv::flip(img, dst, -1);
    cv::imwrite("flip-1.jpg", img);
    cv::imshow("dst3", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
