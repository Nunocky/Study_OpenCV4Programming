#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::VideoCapture capture = cv::VideoCapture(0);
    if (!capture.isOpened()) {
        fprintf(stderr, "camera not found\n");
        return -1;
    }

    //cv::namedWindow("f");

    while(1) {
        cv::Mat frame;
        capture >> frame;

        if (frame.empty()) {
            fprintf(stderr, "capture failed\n");
            break;
        }

        cv::Mat dst;
        cv::Canny(frame, dst, 40.0, 200.0);
        //cv::bitwise_not(dst, dst);
        cv::imshow("f", dst);

        if ((cv::waitKey(1) & 0xff) == 'q')
            break;
    }

    capture.release();
    cv::destroyAllWindows();

    return 0;
}
