#include "screenshot.h"
#include <GL/glut.h>
#include <cstring>
#include "stb_image_write.h"

void saveScreenshot(const char* filename) {
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    int width = viewport[2], height = viewport[3];
    char* data = new char[width * height * 3];

    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

    // Flip the image on Y axis
    int row_size = width * 3;
    char* row = new char[row_size];
    for (int i = 0; i < height / 2; i++) {
        memcpy(row, data + i * row_size, row_size);
        memcpy(data + i * row_size, data + (height - i - 1) * row_size, row_size);
        memcpy(data + (height - i - 1) * row_size, row, row_size);
    }
    delete[] row;

    stbi_write_png(filename, width, height, 3, data, row_size);
    delete[] data;
}
