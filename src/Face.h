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
        /**
         * Constructeur par défaut
         */
        Face(){
            id = {};
            r = 0;
            g = 0;
            b = 0;
            a = 0;
        }

        /**
         * Constructeur paramétré
         * @param id
         */
        explicit Face(std::vector<int> vect) {
            id = std::move(vect);
            r = 0;
            g = 0;
            b = 0;
            a = 0;
        }

        /**
         * Constrcuteur paramétré
         * @param vect
         * @param R
         * @param G
         * @param B
         * @param A
         */
        Face(std::vector<int> vect, unsigned char R, unsigned char G, unsigned char B, unsigned char A){
            id = std::move(vect);
            r = R;
            g = G;
            b = B;
            a = A;
        }

        const std::vector<int> &getId() const;

        void setId(const std::vector<int> &ID);

        unsigned char getR() const;

        void setR(unsigned char R);

        unsigned char getG() const;

        void setG(unsigned char G);

        unsigned char getB() const;

        void setB(unsigned char B);

        unsigned char getA() const;

        void setA(unsigned char A);

        std::string afficherInfo() const;

    private:
        std::vector<int> id;
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };


}



#endif //VISUALISATION_ZBUFFER_FACE_H
