#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    cv::Mat templ = cv::imread("template.jpg");
    if (img.empty() || templ.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::Mat result;
    cv::matchTemplate(img, templ, result, cv::TM_CCOEFF_NORMED);

    cv::Point maxLoc;

    cv::minMaxLoc(result, NULL, NULL, NULL, &maxLoc);

    cv::Mat dst(img);
    cv::rectangle(dst, maxLoc, cv::Size(maxLoc.x + templ.cols, maxLoc.y + templ.rows), cv::Scalar(0, 0, 255), 2);

    cv::imwrite("dst_match.jpg", dst);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
