#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::Mat::zeros(400, 400, CV_8UC3);

    cv::circle(img, cv::Size(200, 200), 50, cv::Scalar(255, 0, 0), 1);
    cv::imwrite("circle1.jpg", img);
    cv::imshow("img1", img);

    img = cv::Mat::zeros(400, 400, CV_8UC3);
    cv::circle(img, cv::Size(200, 200), 100, cv::Scalar(0, 255, 0), 3);
    cv::imwrite("circle2.jpg", img);
    cv::imshow("img2", img);
    
    img = cv::Mat::zeros(400, 400, CV_8UC3);
    cv::circle(img, cv::Size(200, 200), 150, cv::Scalar(0, 0, 255), -1);
    cv::imwrite("circle3.jpg", img);
    cv::imshow("img3", img);
    

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
