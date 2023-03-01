//
// Created by Serrier Mathéo on 21/02/2023.
//

#ifndef VISUALISATION_ZBUFFER_PLYOBJECT3D_H
#define VISUALISATION_ZBUFFER_PLYOBJECT3D_H

#include "Vertex.h"
#include "Face.h"
#include "vector"
#include "iostream"

namespace O
{
/**
 * Classe PlyObject3D
 * définie un objet 3D
 */
    class PlyObject3D {

    public:
        PlyObject3D();

        PlyObject3D(std::string filename);

        std::string afficherInfo(int size) const;

        void createFile(std::string fileName);

        const std::vector<V::Vertex> & getV() const;

        void setV(const std::vector<V::Vertex> &vert);

        bool isColV() const;

        void setColV(bool cV);

        const std::vector<F::Face> & getF() const;

        void setF(const std::vector<F::Face> &face);

        bool isColF() const;

        void setColF(bool cF);

        V::Vertex cross(V::Vertex v1, V::Vertex v2);

        V::Vertex normalize(V::Vertex w);

        void computeFaceNormals();

        void flipOrientation();

    private:
        std::vector <V::Vertex> v;
        bool colV;
        std::vector <F::Face> f;
        bool colF;
        //correspond à la liste des normales calculer
        std::vector <V::Vertex> n;
    };
}




#endif //VISUALISATION_ZBUFFER_PLYOBJECT3D_H
