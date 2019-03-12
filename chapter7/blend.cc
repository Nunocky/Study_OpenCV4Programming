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
    
    cv::addWeighted(img1, 0.3, img2, 0.7, 0.0, dst);
    cv::imwrite("blend0307.jpg", dst);
    cv::imshow("dst1", dst);

    cv::addWeighted(img1, 0.6, img2, 0.4, 0.0, dst);
    cv::imwrite("blend0604.jpg", dst);
    cv::imshow("dst2", dst);


    
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
