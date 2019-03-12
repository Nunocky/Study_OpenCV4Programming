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

    int height = img1.rows;
    int width = img1.cols;

    cv::Mat img_mask = cv::Mat::zeros(height, width, CV_8UC1);

    for (int y = height/4; y < height*3/4; y++) {
        for (int x = width/4; x < width*3/4; x++) {
            img_mask.at<uint8_t>(y, x) = 255;
        }
    }

    cv::Mat dst;
    
    cv::add(img1, img2, dst, img_mask);
    cv::imwrite("addMask1.jpg", dst);
    cv::imshow("dst1", dst);

    cv::add(img1, img2, img1, img_mask);
    cv::imwrite("addMask2.jpg", img1);
    cv::imshow("dst2", img1);



    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
