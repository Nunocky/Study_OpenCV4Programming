#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::Mat dst;
    int ret;
    
    ret = cv::threshold(img, dst, 100, 200, cv::THRESH_BINARY);
    cv::imwrite("threshold_THRESH_BINARY.jpg", dst);
    cv::imshow("dst1", dst);

    ret = cv::threshold(img, dst, 100, 200, cv::THRESH_BINARY_INV);
    cv::imwrite("threshold_THRESH_BINARY_INT.jpg", dst);
    cv::imshow("dst2", dst);

    ret = cv::threshold(img, dst, 100, 200, cv::THRESH_TRUNC);
    cv::imwrite("threshold_THRESH_BINARY_INT.jpg", dst);
    cv::imshow("dst3", dst);

    ret = cv::threshold(img, dst, 100, 200, cv::THRESH_TOZERO);
    cv::imwrite("threshold_THRESH_TOZERO.jpg", dst);
    cv::imshow("dst4", dst);

    ret = cv::threshold(img, dst, 100, 200, cv::THRESH_TOZERO_INV);
    cv::imwrite("threshold_THRESH_TOZERO_INV.jpg", dst);
    cv::imshow("dst5", dst);


    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
