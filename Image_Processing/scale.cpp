#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv) {
    // Check if the input image paths are provided
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_image_path1> <input_image_path2>" << std::endl;
        return -1;
    }

    // Read the input images
    Mat image1 = imread(argv[1]);
    Mat image2 = imread(argv[2]);

    if (image1.empty() || image2.empty()) {
        std::cerr << "Error: Could not read one or both of the images" << std::endl;
        return -1;
    }

    // Convert the images to grayscale
    Mat grayImage1, grayImage2;
    cvtColor(image1, grayImage1, COLOR_BGR2GRAY);
    cvtColor(image2, grayImage2, COLOR_BGR2GRAY);

    // Threshold the grayscale images to get binary images
    Mat binaryImage1, binaryImage2;
    threshold(grayImage1, binaryImage1, 200, 255, THRESH_BINARY);
    threshold(grayImage2, binaryImage2, 200, 255, THRESH_BINARY);

    // Count white pixels in both images
    int whitePixels1 = countNonZero(binaryImage1);
    int whitePixels2 = countNonZero(binaryImage2);

    // Calculate scaling factor based on the ratio of white pixels
    double scaleFactor = static_cast<double>(whitePixels1) / whitePixels2;

    // Determine which image is larger
    Mat largerImage, smallerImage;
    if (scaleFactor < 1) {
        largerImage = image2;
        smallerImage = image1;
        scaleFactor = 1 / scaleFactor; // Invert for scaling down
    } else {
        largerImage = image1;
        smallerImage = image2;
    }

    // Resize the larger image to the size of the smaller image
    resize(largerImage, largerImage, Size(), 1 / scaleFactor, 1 / scaleFactor);
    

     // Compare the two images pixel by pixel
    bool match = true;
    for (int y = 0; y < smallerImage.rows; ++y) {
        for (int x = 0; x < smallerImage.cols; ++x) {
            if (smallerImage.at<uchar>(y, x) != largerImage.at<uchar>(y, x)) {
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
