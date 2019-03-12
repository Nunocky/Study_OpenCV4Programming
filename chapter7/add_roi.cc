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

    dst = img1;

    int height = img1.rows;
    int width = img1.cols;

    cv::Rect roi_rect;
    roi_rect.x = width/4;
    roi_rect.y = height/4;
    roi_rect.width = width/2;
    roi_rect.height = height/2;

    cv::Mat img1_roi(img1, roi_rect);
    cv::Mat img2_roi(img2, roi_rect);
    cv::Mat dst_roi(dst, roi_rect);
    
    cv::add(img1_roi, img2_roi, dst_roi);

    cv::imwrite("dst.jpg", dst);
    cv::imshow("dst", dst);


    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
