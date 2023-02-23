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

    std::string  line;
    int vertexCount = 0;
    int faceCount = 0;
    colF = false;
    colV = false;

    //lecture du header
    while (getline(file, line)) {
        // Nombre de sommets
        if (line.find("element vertex") != std::string::npos) {
            vertexCount = std::stoi(line.substr(15));
        }

        // Nombre de faces
        if (line.find("element face") != std::string::npos) {
            faceCount = std::stoi(line.substr(13));
        }

        // Si la ligne contient "property uchar red", alors l'objet a une couleur de vertex
        if (line.find("property uchar red") != std::string::npos) {
            colV = true;
        }

        // Si la ligne contient "property uchar red" ou "property uchar diffuse_red", alors l'objet a une couleur de face
        if (line.find("property uchar red") != std::string::npos || line.find("property uchar diffuse_red") != std::string::npos) {
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
        double x,y,z;
        file >> x >> y >> z ;
        vertex.setX(x);
        vertex.setY(y);
        vertex.setZ(z);

        //this->v.push_back(vertex);
        if (colV) {
            unsigned char r,g,b,a;
            file >> r >> g >> b >> a;
            vertex.setR(r);
            vertex.setG(g);
            vertex.setB(b);
            vertex.setA(a);
        }

        v.push_back(vertex);
    }

    // Lecture des faces
    for (int i = 0; i < faceCount; i++) {
        F::Face face;
        int vertexIndexCount;
        file >> vertexIndexCount;
        vector<int> index;

        for (int j = 0; j < vertexIndexCount; j++) {
            int id;
            file >> id;
            //std::cout << std::to_string(id) << std::endl;
            index.push_back(id);
        }

        if (colF) {
            unsigned char r, g, b, a;
            file >> r >> g >> b >> a;
            face.setR(r);
            face.setG(g);
            face.setB(b);
            face.setA(a);
        }
        face.setIndex(index);

        f.push_back(face);
    }

    file.close();

    /**int numVertices = 0, numFaces = 0;
    while (getline(file,line)) {
        if (line.find("element vertex") == 0) {
            numVertices = stoi(line.substr(15));
        } else if (line.find("element face") == 0) {
            numFaces = stoi(line.substr(13));
        } else if (line == "end_header") {
            break;
        }
    }

    for (int i = 0; i < numVertices; i++) {
        double x,y,z;
        unsigned char r,g,b,a;
        file >> x >> y >> z >> r >> g >> b >> a;
        V::Vertex vertex;
        vertex.setX(x);
        vertex.setY(y);
        vertex.setZ(z);
        vertex.setR(r);
        vertex.setG(g);
        vertex.setB(b);
        vertex.setA(a);
        this->v.push_back(vertex);
    }

    for (int i = 0; i < numFaces; i++){
        int numIndices;
        file >> numIndices;
        F::Face face;
        for (int j = 0; j < numIndices; j++) {
            int index;
            file >> index;
            face.addVertexIndex(index);
        }
        unsigned char r, g, b, a;
        file >> r >> g >> b >> a;
        face.setR(r);
        face.setG(g);
        face.setB(b);
        face.setA(a);

        this->f.push_back(face);
    }*/
}

/**O::PlyObject3D::PlyObject3D(std::vector<V::Vertex> v, std::vector<F::Face> f) : v(std::move(v)), f(std::move(f)) {
}

O::PlyObject3D::PlyObject3D(std::vector<V::Vertex> v, bool colV, std::vector<F::Face> f, bool colF) :
    v(std::move(v)),
    colV(colV),
    f(std::move(f)),
    colF(colF) {
}*/

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



