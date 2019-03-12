#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    //cv::Mat img = cv::imread("family.jpg");
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::CascadeClassifier cascade = cv::CascadeClassifier("haarcascade_frontalface_alt.xml");
    //cv::CascadeClassifier cascade = cv::CascadeClassifier("haarcascade_eye.xml");

    std::vector<cv::Rect> facerect;
    cascade.detectMultiScale(img, facerect);

    if (facerect.size() > 0){
        for(std::vector<cv::Rect>::iterator it = facerect.begin(); it != facerect.end(); it++) {
            cv::rectangle(img,
                          cv::Point(it->x, it->y),
                          cv::Point(it->x + it->width, it->y + it->height),
                          cv::Scalar(0, 0, 255),
                          2);
        }
    }
    else {
        printf("no faces\n");
    }

    cv::imwrite("dobj.jpg", img);
    cv::imshow("img", img);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
