#include <iostream>
#include <vector>
#include <cfloat>
#include <fstream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

// Function to center the vertices of a mesh at the origin
void centerMeshAtOrigin(aiMesh* mesh) {
    if (!mesh) return;

    aiVector3D minVec(FLT_MAX, FLT_MAX, FLT_MAX);
    aiVector3D maxVec(-FLT_MAX, -FLT_MAX, -FLT_MAX);

    // Calculate the bounding box
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        aiVector3D& vertex = mesh->mVertices[i];
        minVec.x = std::min(minVec.x, vertex.x);
        minVec.y = std::min(minVec.y, vertex.y);
        minVec.z = std::min(minVec.z, vertex.z);
        maxVec.x = std::max(maxVec.x, vertex.x);
        maxVec.y = std::max(maxVec.y, vertex.y);
        maxVec.z = std::max(maxVec.z, vertex.z);
    }

    // Center of the bounding box
    aiVector3D center = (maxVec + minVec) / 2.0f;

    // Translate all vertices to center the mesh at the origin
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        mesh->mVertices[i] -= center;
    }
}

// Function to save the mesh to an OBJ file
void saveOBJ(const aiMesh* mesh, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Could not open file for writing: " << filename << std::endl;
        return;
    }

    // Write vertices
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        const aiVector3D& vertex = mesh->mVertices[i];
        outFile << "v " << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
    }

    // Write faces
    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        const aiFace& face = mesh->mFaces[i];
        outFile << "f";
        for (unsigned int j = 0; j < face.mNumIndices; j++) {
            outFile << " " << face.mIndices[j] + 1; // OBJ files are 1-indexed
        }
        outFile << std::endl;
    }

    outFile.close();
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_model.obj>\n";
        return 1;
    }

    std::string filePath = argv[1];
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(filePath, aiProcess_JoinIdenticalVertices | aiProcess_Triangulate);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
        return -1;
    }

    // Assume the first mesh is the one to be centered and saved
    aiMesh* mesh = scene->mMeshes[0];
    centerMeshAtOrigin(mesh);

    // Save the centered mesh to a new OBJ file
    std::string saveFilename = "centered_model.obj";
    saveOBJ(mesh, saveFilename);
    std::cout << "Saved centered model to " << saveFilename << std::endl;

    return 0;
}
