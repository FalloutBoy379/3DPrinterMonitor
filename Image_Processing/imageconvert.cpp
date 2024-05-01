#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    // Check if the correct number of command-line arguments are provided
    if (argc != 3) {
        cout << "Usage: ./draw_contour <input_image_path> <output_image_path>" << endl;
        return -1;
    }

    // Read the input image
    Mat image = imread(argv[1]);
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // Convert the image to grayscale
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    // Apply GaussianBlur to reduce noise and improve contour detection
    GaussianBlur(grayImage, grayImage, Size(5, 5), 0);

    // Detect edges using Canny
    Mat edges;
    Canny(grayImage, edges, 50, 150);

    // Find contours
    vector<vector<Point>> contours;
    findContours(edges, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // Draw contours on the image
    Mat contourImage = Mat::zeros(image.size(), CV_8UC3);
    for (size_t i = 0; i < contours.size(); ++i) {
        Scalar color = Scalar(255, 255, 255); // White color
        drawContours(contourImage, contours, static_cast<int>(i), color, FILLED);
    }

    // Convert the contour image to grayscale
    Mat contourGray;
    cvtColor(contourImage, contourGray, COLOR_BGR2GRAY);

    // Threshold to create a binary image
    Mat binaryImage;
    threshold(contourGray, binaryImage, 0, 255, THRESH_BINARY);

    // Save the binary image
    imwrite(argv[2], binaryImage);
    cout << "Binary image saved successfully as " << argv[2] << endl;

    return 0;
}
