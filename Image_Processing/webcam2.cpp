#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    // Check if the correct number of command-line arguments are provided
    if (argc != 3) {
        cout << "Usage: ./edge_detection <input_image_path> <output_image_path>" << endl;
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

    // Apply GaussianBlur to reduce noise and improve edge detection
    GaussianBlur(grayImage, grayImage, Size(5, 5), 0);

    // Apply Canny edge detection
    Mat edges;
    Canny(grayImage, edges, 50, 150);

    // Find contours to determine the bounding box
    vector<vector<Point>> contours;
    findContours(edges, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // Create a binary image with the bounding box area as white
    Mat binaryImage = Mat::zeros(grayImage.size(), CV_8UC1);
    if (!contours.empty()) {
        Rect boundingBox = boundingRect(contours[0]);
        rectangle(binaryImage, boundingBox, Scalar(255), FILLED);
    }

    // Save the binary image
    imwrite(argv[2], binaryImage);

    cout << "Binary image with bounding box saved successfully" << endl;

    return 0;
}
