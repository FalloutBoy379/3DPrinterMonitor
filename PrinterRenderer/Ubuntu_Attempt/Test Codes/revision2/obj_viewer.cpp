#include <GL/glut.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

const aiScene* scene = NULL;
Assimp::Importer importer;
float scale = 1.0f; // Uniform scale factor
float angle = 0.0f; // Rotation angle

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, // Camera is at (0,0,3), in World Space
              0.0f, 0.0f, 0.0f, // and looks at the origin
              0.0f, 1.0f, 0.0f); // Head is up (set to 0,-1,0 to look upside-down)
    glScalef(scale, scale, scale); // Scale the model uniformly
    glRotatef(angle, 0.0f, 1.0f, 0.0f); // Rotate the model around the y-axis

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

void reshape(int w, int h) {
    if (h == 0) h = 1;
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
            scale *= 1.1f;
            break;
        case '-':
            scale /= 1.1f;
            break;
        case 'a':
            angle -= 5.0f;
            break;
        case 'd':
            angle += 5.0f;
            break;
        case 27: // ESC key
            exit(0);
            break;
    }
    glutPostRedisplay(); // Redraw the scene
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDisable(GL_CULL_FACE);

    GLfloat lightPos[4] = {0.0, 0.0, 1.0, 0.0};
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

    // Check if a filename is provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename.obj>" << std::endl;
        return 1;
    }

    scene = importer.ReadFile(argv[1], 
        aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_GenNormals);

    if (!scene) {
        std::cerr << "Error: " << importer.GetErrorString() << std::endl;
        return 1;
    }

    std::cout << "Successfully imported OBJ file, " << scene->mNumMeshes << " meshes." << std::endl;

    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
