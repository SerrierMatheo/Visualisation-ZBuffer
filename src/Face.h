//
// Created by Serrier Mathéo on 21/02/2023.
//

#ifndef VISUALISATION_ZBUFFER_FACE_H
#define VISUALISATION_ZBUFFER_FACE_H

#include <utility>
#include <vector>
#include "string"

namespace F
{
    /**
     * Classe face
     * définie le concept de face
     * constitué d'un ensemble de vertex (vector) et d'attribut correspondant à la colorisation
     * id de type vector <int> -> ensemble des sommets de la face
     * r,g,b,a correspondant au valeur RGBA de la face
     */
    class Face {
    public:

        Face();

        Face(const std::vector<int> &index);


        const std::vector<int> &getIndex() const;

        void setIndex(const std::vector<int> &ID);

        unsigned char getR() const;

        void setR(unsigned char R);

        unsigned char getG() const;

        void setG(unsigned char G);

        unsigned char getB() const;

        void setB(unsigned char B);

        unsigned char getA() const;

        void setA(unsigned char A);

        std::string afficherInfo() const;

        void addVertexIndex(int vertex_index);

    private:
        std::vector<int> index;
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };


}



#endif //VISUALISATION_ZBUFFER_FACE_H
