#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("Lenna_dmg.jpg");

    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::imshow("img", img);
    
    cv::Mat msk;
    cv::cvtColor(img, msk, cv::COLOR_RGB2GRAY);

    cv::threshold(msk, msk, 240, 255, cv::THRESH_BINARY);

    cv::Mat dst;
    dst = img;
    cv::inpaint(img, msk, dst, 1, cv::INPAINT_TELEA);

    cv::imwrite("dst.jpg", dst);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
