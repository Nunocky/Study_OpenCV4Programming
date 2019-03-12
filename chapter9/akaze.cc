#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat src1 = cv::imread("../images/Lenna.bmp");
    cv::Mat src2 = cv::imread("Lenna2.bmp");

    if (src1.empty() || src2.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    cv::Ptr<cv::FeatureDetector> detector = cv::AKAZE::create();
//    cv::Ptr<cv::FeatureDetector> detector = cv::ORB::create();

    std::vector<cv::KeyPoint> keypoints1, keypoints2;
    cv::Mat descriptor1, descriptor2;
    detector->detectAndCompute(src1, cv::Mat(), keypoints1, descriptor1);
    detector->detectAndCompute(src2, cv::Mat(), keypoints2, descriptor2);

//    cv::BFMatcher matcher = cv::BFMatcher(cv::NORM_HAMMING);
    cv::BFMatcher matcher = cv::BFMatcher(cv::NORM_HAMMING, true);
//    cv::BFMatcher matcher = cv::BFMatcher(cv::NORM_L2);

    std::vector<cv::DMatch> matches;

    matcher.match(descriptor1, descriptor2, matches);

    cv::Mat dst;
    
    cv::drawMatches(src1,
                    keypoints1,
                    src2,
                    keypoints2,
                    matches,
                    dst,
                    cv::Scalar::all(-1),
                    cv::Scalar::all(-1),
                    std::vector<char>(),
                    cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

    cv::imwrite("dst.jpg", dst);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
