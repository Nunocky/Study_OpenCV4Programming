#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("desktop.jpg");
    cv::Mat msk = cv::imread("desktop_mask.png", cv::IMREAD_GRAYSCALE);

    if (img.empty() || msk.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::Mat dst;
    cv::inpaint(img, msk, dst, 1, cv::INPAINT_TELEA);

    cv::imwrite("dst.jpg", dst);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
