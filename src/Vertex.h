//
// Created by Serrier Mathéo on 21/02/2023.
//

#ifndef VISUALISATION_ZBUFFER_VERTEX_H
#define VISUALISATION_ZBUFFER_VERTEX_H

#include <string>

namespace V
{
/**
 * Classe vertex
 * définie le type d'objet vertex, correspond à un point dans un plan tridimensionnel pouvant être coloré
 * Possède 7 attributs
 * x, y et z correspond au coordonnées du point
 * r,g,b et a correspondant au valeur RGBA du point (couleur)
 */
    class Vertex {
    public:
        /**
         * Constructeur par défaut
         */
        Vertex(){
            x = 0;
            y = 0;
            z = 0;
            r = 0;
            g = 0;
            b = 0;
            a = 0;
        }

        /**
        * Constructeur paramétré 1
        * A utiliser si la coloration n'est pas définie
        * @param x correspond à l'abscisse du point
        * @param y correspond à l'ordonnée du point
        * @param z correspond à la profondeur du point
        */
        Vertex(double X, double Y, double Z){
            x = X;
            y = Y;
            z = Z;
            r = 0;
            g = 0;
            b = 0;
            a = 0;
        }

        /**
         * Constructeur paramétré 2
         * A utiliser si la couleur est définie
         * @param X
         * @param Y
         * @param Z
         * @param R
         * @param G
         * @param B
         * @param A
         */
        Vertex(double X, double Y, double Z, unsigned char R, unsigned char G, unsigned char B, unsigned char A){
            x = X;
            y = Y;
            z = Z;
            r = R;
            g = G;
            b = B;
            a = A;
        }

        double getX() const;

        double getY() const;

        double getZ() const;

        void setX(double x);

        void setY(double y);

        void setZ(double z);

        /**
         * permet d'afficher les informations d'une classe
         * valeur stocker dans les attributs
         */
        std::string afficherInfo() const;

    private:
        double x;
        double y;
        double z;
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;

    };




}

#endif //VISUALISATION_ZBUFFER_VERTEX_H
