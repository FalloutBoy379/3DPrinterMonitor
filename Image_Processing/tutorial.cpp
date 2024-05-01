#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv) {
    // Check if the input image paths are provided
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <image_path1> <image_path2>" << std::endl;
        return -1;
    }

    // Read the first input image
    Mat image1 = imread(argv[1]);

    if (image1.empty()) {
        std::cerr << "Error: Could not read the first image" << std::endl;
        return -1;
    }

    // Read the second input image
    Mat image2 = imread(argv[2]);

    if (image2.empty()) {
        std::cerr << "Error: Could not read the second image" << std::endl;
        return -1;
    }

    // Check if the dimensions of the two images are the same
    if (image1.size() != image2.size()) {
        std::cerr << "Error: Images have different dimensions" << std::endl;
        return -1;
    }

    // Convert the images to grayscale
    Mat grayImage1, grayImage2;
    cvtColor(image1, grayImage1, COLOR_BGR2GRAY);
    cvtColor(image2, grayImage2, COLOR_BGR2GRAY);

    // Compare the two images pixel by pixel
    bool match = true;
    for (int y = 0; y < image1.rows; ++y) {
        for (int x = 0; x < image1.cols; ++x) {
            if (grayImage1.at<uchar>(y, x) != grayImage2.at<uchar>(y, x)) {
                match = false;
                break;
            }
        }
        if (!match) {
            break;
        }
    }

    // Print the result
    if (match) {
        std::cout << "Images match" << std::endl;
    } else {
        std::cout << "Images do not match" << std::endl;
    }

    return 0;
}
