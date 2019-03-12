#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::VideoCapture capture = cv::VideoCapture(0);
    if (!capture.isOpened()) {
        fprintf(stderr, "camera not found\n");
        return -1;
    }

    int width = capture.get(cv::CAP_PROP_FRAME_WIDTH);
    int height = capture.get(cv::CAP_PROP_FRAME_HEIGHT);

    cv::Point center(width/2, height/2);
    double degree = 0;

    while(1) {
        cv::Mat frame;
        capture >> frame;

        if (frame.empty()) {
            fprintf(stderr, "capture failed\n");
            break;
        }

        cv::Mat affine_trans = cv::getRotationMatrix2D(center, degree, 1.0);
        cv::Mat dst;
        cv::warpAffine(frame, dst, affine_trans, cv::Size(width, height));
        degree += 1.0;

        cv::imshow("f", dst);

        if ((cv::waitKey(1) & 0xff) == 'q')
            break;
    }

    capture.release();
    cv::destroyAllWindows();

    return 0;
}
