#include <iostream>
#include <GL/glut.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <cfloat> // For FLT_MAX and FLT_MIN
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "assets/stb_image_write.h"

const aiScene* scene = NULL;
Assimp::Importer importer;
float scale = 1.0f; // Uniform scale factor
float angle = 0.0f; // Rotation angle
const float MAX_SIZE = 200.0f; // Maximum dimension of the bounding box

// Global variables for camera position and view direction
float camX = 0.0f, camY = 0.0f, camZ = 19.4f; // Camera position
float lookX = 0.0f, lookY = 0.0f, lookZ = 0.0f; // View direction

int captureView = 0;

void computeBoundingBox(const aiScene* scene, aiVector3D& minVec, aiVector3D& maxVec) {
    minVec = aiVector3D(FLT_MAX, FLT_MAX, FLT_MAX);
    maxVec = aiVector3D(-FLT_MAX, -FLT_MAX, -FLT_MAX);

    for (unsigned int m = 0; m < scene->mNumMeshes; m++) {
        const aiMesh* mesh = scene->mMeshes[m];
        for (unsigned int v = 0; v < mesh->mNumVertices; v++) {
            aiVector3D temp = mesh->mVertices[v];
            minVec.x = std::min(minVec.x, temp.x);
            minVec.y = std::min(minVec.y, temp.y);
            minVec.z = std::min(minVec.z, temp.z);
            maxVec.x = std::max(maxVec.x, temp.x);
            maxVec.y = std::max(maxVec.y, temp.y);
            maxVec.z = std::max(maxVec.z, temp.z);
        }
    }

    aiVector3D size = maxVec - minVec;
    float maxDimension = std::max(size.x, std::max(size.y, size.z));
    if (maxDimension > MAX_SIZE) {
        std::cout << "Warning: Model is too large (" << maxDimension << " units), scaling down to fit within " << MAX_SIZE << " units." << std::endl;
        scale = MAX_SIZE / maxDimension;
    }
}

void saveScreenshot(const char* filename) {
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    int x = viewport[0];
    int y = viewport[1];
    int width = viewport[2];
    int height = viewport[3];

    char* data = new char[width * height * 3];  // 3 components (R, G, B)

    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

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

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camX, camY, camZ, lookX, lookY, lookZ, 0.0f, 1.0f, 0.0f);

    if (scene && scene->HasMeshes()) {
        for (unsigned int m = 0; m < scene->mNumMeshes; m++) {
            const aiMesh* mesh = scene->mMeshes[m];
            glBegin(GL_TRIANGLES);
            for (unsigned int f = 0; f < mesh->mNumFaces; f++) {
                const aiFace& face = mesh->mFaces[f];
                for (unsigned int i = 0; i < face.mNumIndices; i++) {
                    int index = face.mIndices[i];
                    if (mesh->HasNormals()) {
                        glNormal3fv(&mesh->mNormals[index].x);
                    }
                    glVertex3fv(&mesh->mVertices[index].x);
                }
            }
            glEnd();
        }
    }

    if (captureView > 0) {
        switch (captureView) {
            case 1:
                saveScreenshot("../../img/z.png");
                break;
            // case 2:
            //     saveScreenshot("img/y.png");
            //     break;
            // case 3:
            //     saveScreenshot("img/x.png");
            //     break;
        }
        captureView = 0; // Reset the capture view
    }

    glutSwapBuffers();
}

void reshape(int width, int height) {
    if (height == 0) height = 1; // To prevent divide by zero
    float ratio = width * 1.0 / height;

    glMatrixMode(GL_PROJECTION); // Switch to the Projection matrix
    glLoadIdentity();            // Reset the projection matrix

    // Set the viewport to be the entire window
    glViewport(0, 0, width, height);

    // Set the correct perspective.
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);  // Switch back to the Modelview matrix
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDisable(GL_CULL_FACE);

    GLfloat lightPos[4] = {1.0, 1.0, 5.0, 0.0};
    GLfloat diffuse[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat ambient[4] = {0.2, 0.2, 0.2, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

    glClearColor(0.1, 0.1, 0.1, 1.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OBJ Viewer with Assimp and OpenGL");

    // if (argc < 2) {
    //     std::cerr << "Usage: " << argv[0] << " <filename.obj>" << std::endl;
    //     return 1;
    // }

    scene = importer.ReadFile("../../assets/centered_model.obj", aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_GenNormals);
    if (!scene) {
        std::cerr << "Error: " << importer.GetErrorString() << std::endl;
        return 1;
    }

    aiVector3D minVec, maxVec;
    computeBoundingBox(scene, minVec, maxVec);

    std::cout << "Successfully imported OBJ file, " << scene->mNumMeshes << " meshes." << std::endl;
    std::cout << "Bounding Box Dimensions: " << maxVec.x - minVec.x << " x " << maxVec.y - minVec.y << " x " << maxVec.z - minVec.z << std::endl;

    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    captureView = 1;
    // glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
