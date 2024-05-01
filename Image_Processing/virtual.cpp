#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

vector<vector<int>> newPoints;
VideoCapture cap(0);

vector<vector<int>> myColors{ {124,48,117,143,170,255}, // Purple
                                {68,72,156,102,126,255} };// Green
vector<Scalar> myColorValues{ {255,0,255},       // Purple
                                {0,255,0} };// Green  

Point getContours(Mat image) {
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    
    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    Point myPoint(0, 0);

    for (int i = 0; i < contours.size(); i++) {
        int area = contourArea(contours[i]);
        cout << area << endl;

        if (area > 1000) {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

            boundRect[i] = boundingRect(conPoly[i]);
            myPoint.x = boundRect[i].x + boundRect[i].width / 2;
            myPoint.y = boundRect[i].y;
        }
    }
    return myPoint;
}

vector<vector<int>> findColor(Mat img) {
    Mat imgHSV;
    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    for (int i = 0; i < myColors.size(); i++) {
        Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
        Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
        Mat mask;
        inRange(imgHSV, lower, upper, mask);
        Point myPoint = getContours(mask);
        if (myPoint.x != 0 ) {
            newPoints.push_back({ myPoint.x, myPoint.y, i });
        }
    }
    return newPoints;
}

void drawOnCanvas(Mat& img, vector<vector<int>>& newPoints, vector<Scalar>& myColorValues) {
    for (int i = 0; i < newPoints.size(); i++) {
        circle(img, Point(newPoints[i][0], newPoints[i][1]), 10, myColorValues[newPoints[i][2]], FILLED);
    }
}

int main() {
    if (!cap.isOpened()) {
        cerr << "Error: Unable to open the webcam." << endl;
        return -1;
    }

    Mat img;
    while (true) {
        cap.read(img);
        if (img.empty()) {
            cerr << "Error: Unable to capture frame from webcam." << endl;
            break;
        }

        newPoints.clear();
        findColor(img);
        drawOnCanvas(img, newPoints, myColorValues);

        imshow("Image", img);
        waitKey(1);
    }
    cap.release();

    return 0;
}
