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
    
    cv::bitwise_or(img1, img2, dst);
    cv::imwrite("or.jpg", dst);
    cv::imshow("dst1", dst);

    cv::Mat img_mask = cv::imread("mask.bmp", cv::IMREAD_GRAYSCALE);
    cv::bitwise_or(img1, img2, img1, img_mask);
    cv::imwrite("orMask.jpg", img1);
    cv::imshow("dst2", img1);


    
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
