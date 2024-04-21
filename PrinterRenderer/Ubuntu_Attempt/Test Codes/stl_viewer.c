#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float x, y, z;
} Vertex;

typedef struct {
    Vertex normal;
    Vertex v1, v2, v3;
} Triangle;

Triangle *triangles = NULL;
int numTriangles = 0;

#include <ctype.h>  // Include for character handling functions

void loadSTL(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[1024];
    char header[80];
    fgets(header, sizeof(header), file); // Read the first line to bypass the header

    numTriangles = 0;
    int capacity = 10;
    triangles = malloc(sizeof(Triangle) * capacity);

    while (fgets(line, sizeof(line), file)) {
        char* trimmed_line = line;
        while (isspace(*trimmed_line)) trimmed_line++; // Trim leading whitespace

        if (strncmp(trimmed_line, "facet normal", 12) == 0) {
            if (numTriangles == capacity) {
                capacity *= 2;
                triangles = realloc(triangles, sizeof(Triangle) * capacity);
            }

            sscanf(trimmed_line, "facet normal %f %f %f", &triangles[numTriangles].normal.x, &triangles[numTriangles].normal.y, &triangles[numTriangles].normal.z);
            fgets(line, sizeof(line), file); // Read "outer loop"
            fgets(line, sizeof(line), file);
            sscanf(line, " vertex %f %f %f", &triangles[numTriangles].v1.x, &triangles[numTriangles].v1.y, &triangles[numTriangles].v1.z);
            fgets(line, sizeof(line), file);
            sscanf(line, " vertex %f %f %f", &triangles[numTriangles].v2.x, &triangles[numTriangles].v2.y, &triangles[numTriangles].v2.z);
            fgets(line, sizeof(line), file);
            sscanf(line, " vertex %f %f %f", &triangles[numTriangles].v3.x, &triangles[numTriangles].v3.y, &triangles[numTriangles].v3.z);
            fgets(line, sizeof(line), file); // Read "endloop"
            fgets(line, sizeof(line), file); // Read "endfacet"
            numTriangles++;
        }
    }
    fclose(file);
    printf("Successfully read %d triangles.\n", numTriangles);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < numTriangles; i++) {
        glNormal3f(triangles[i].normal.x, triangles[i].normal.y, triangles[i].normal.z);
        glVertex3f(triangles[i].v1.x, triangles[i].v1.y, triangles[i].v1.z);
        glVertex3f(triangles[i].v2.x, triangles[i].v2.y, triangles[i].v2.z);
        glVertex3f(triangles[i].v3.x, triangles[i].v3.y, triangles[i].v3.z);
    }
    glEnd();
    glutSwapBuffers();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 1000.0); // Adjust near and far planes
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -50.0); // Adjust based on the object size
    glRotatef(25, 1, 0, 0);
}


int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <STL file>\n", argv[0]);
        return 1;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("STL Viewer");
    init();
    loadSTL(argv[1]); // Load the STL file provided as a command-line argument
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
