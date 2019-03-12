#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    const double SCALE1 = 0.5;
    const double SCALE2 = 1.62;
    int height = img.rows;
    int width = img.cols;

    cv::Mat dst;

    cv::resize(img, dst, cv::Size(width * SCALE1, height * SCALE1));
    cv::imwrite("resize0.5.jpg", img);
    cv::imshow("dst1", dst);
    
    cv::resize(img, dst, cv::Size(width * SCALE2, height * SCALE2));
    cv::imwrite("resize1.62.jpg", img);
    cv::imshow("dst2", dst);
    
    cv::resize(img, dst, cv::Size(400, 200));
    cv::imwrite("resize400x200.jpg", img);
    cv::imshow("dst3", dst);


    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
