//
// Created by Stages on 07/03/2023.
//

#include "Object3D.h"


#include <fstream>
#include <sstream>
#include <cmath>
#include "iostream" //

using namespace std;
using namespace O;

const int COURT = 0;
const int LONG = 1;

O::Object3D::Object3D() {
    vector<V::Vertex> vert;
    v = vert;
    colV = false;
    vector<F::Face> face;
    f = face;
    colF = false;
    vector<V::Vertex> norm;
}

/**
 * Constructeur paramétré
 * @param filename correspond au nom du fichier .ply à partir du quel on souhaite créer un Object3D
 */
Object3D::Object3D(std::string filename) {
    std::string filePath = "../Ressources/" + filename;
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
    //    for (int i = 0; i < faceCount; i++) {
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
                face.setR(0);
                face.setG(0);
                face.setB(0);
                face.setA(0);
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
            face.setA(0);
            face.setIndex(index);
        }
        //TODO appeler polygonToTriangles() et ajouter les faces à f
        vector<vector<int> > vtriangles = polygonToTriangles(face);

        if(vtriangles.size() > 1){
            for (int j = 0; j < vtriangles.size(); ++j) {
                F::Face fc;
                fc.setIndex(vtriangles[j]);
                fc.setR(face.getR());
                fc.setG(face.getG());
                fc.setB(face.getB());
                fc.setA(face.getA());
                f.push_back(fc);
                fc.afficherInfo();
            }
        }else {
            f.push_back(face);
        }
    }

    //décomposition des faces non triangulaire
    flipOrientation();
    computeFaceNormals();
    file.close();
}


string Object3D::afficherInfo(int size) const{

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
            info += "nombre de normales : " + std::to_string(this->n.size()) + "\n";
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
                V::Vertex t = this->n[i];
                info += "normale de la face : " + t.afficherInfo() + "\n";
            }
            break;
        default:
            info = "ERROR";
            break;
    }
    return info;
}

const std::vector<V::Vertex> &O::Object3D::getV() const {
    return v;
}

void O::Object3D::setV(const std::vector<V::Vertex> &vert) {
    Object3D::v = vert;
}

bool O::Object3D::isColV() const {
    return colV;
}

void O::Object3D::setColV(bool cV) {
    Object3D::colV = cV;
}

const std::vector<F::Face> &O::Object3D::getF() const {
    return f;
}

void O::Object3D::setF(const std::vector<F::Face> &face) {
    Object3D::f = face;
}

bool O::Object3D::isColF() const {
    return colF;
}

void O::Object3D::setColF(bool cF) {
    Object3D::colF = cF;
}

const vector<V::Vertex> &Object3D::getN() const {
    return n;
}

void Object3D::createFile(string fileName) {
    string filePath = "../Ressources/" + fileName + ".ply";
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

    for (const F::Face& face : this->f) {
        file << face.getIndex().size() << " ";

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

//calcul de produit vectoriel
V::Vertex Object3D::cross(V::Vertex v1, V::Vertex v2) {
    V::Vertex result;
    result.setX(v1.getY()*v2.getZ() - v1.getZ()*v2.getY());
    result.setY(v1.getZ()*v2.getX() - v1.getX()*v2.getZ());
    result.setZ(v1.getX()*v2.getY() - v1.getY()*v2.getX());
    return result;
}

//normalise la normale obtenue grâce au produit vectoriel des representant de la face
void Object3D::normalize(V::Vertex w) {
    double norm = sqrt(w.getX()*w.getX() + w.getY()*w.getY() + w.getZ()*w.getZ());

    w.setX(w.getX() / norm);
    w.setY(w.getY() / norm);
    w.setZ(w.getZ() / norm);
}

//Pour chaque face de l'instance, calcul et normalise la normale et l'ajoute dans le vector<Vertex> n
void Object3D::computeFaceNormals() {

    for (int i = 0; i < f.size(); ++i) {
        if(f[i].getIndex().size() > 3){
            //TODO erreur du au découpage en triangle
            throw std::runtime_error("Nombre de sommets != 3");
        }

        V::Vertex u;
        V::Vertex v1;
        //calculer u et v
        V::Vertex A = this->v[this->f[i].getIndex()[0]];
        //std::cout << f[i].afficherInfo() << std::endl;
        V::Vertex B = this->v[this->f[i].getIndex()[1]];
        //std::cout << B.afficherInfo() << std::endl;
        V::Vertex C = this->v[this->f[i].getIndex()[2]];
        //std::cout << C.afficherInfo() << std::endl;

        u.setX(B.getX()-A.getX());
        u.setY(B.getY()-A.getY());
        u.setZ(B.getZ()-A.getZ());
        //std::cout << u.afficherInfo() << std::endl;

        v1.setX(C.getX()-A.getX());
        v1.setY(C.getY()-A.getY());
        v1.setZ(C.getZ()-A.getZ());
        //std::cout << v1.afficherInfo() << std::endl;

        V::Vertex w = cross(u,v1);
        normalize(w);
        //std::cout << "normale : " + w.afficherInfo() << std::endl;
        this->n.push_back(w);
    }
}

void Object3D::flipOrientation() {
    for (int i = 0; i < f.size(); ++i) {
        V::Vertex v1 = this->v[this->f[i].getIndex()[0]];
        V::Vertex v2 = this->v[this->f[i].getIndex()[1]];
        V::Vertex v3 = this->v[this->f[i].getIndex()[2]];
        bool b = f[i].isClockwise(v1,v2,v3);
        int i0 = this->f[i].getIndex()[0];
        int i1 = this->f[i].getIndex()[1];
        int i2 = this->f[i].getIndex()[2];
        std::vector<int> newIndex;// = {i0,i2,i1};
        newIndex.push_back(i0);
        newIndex.push_back(i2);
        newIndex.push_back(i1);
        if(b){
            std::cout << "face [" + std::to_string(i) + "] : clockwise" << std::endl;
        }else {
            this->f[i].setIndex(newIndex);
            std::cout << "face [" + std::to_string(i) + "] : counterclockwise" << std::endl;
        }
    }
}


/**
* Permet de convertir un Object3D en objet
* @param o un Object3D
* @return obj un Objet
*/
Objet Object3D::Object3DtoObjet(Object3D o) {
    Objet obj;

    //remplir le vector de faces de obj

    //parcours des faces
    for (int i = 0; i < o.getF().size(); ++i) {
        Face f;
        f.points = o.getF()[i].getIndex();

        //donne la couleur à la face courante
        if (o.isColF()){
            unsigned char r = static_cast<unsigned char>(o.getF()[i].getR());
            unsigned char g = static_cast<unsigned char>(o.getF()[i].getG());
            unsigned char b = static_cast<unsigned char>(o.getF()[i].getB());
            unsigned char a = static_cast<unsigned char>(o.getF()[i].getA());
            Couleur c = {r, g, b, a};
            f.c.push_back(c);
        }else{
            Couleur c = {0, 0, 0, 0};
            f.c.push_back(c);
        }
        //Vector uv is empty
        //Attribution de la normale
        //dans l'ordre des faces car c'est dans ce même ordre qu'elles sont stockés par l'Object3D
        double x,y,z;
        x = o.getN()[i].getX();
        y = o.getN()[i].getY();
        z = o.getN()[i].getZ();
        Vec norm;
        norm.push_back(x);
        norm.push_back(y);
        norm.push_back(z);
        f.normale = norm;

        //ajoute la face au vector de faces de obj
        obj.faces.push_back(f);
    }

    //remplir point de obj
    Mat p;

    //parcourir v de o
    for (int i = 0; i < o.getV().size(); ++i) {
        //recupérer x,y,z de o.v[i]
        double x,y,z;
        x = o.getV()[i].getX();
        y = o.getV()[i].getY();
        z = o.getV()[i].getZ();
        Vec point;
        point.push_back(x);
        point.push_back(y);
        point.push_back(z);

        //ajoute les points à la matrice
        p.push_back(point);
    }

    //initialise points de obj
    obj.points = p;
    return obj;
}

//f a plus de 3 sommets
//TODO à modifier
vector<vector<int> > Object3D::polygonToTriangles(F::Face f) {
    vector<vector<int> > vIndex;

    if (f.getIndex().size() > 3) {
        for (int i = 1; i < f.getIndex().size() - 1; i++) {
            vector<int> triangle; //= { f.getIndex()[0], f.getIndex()[i], f.getIndex()[i+1] };
            triangle.push_back(f.getIndex()[0]);
            triangle.push_back(f.getIndex()[i]);
            triangle.push_back(f.getIndex()[i+1]);
            vIndex.push_back(triangle);
        }
    } else {
        vIndex.push_back(f.getIndex());
    }

    return vIndex;
}
