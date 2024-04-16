#include <>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

// Structure for a 3D vector
typedef struct {
    float x, y, z;
} Vector3D;

// Structure for a triangle in the STL file
typedef struct {
    Vector3D normal;
    Vector3D vertex1, vertex2, vertex3;
    unsigned short attributeByteCount;
} STLTriangle;

// Function to read a binary STL file
STLTriangle* readSTL(const char* filename, size_t* numTriangles) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    // Skip the header
    fseek(file, 80, SEEK_SET);

    // Read the number of triangles
    unsigned int triangleCount = 0;
    fread(&triangleCount, sizeof(unsigned int), 1, file);

    // Allocate memory for the triangles
    STLTriangle* triangles = malloc(sizeof(STLTriangle) * triangleCount);
    if (!triangles) {
        fclose(file);
        return NULL;
    }

    // Read the triangles from the file
    fread(triangles, sizeof(STLTriangle), triangleCount, file);

    fclose(file);

    *numTriangles = triangleCount;
    return triangles;
}

// Function to render the STL model
void renderModel(STLTriangle* triangles, size_t numTriangles) {
    if (!triangles) return;

    glBegin(GL_TRIANGLES);
    for (size_t i = 0; i < numTriangles; ++i) {
        STLTriangle* tri = &triangles[i];
        glVertex3f(tri->vertex1.x, tri->vertex1.y, tri->vertex1.z);
        glVertex3f(tri->vertex2.x, tri->vertex2.y, tri->vertex2.z);
        glVertex3f(tri->vertex3.x, tri->vertex3.y, tri->vertex3.z);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "STL Viewer", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    // Set the viewport
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // Set up the projection matrix
    glMatrixMode(GL_PROJECTION);
    gluPerspective(65.0, (double)width / (double)height, 1.0, 100.0);

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 0.0, 5.0,  // Camera position
        0.0, 0.0, 0.0,  // Look-at point
        0.0, 1.0, 0.0); // Up vector

    // Load the STL file
    size_t numTriangles;
    STLTriangle* triangles = readSTL("your_model.stl", &numTriangles);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Render the model
        renderModel(triangles,
