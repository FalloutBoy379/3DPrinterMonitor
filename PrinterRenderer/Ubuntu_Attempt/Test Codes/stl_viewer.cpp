#include <GL/glut.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

const aiScene* scene = NULL;
Assimp::Importer importer;

void display() {
    glColor3f(1.0, 0.7, 0.3); // Set a default color for the model (e.g., a soft orange)

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);

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

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat diffuse_light[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat ambient_light[] = { 0.2, 0.2, 0.2, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);

    glClearColor(0.1, 0.1, 0.1, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.33, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("STL Viewer with Assimp and OpenGL");

    scene = importer.ReadFile("/home/ansh/Desktop/EC535/3DPrinterMonitor/Cube_3d_printing_sample.stl", 
        aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);

    if(!scene) {
        std::cerr << "Error: " << importer.GetErrorString() << std::endl;
        return 1;
    }

    std::cout << "Successfully imported STL File, " << scene->mNumMeshes << " Meshes" << std::endl;

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
