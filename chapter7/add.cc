#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img1 = cv::imread("../images/Lenna.bmp");
    cv::Mat img2 = cv::imread("../images/Parrots.bmp");

    if (img1.empty() || img2.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::Mat dst;
    
    cv::add(img1, img2, dst);

    cv::imwrite("add.jpg", dst);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
