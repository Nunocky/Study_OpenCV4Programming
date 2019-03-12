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
    
    cv::medianBlur(img, dst, 11);
    cv::imwrite("medianBlur1.jpg", dst);
    cv::imshow("dst1", dst);

    cv::medianBlur(img, dst, 33);
    cv::imwrite("medianBlur2.jpg", dst);
    cv::imshow("dst2", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
