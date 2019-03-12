#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    const int MAX_CORNERS = 50;
    const double QUALITY_LEVEL = 0.01;
    const double MIN_DISTANCE = 20.0;
    const int BLOCK_SIZE = 3;

    cv::Mat img = cv::imread("../images/Lenna.bmp");
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::Mat gray;


    cv::cvtColor(img, gray, cv::COLOR_RGB2GRAY);

    std::vector<cv::Point2f> corners;

    cv::goodFeaturesToTrack(gray,
                            corners,
                            MAX_CORNERS,
                            QUALITY_LEVEL,
                            MIN_DISTANCE,
                            cv::Mat(),
                            BLOCK_SIZE,
                            false);

    for (std::vector<cv::Point2f>::iterator it = corners.begin(); it != corners.end(); it++) {
        int x = it->x;
        int y = it->y;
        cv::circle(img, cv::Point(x, y), 4, cv::Scalar(255, 255, 0), 2);
    }

    cv::imwrite("corners.jpg", img);
    cv::imshow("img", img);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
