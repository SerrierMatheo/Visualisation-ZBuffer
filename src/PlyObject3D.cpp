//
// Created by Serrier Mathéo on 21/02/2023.
//

#include "PlyObject3D.h"

#include <utility>
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

O::PlyObject3D::PlyObject3D(std::vector<V::Vertex> v, std::vector<F::Face> f) : v(std::move(v)), f(std::move(f)) {
}

O::PlyObject3D::PlyObject3D(std::vector<V::Vertex> v, bool colV, std::vector<F::Face> f, bool colF) :
    v(std::move(v)),
    colV(colV),
    f(std::move(f)),
    colF(colF) {
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

