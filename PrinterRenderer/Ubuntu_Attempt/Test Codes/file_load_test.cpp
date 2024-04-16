#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

int main() {
    Assimp::Importer importer;

    const aiScene* scene = importer.ReadFile("/home/ansh/Desktop/EC535/3DPrinterMonitor/Cube_3d_printing_sample.stl", 
        aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);

    if(!scene) {
        std::cerr << "Error: " << importer.GetErrorString() << std::endl;
        return 1;
    }

    std::cout << "Successfully imported STL File" << scene->mNumMeshes << " Meshes" << std::endl;

    if (scene->mNumMeshes > 0) {
        const aiMesh* mesh = scene->mMeshes[0];
        std::cout << "Mesh has " << mesh->mNumVertices << " vertices." << std::endl;
    }

    return 0;
}
