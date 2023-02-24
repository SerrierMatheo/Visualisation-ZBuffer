//
// Created by Serrier Mathéo on 21/02/2023.
//

#include "PlyObject3D.h"

#include <fstream>
#include <sstream>
#include "iostream" //

using namespace std;
using namespace O;

const int COURT = 0;
const int LONG = 1;

O::PlyObject3D::PlyObject3D() {
    vector<V::Vertex> vert;
    v = vert;
    colV = false;
    vector<F::Face> face;
    f = face;
    colF = false;
}

/**
 * Constructeur paramétré
 * @param filename correspond au nom du fichier .ply à partir du quel on souhaite créer un PlyObject3D
 */
PlyObject3D::PlyObject3D(std::string filename) {
    std::string filePath = "../../Ressources/" + filename;
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    std::string line;
    int vertexCount = 0;
    int faceCount = 0;
    bool inVertexBlock = false;
    bool inFaceBlock = false;
    colF = false;
    colV = false;

    //lecture du header
    while (getline(file, line)) {
        // Nombre de sommets
        if (line.find("element vertex") != std::string::npos) {
            vertexCount = std::stoi(line.substr(15));
            inVertexBlock = true;
            inFaceBlock = false;
        }

        // Si la ligne contient "property uchar red", alors l'objet a une couleur de vertex
        if (inVertexBlock && line.find("property uchar red") != std::string::npos) {
            colV = true;
        }

        // Nombre de faces
        if (line.find("element face") != std::string::npos) {
            faceCount = std::stoi(line.substr(13));
            inFaceBlock = true;
            inVertexBlock = false;
        }

        // Si la ligne contient "property uchar red" , alors l'objet a une couleur de face
        if (inFaceBlock && line.find("property uchar red") != std::string::npos) {
            colF = true;
        }

        // Fin du header
        if (line == "end_header") {
            break;
        }
    }

    // Lecture des sommets
    for (int i = 0; i < vertexCount; i++) {
        V::Vertex vertex;
        std::string lineC;
        std::getline(file, lineC);
        std::stringstream ss(lineC);
        double x, y, z;
        ss >> x >> y >> z;
        vertex.setX(x);
        vertex.setY(y);
        vertex.setZ(z);
        if (colV) {
            unsigned int r, g, b, a;
            ss >> r >> g >> b >> a;
            //std::cout << r << g << b << a << std::endl;
            auto cr = static_cast<unsigned char>(r);
            auto cg = static_cast<unsigned char>(g);
            auto cb = static_cast<unsigned char>(b);
            auto ca = static_cast<unsigned char>(a);
            vertex.setR(cr);
            vertex.setG(cg);
            vertex.setB(cb);
            vertex.setA(ca);
        }
        v.push_back(vertex);
    }


    // Lecture des faces
    for (int i = 0; i < faceCount; i++) {
        F::Face face;
        if (!colF) {
            int vertexIndexCount;
            file >> vertexIndexCount;
            vector<int> index;

            for (int j = 0; j < vertexIndexCount; j++) {
                int id;
                file >> id;
                //std::cout << std::to_string(id) << std::endl;
                index.push_back(id);
            }
            face.setIndex(index);
        } else {

            int vertexIndexCount;
            int r, g, b, a;
            file >> vertexIndexCount;
            vector<int> index;
            for (int j = 0; j < vertexIndexCount; j++) {
                int id;
                file >> id;
                //std::cout << std::to_string(id) << std::endl;
                index.push_back(id);
            }
            file >> r >> g >> b >> a;
            auto cr = static_cast<unsigned char>(r);
            auto cg = static_cast<unsigned char>(g);
            auto cb = static_cast<unsigned char>(b);
            auto ca = static_cast<unsigned char>(a);
            face.setR(cr);
            face.setG(cg);
            face.setB(cb);
            face.setA(ca);
            face.setIndex(index);
        }
        f.push_back(face);
    }

    file.close();
}

string PlyObject3D::afficherInfo(int size) const{

    std::string info;
    switch (size) {
        case (COURT):
            //Affichage simple
            info += "Objet 3D : \n";
            info += "type : Ply \n";
            info += "nombre de vertex : " + std::to_string(this->v.size()) + "\n";
            info += "Couleur : " + std::to_string(this->isColV()) + "\n";
            info += "nombre de faces : " + std::to_string(this->f.size()) + "\n";
            info += "Couleur : " + std::to_string(this->isColF()) + "\n";
            break;
        case (LONG):
            //affichage complet
            info += "Objet 3D : \n";
            info += "type : Ply \n";
            info += "nombre de vertex : " + std::to_string(this->v.size()) + "\n";
            info += "Couleur : " + std::to_string(this->isColV()) + "\n";
            info += "liste des vertex : \n";
            for (const auto & i : this->v) {
                info += i.afficherInfo() + "\n";
            }
            info += "nombre de faces : " + std::to_string(this->f.size()) + "\n";
            info += "Couleur : " + std::to_string(this->isColF()) + "\n";
            info += "liste des faces : \n";
            for (int i = 0; i < this->f.size(); ++i) {
                info += this->getF()[i].afficherInfo() + "\n";
            }
            break;
        default:
            info = "ERROR";
            break;
    }
    return info;
}

const std::vector<V::Vertex> &O::PlyObject3D::getV() const {
    return v;
}

void O::PlyObject3D::setV(const std::vector<V::Vertex> &vert) {
    PlyObject3D::v = vert;
}

bool O::PlyObject3D::isColV() const {
    return colV;
}

void O::PlyObject3D::setColV(bool cV) {
    PlyObject3D::colV = cV;
}

const std::vector<F::Face> &O::PlyObject3D::getF() const {
    return f;
}

void O::PlyObject3D::setF(const std::vector<F::Face> &face) {
    PlyObject3D::f = face;
}

bool O::PlyObject3D::isColF() const {
    return colF;
}

void O::PlyObject3D::setColF(bool cF) {
    PlyObject3D::colF = cF;
}

void PlyObject3D::createFile(string fileName) {
    string filePath = "../../Ressources/" + fileName;
    ofstream file(filePath); //creation du fichier dans le repertoire

    if(!file.is_open()) {
        std::cerr << "Could not open file " << fileName << " for writing.";
        return;
    }

    file << "ply" << std::endl;
    file << "format ascii 1.0" << std::endl;
    file << "comment VCGLIB generated" << std::endl;
    file << "element vertex " << this->v.size() << std::endl;
    file << "property float x" << std::endl;
    file << "property float y" << std::endl;
    file << "property float z" << std::endl;

    if (this->colV) {
        file << "property uchar red" << std::endl;
        file << "property uchar green" << std::endl;
        file << "property uchar blue" << std::endl;
        file << "property uchar alpha" << std::endl;
    }

    file << "element face " << this->f.size() << std::endl;
    file << "property list uchar int vertex_indices" << std::endl;

    if(this->colF) {
        file << "property uchar red" << std::endl;
        file << "property uchar green" << std::endl;
        file << "property uchar blue" << std::endl;
        file << "property uchar alpha" << std::endl;
    }

    file << "end_header" << std::endl;

    for (const V::Vertex& vertex : this->v) {
        file << vertex.getX() << " " << vertex.getY() << " " << vertex.getZ() << " ";
        if(this->colV) {
            file << static_cast<int>(vertex.getR()) << " " << static_cast<int>(vertex.getG()) << " "
            << static_cast<int>(vertex.getB()) << " " << static_cast<int>(vertex.getA());
        }
        file << std::endl;
    }

    //std::cout << this->f.size() << std::endl;

    for (const F::Face& face : this->f) {
        file << face.getIndex().size() << " ";

        //TODO erreur probalement du au parcours du vector
        for (int idx : face.getIndex()) {
            file << idx << " ";
        }
        if (this->colF) {
            file << static_cast<int>(face.getR()) << " " << static_cast<int>(face.getG()) << " "
            << static_cast<int>(face.getB()) << " " << static_cast<int>(face.getA());
        }
        file << std::endl;
    }
    file.close();
}


