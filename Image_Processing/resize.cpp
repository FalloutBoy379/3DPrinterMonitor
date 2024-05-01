#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstring>

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

    // Calculate scaling factor based on the ratio of image heights
    double scaleFactor = static_cast<double>(image1.rows) / image2.rows;

    // Scale the first image
    Mat scaledImage;
    resize(image1, scaledImage, Size(), scaleFactor, scaleFactor);

    // Extract the filename and extension from the first image path
    char* lastSlash = strrchr(argv[1], '/');
    char* filename = (lastSlash != nullptr) ? lastSlash + 1 : argv[1];
    char* dot = strrchr(filename, '.');
    *dot = '\0'; // Null-terminate the string at the '.' to remove the extension

    // Generate the output image path with the .png extension
    char outputPath[256];
    sprintf(outputPath, "%s_scaled.png", filename);

    // Save the scaled image
    imwrite(outputPath, scaledImage);

    std::cout << "Scaled image saved as: " << outputPath << std::endl;

    return 0;
}
