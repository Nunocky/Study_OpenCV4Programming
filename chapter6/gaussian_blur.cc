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
    
    cv::GaussianBlur(img, dst, cv::Size(13, 13), 10, 10);
    cv::imwrite("gaussianBlur1.jpg", dst);
    cv::imshow("dst1", dst);
    
    cv::GaussianBlur(img, dst, cv::Size(31, 5), 80, 3);
    cv::imwrite("gaussianBlur2.jpg", dst);
    cv::imshow("dst2", dst);



    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
