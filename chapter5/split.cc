#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    std::vector<cv::Mat> mv;
    
    cv::split(img, mv);

    cv::Mat &blue  = mv[0];
    cv::Mat &green = mv[1];
    cv::Mat &red   = mv[2];

    cv::imwrite("b.jpg", blue);
    cv::imshow("blue", blue);

    cv::imwrite("g.jpg", green);
    cv::imshow("green", green);

    cv::imwrite("r.jpg", red);
    cv::imshow("red", red);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
