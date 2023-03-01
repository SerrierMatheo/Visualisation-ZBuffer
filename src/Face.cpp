//
// Created by Serrier Mathéos on 21/02/2023.
//

#include "Face.h"
#include "iostream" //

using namespace std;
using namespace F;

/**
 * getId : return you the value of id attribute
 * @return
 */
const std::vector<int> Face::getIndex() const {
    return index;
}

void Face::setIndex(const vector<int> &ID) {
    Face::index = ID;
}

unsigned char Face::getR() const {
    return r;
}

void Face::setR(unsigned char R) {
    Face::r = R;
}

unsigned char Face::getG() const {
    return g;
}

void Face::setG(unsigned char G) {
    Face::g = G;
}

unsigned char Face::getB() const {
    return b;
}

void Face::setB(unsigned char B) {
    Face::b = B;
}

unsigned char Face::getA() const {
    return a;
}

void Face::setA(unsigned char A) {
    Face::a = A;
}

string Face::afficherInfo() const{
    std::string info;
    info += "Liste des id des sommets : \n";
    vector<int> vi = this->getIndex();
    for (int i : vi) {
        info += "[" + std::to_string(i) + "] : Point " + std::to_string(i) + "\n";
    }
    info += "Valeur RGBA : (" + std::to_string(this->r) + "," + std::to_string(this->g) + "," + std::to_string(this->b) + "," + std::to_string(this->a) + ")\n";
    return info;
}



Face::Face(const vector<int> &index) {
    this->index = index;
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 0;
}

Face::Face() {
    vector<int> v;
    this->index = v;
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 0;
}

