#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::imwrite("grayscale.jpg", img);
    cv::imshow("img", img);


    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
