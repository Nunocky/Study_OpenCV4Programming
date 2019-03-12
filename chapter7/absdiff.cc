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
    
    cv::absdiff(img1, img2, dst);
    cv::imwrite("absdiff.jpg", dst);
    cv::imshow("dst1", dst);

    int height = img1.rows;
    int width = img1.cols;

    cv::Mat blue = cv::Mat::zeros(cv::Size(width, height), CV_8UC3);
    blue = cv::Scalar(128, 0, 0);
    
    cv::absdiff(img1, blue, dst);
    cv::imwrite("absdiffScalar.jpg", dst);
    cv::imshow("dst2", dst);

    
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
