#include <cstdio>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[])
{
    cv::Mat img = cv::imread("../images/Lenna.bmp");
    if (img.empty()) {
        fprintf(stderr, "read failed\n");
        return 0;
    }

    int rows = img.rows;
    int cols = img.cols;
    int x0 = cols/4;
    int x1 = (cols*3)/4;
    int y0 = rows/4;
    int y1 = (rows*3)/4;

    cv::Point2f list_src[] = {cv::Point2f(x0, y0),
                              cv::Point2f(x0, y1),
                              cv::Point2f(x1, y1),
                              cv::Point2f(x1, y0)};

    cv::Mat dst;
    cv::Mat perspective_matrix;

    // pattern-0
    int x_margin = cols/10;
    int y_margin = rows/10;

    cv::Point2f list_dsts[] = {cv::Point2f(x0 + x_margin, y0 + y_margin),
                               list_src[1],
                               list_src[2],
                               cv::Point2f(x1 - x_margin, y0 + y_margin)};
    
    perspective_matrix = cv::getPerspectiveTransform(list_src, list_dsts);
    cv::warpPerspective(img, dst, perspective_matrix, img.size());
    cv::imwrite("dst0.jpg", img);
    cv::imshow("dst0", dst);

    // pattern-1
    x_margin = cols/8;
    y_margin = rows/8;

    cv::Point2f list_dsts2[] = {list_src[0],
                                list_src[1],
                                cv::Point2f(x1 - x_margin, y1 - y_margin),
                                cv::Point2f(x1 - x_margin, y0 + y_margin)};
    
    perspective_matrix = cv::getPerspectiveTransform(list_src, list_dsts2);
    cv::warpPerspective(img, dst, perspective_matrix, img.size());
    cv::imwrite("dst1.jpg", img);
    cv::imshow("dst1", dst);

    // pattern-2
    x_margin = cols/6;
    y_margin = rows/6;

    cv::Point2f list_dsts3[] = {cv::Point2f(x0 + x_margin, y0 + y_margin),
                                list_src[1],
                                cv::Point2f(x1 - x_margin, y1 - y_margin),
                                list_src[3]};
    
    perspective_matrix = cv::getPerspectiveTransform(list_src, list_dsts3);
    cv::warpPerspective(img, dst, perspective_matrix, img.size());
    cv::imwrite("dst2.jpg", img);
    cv::imshow("dst2", dst);




    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
