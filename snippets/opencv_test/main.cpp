#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc == 2) {
        std::string file = *(argv + 1);
        std::string title = "display";
        cv::Mat image{cv::imread(file)};
        cv::imshow(title, image);
        cv::waitKey(10000);
    } else {
        std::cout << "please provide one image as a argument\n";
    }
    return 0;
}
