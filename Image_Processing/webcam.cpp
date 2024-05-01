#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    // Open the default camera
    VideoCapture cap(1);
    if (!cap.isOpened()) {
        cerr << "Error: Unable to open the webcam." << endl;
        return -1;
    }

    // Wait for 5 seconds to stabilize the camera
    cout << "Waiting for 5 seconds..." << endl;
    waitKey(5000);

    // Capture a frame from the camera
    Mat frame;
    cap >> frame;
    if (frame.empty()) {
        cerr << "Error: Unable to capture frame from webcam." << endl;
        return -1;
    }

    // Convert the captured frame to grayscale
    Mat grayFrame;
    cvtColor(frame, grayFrame, COLOR_BGR2GRAY);

    // Apply Gaussian blur to reduce noise
    GaussianBlur(grayFrame, grayFrame, Size(5, 5), 0);

    // Perform edge detection using Canny
    Mat edges;
    Canny(grayFrame, edges, 50, 150);

    // Find contours in the edges
    vector<vector<Point>> contours;
    findContours(edges, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // Draw contours on the original frame
    Mat result = frame.clone();
    drawContours(result, contours, -1, Scalar(0, 255, 0), 2);

    // Save the result
    imwrite("input_image.jpg", result);

    cout << "Image captured, converted to black and white, highlighted, and saved as result.jpg." << endl;

    return 0;
}
