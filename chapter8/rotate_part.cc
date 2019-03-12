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

    cv::Point center(width/4, height/4);
    double degree = 0;

    cv::Rect roi(width/4, height/4, width/2, height/2);

    while(1) {
        cv::Mat frame;
        capture >> frame;

        if (frame.empty()) {
            fprintf(stderr, "capture failed\n");
            break;
        }

        cv::Mat frame_part = frame(roi);

        cv::Mat affine_trans = cv::getRotationMatrix2D(center, degree, 1.0);
        cv::Mat dst;
        cv::warpAffine(frame_part, dst, affine_trans, cv::Size(width/2, height/2), cv::INTER_CUBIC);
        degree += 1.0;

        //dst.copyTo(frame.rowRange(roi.y, roi.y + roi.height).colRange(roi.x, roi.x + roi.width));
        dst.copyTo(frame_part);

        cv::imshow("f", frame);

        if ((cv::waitKey(1) & 0xff) == 'q')
            break;
    }

    capture.release();
    cv::destroyAllWindows();

    return 0;
}
