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

    int roi_target[] = {0, 1, 2, 3};
    int counter = 60;

    while(1) {
        cv::Mat frame;
        capture >> frame;

        if (frame.empty()) {
            fprintf(stderr, "capture failed\n");
            break;
        }

        cv::Mat dst = cv::Mat::zeros(cv::Size(width, height), CV_8UC3);

        int y1[] = {0,        height/2, height/2, 0};
        int y2[] = {height/2, height,   height,   height/2};
        int x1[] = {0,        0,        width/2,  width/2};
        int x2[] = {width/2,  width/2,  width,    width};

#if 1        
        for (int i=0; i<4; i++) {
            cv::Rect roi_to(x1[i], y1[i], x2[i] - x1[i], y2[i] - y1[i]);
            cv::Rect roi_from(x1[roi_target[i]], y1[roi_target[i]], x2[roi_target[i]] - x1[roi_target[i]], y2[roi_target[i]] - y1[roi_target[i]]);
            cv::Mat mat_to   = dst(roi_to);
            cv::Mat mat_from = frame(roi_from);
            mat_from.copyTo(mat_to);
        }
#else
        for (int i=0; i<4; i++) {
            int yy = y1[roi_target[i]];
            for(int y = y1[i]; y < y2[i]; y++) {
                int xx = x1[roi_target[i]];
                for(int x=x1[i]; x < x2[i]; x++) {
                    dst.at<cv::Vec3b>(y, x) = frame.at<cv::Vec3b>(yy, xx);
                    xx++;
                }
                yy++;
            }
        }
#endif
        counter--;
        if (counter <= 0){
            counter = 60;

            for (int i=0; i<4; i++) {
                roi_target[i] += 1;
                if (roi_target[i] == 4)
                    roi_target[i] = 0;
            }
        }

        cv::imshow("f", dst);

        if ((cv::waitKey(1) & 0xff) == 'q')
            break;
    }

    capture.release();
    cv::destroyAllWindows();

    return 0;
}
