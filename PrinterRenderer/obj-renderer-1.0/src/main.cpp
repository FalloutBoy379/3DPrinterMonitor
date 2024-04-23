#include <iostream>
#include <GL/glut.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <cfloat>
#include "screenshot.h"

const aiScene* scene = NULL;
Assimp::Importer importer;
float scale = 1.0f;
float camX = 50.0f, camY = 0.0f, camZ = 0.0f;
float lookX = 0.0f, lookY = 0.0f, lookZ = 0.0f;
const float MAX_SIZE = 200.0f;

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

    glutSwapBuffers();
}

void reshape(int width, int height) {
    if (height == 0) height = 1;
    float ratio = width * 1.0 / height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_MODELVIEW);
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
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename.obj>" << std::endl;
        return 1;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OBJ Viewer with Assimp and OpenGL");

    scene = importer.ReadFile(argv[1], aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_GenNormals);
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
    glutMainLoop();
    return 0;
}
