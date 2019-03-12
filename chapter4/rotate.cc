#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    int height = img.rows;
    int width = img.cols;
    cv::Point center(width/2, height/2);
    cv::Mat dst;
    cv::Mat affine_trans;

    affine_trans = cv::getRotationMatrix2D(center, 33, 1);
    cv::warpAffine(img, dst, affine_trans, cv::Size(width, height));
    cv::imwrite("rotate_033.jpg", img);
    cv::imshow("dst1", dst);
    
    affine_trans = cv::getRotationMatrix2D(center, 110, 1);
    cv::warpAffine(img, dst, affine_trans, cv::Size(width, height), cv::INTER_CUBIC);
    cv::imwrite("rotate_110.jpg", img);
    cv::imshow("dst2", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
