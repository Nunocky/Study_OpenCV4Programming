#include <cstdio>
#include <opencv2/opencv.hpp>


cv::Mat create_cos(int rows, int cols)
{
    cv::Mat weight(rows, cols, CV_32FC3);
    cv::Point center(cols/2, rows/2);
    double radius = sqrt(center.x * center.x + center.y * center.y);

    for(int r = 0; r<rows; r++) {
        for(int c = 0; c<cols; c++) {
            // distance from center
            double distance = sqrt((center.x - r)*(center.x - r) + (center.y - c)*(center.y - c));
            double radian = (distance/radius) * M_PI;

            double Y = (cosl(radian) + 1) / 2;
            cv::Vec3f &point = weight.at<cv::Vec3f>(r, c);
            point[0] = Y;
            point[1] = Y;
            point[2] = Y;
        }
    }

    return weight;
}

int main(int argc, char* argv[])
{
    cv::Mat img1 = cv::imread("../images/Lenna.bmp");
    cv::Mat img2 = cv::imread("../images/Parrots.bmp");

    if (img1.empty() || img2.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    img1.convertTo(img1, CV_32F, 1.0/255);
    img2.convertTo(img2, CV_32F, 1.0/255);

    int rows = img1.rows;
    int cols = img1.cols;

    cv::Mat weight = create_cos(rows, cols);
    cv::Mat i_weight = cv::Scalar(1, 1, 1) - weight;

    cv::Mat int_src1, int_src2;

    cv::multiply(img1, weight, int_src1);
    cv::multiply(img2, i_weight, int_src2);

    cv::Mat dst;
    cv::add(int_src1, int_src2, dst);

    cv::imwrite("int_src1.jpg", int_src1);
    cv::imwrite("int_src2.jpg", int_src2);
    cv::imwrite("dst.jpg", dst);

    cv::imshow("int_src1", int_src1);
    cv::imshow("int_src2", int_src2);
    cv::imshow("dst", dst);


    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
