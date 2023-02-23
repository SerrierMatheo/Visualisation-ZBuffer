//
// Created by Serrier Mathéo on 21/02/2023.
//

#include "Vertex.h"
#include "iosfwd"
#include "iostream" //

using namespace std;
using namespace V;

double Vertex::getX() const {
    return x;
}

double Vertex::getY() const {
    return y;
}

double Vertex::getZ() const {
    return z;
}

void Vertex::setX(double X) {
    this->x = X;
}

void Vertex::setY(double Y) {
    Vertex::y = Y;
}

void Vertex::setZ(double Z) {
    Vertex::z = Z;
}

string Vertex::afficherInfo() const{
    std::string info = "";
    info += "Coordonnees du point : (" + std::to_string(this->getX())+", "+ std::to_string(this->getY()) + ", " + std::to_string(this->getZ()) + ")\n";
    info += "Valeur RGBA : (" + std::to_string(this->r) + "," + std::to_string(this->g) + "," + std::to_string(this->b) + "," + std::to_string(this->a) + ")\n";
    return info;
}

unsigned char Vertex::getR() const {
    return r;
}

void Vertex::setR(unsigned char r) {
    Vertex::r = r;
}

unsigned char Vertex::getG() const {
    return g;
}

void Vertex::setG(unsigned char g) {
    Vertex::g = g;
}

unsigned char Vertex::getB() const {
    return b;
}

void Vertex::setB(unsigned char b) {
    Vertex::b = b;
}

unsigned char Vertex::getA() const {
    return a;
}

void Vertex::setA(unsigned char a) {
    Vertex::a = a;
}
