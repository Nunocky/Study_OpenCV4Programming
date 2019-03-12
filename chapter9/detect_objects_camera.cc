#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::VideoCapture capture = cv::VideoCapture(0);

    if (!capture.isOpened()) {
        fprintf(stderr, "camera not found\n");
        return -1;
    }

    cv::CascadeClassifier cascade = cv::CascadeClassifier("haarcascade_frontalface_alt.xml");
    //cv::CascadeClassifier cascade = cv::CascadeClassifier("haarcascade_eye.xml");

    while(1) {
        cv::Mat frame;
        capture >> frame;

        if (frame.empty()) {
            fprintf(stderr, "capture failed\n");
            break;
        }


        std::vector<cv::Rect> facerect;
        cascade.detectMultiScale(frame, facerect);

        if (facerect.size() > 0){
            for(std::vector<cv::Rect>::iterator it = facerect.begin(); it != facerect.end(); it++) {
                cv::rectangle(frame,
                              cv::Point(it->x, it->y),
                              cv::Point(it->x + it->width, it->y + it->height),
                              cv::Scalar(0, 0, 255),
                              2);
            }
        }
//        else {
//            printf("no faces\n");
//        }

        cv::imshow("f", frame);

        if ((cv::waitKey(1) & 0xff) == 'q')
            break;
    }

    capture.release();
    cv::destroyAllWindows();

    return 0;
}
