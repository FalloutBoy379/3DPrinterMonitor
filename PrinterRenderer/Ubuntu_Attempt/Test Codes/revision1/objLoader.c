#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef struct {
    float x, y, z;
} Vertex;

typedef struct {
    int v1, v2, v3;  // Indices of the vertices forming a face
} Face;

Vertex *vertices = NULL;  // Dynamic array of vertices
Face *faces = NULL;       // Dynamic array of faces
int vertexCount = 0, faceCount = 0;

void readObj(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }

    char line[128];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == 'v' && line[1] == ' ') {
            Vertex v;
            sscanf(line, "v %f %f %f", &v.x, &v.y, &v.z);
            vertices = realloc(vertices, (vertexCount + 1) * sizeof(Vertex));
            vertices[vertexCount++] = v;
            printf("Vertex %d: %f, %f, %f\n", vertexCount, v.x, v.y, v.z);
        } else if (line[0] == 'f' && line[1] == ' ') {
            Face f;
            int numRead = sscanf(line, "f %d/%*d/%*d %d/%*d/%*d %d/%*d/%*d", &f.v1, &f.v2, &f.v3);
            if (numRead != 3) {
                // Try parsing with a single index after double slashes
                numRead = sscanf(line, "f %d//%*d %d//%*d %d//%*d", &f.v1, &f.v2, &f.v3);
                if (numRead != 3) {
                    // Fallback to parsing without slashes
                    numRead = sscanf(line, "f %d %d %d", &f.v1, &f.v2, &f.v3);
                    if (numRead != 3) {
                        printf("Error parsing face line: %s", line);
                        continue;  // Skip this face entry
                    }
                }
            }
            faces = realloc(faces, (faceCount + 1) * sizeof(Face));
            faces[faceCount++] = f;
            printf("Face %d: %d, %d, %d\n", faceCount, f.v1, f.v2, f.v3);
        }
    }
    fclose(file);
}

void drawFace(SDL_Renderer *renderer, int faceIndex) {
    if (faceIndex < 0 || faceIndex >= faceCount) {
        printf("Invalid face index: %d\n", faceIndex);
        return;
    }

    // Define scale to fit the cube in the window and translation to center it
    float scale = 9.0f;  // This needs to be adjusted to fit your cube size
    float offsetX = 600;  // Assuming window width is 800
    float offsetY = 500;  // Assuming window height is 600

    Face face = faces[faceIndex];

    // Simple orthographic projection, ignoring z-coordinate
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); // White color
    SDL_RenderDrawLine(renderer,
        offsetX + vertices[face.v1 - 1].x * scale,
        offsetY - vertices[face.v1 - 1].y * scale,  // Subtract to invert the y-axis
        offsetX + vertices[face.v2 - 1].x * scale,
        offsetY - vertices[face.v2 - 1].y * scale);
    SDL_RenderDrawLine(renderer,
        offsetX + vertices[face.v2 - 1].x * scale,
        offsetY - vertices[face.v2 - 1].y * scale,
        offsetX + vertices[face.v3 - 1].x * scale,
        offsetY - vertices[face.v3 - 1].y * scale);
    SDL_RenderDrawLine(renderer,
        offsetX + vertices[face.v3 - 1].x * scale,
        offsetY - vertices[face.v3 - 1].y * scale,
        offsetX + vertices[face.v1 - 1].x * scale,
        offsetY - vertices[face.v1 - 1].y * scale);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename.obj>\n", argv[0]);
        exit(1);
    }

    readObj(argv[1]);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL could not initialize: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *window = SDL_CreateWindow("OBJ Viewer",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        fprintf(stderr, "Renderer could not be created: %s\n", SDL_GetError());
        exit(1);
    }

    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        // Inside your main loop
        for (int i = 0; i < faceCount; i++) {
            drawFace(renderer, i);
        }


        SDL_RenderPresent(renderer);
        SDL_Delay(100);  // Delay to reduce CPU usage
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    free(vertices);
    free(faces);

    return 0;
}
