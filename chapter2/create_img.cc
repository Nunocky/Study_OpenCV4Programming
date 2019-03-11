#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::Mat::zeros(400, 400, CV_8UC3);

    // img[:,:] = [255, 0, 0]
    // cv2.imwrite("blueImage.jpg", img)
    // cv2.imshow("img1", img)
    img = cv::Scalar(255, 0, 0);
    cv::imwrite("blueImage.jpg", img);
    cv::imshow("img1", img);

    // img[:,:] = [0, 255, 0]
    // cv2.imwrite("greenImage.jpg", img)
    // cv2.imshow("img2", img)
    img = cv::Scalar(0, 255, 0);
    cv::imwrite("greenImage.jpg", img);
    cv::imshow("img2", img);

    // img[:,:] = [0, 0, 255]
    // cv2.imwrite("redImage.jpg", img)
    // cv2.imshow("img3", img)
    img = cv::Scalar(0, 0,255);
    cv::imwrite("redImage.jpg", img);
    cv::imshow("img3", img);


    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
