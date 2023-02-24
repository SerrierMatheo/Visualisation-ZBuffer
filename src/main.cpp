#include <iostream>
#include "Vertex.h"
#include "Face.h"
#include "PlyObject3D.h"
#include "fstream"

using namespace V;
using namespace F;
using namespace O;
using namespace std;

int main() {

    /**Vertex v(10,15,20);
    //std::cout << "Infomation du vertex v "<< std::endl;
    //v.afficherInfo();

    std::vector<int> vect;
    vect.reserve(5);
    for (int i = 1; i <= 3; ++i) {
        vect.push_back(i);
    }

    Face f(vect);
    std::cout << f.getIndex().size() << std::endl;
    for(int i = 0; i < f.getIndex().size(); i++){
        std::cout << f.getIndex()[i] << std::endl;
    }

    //--------------------------------------------------------------------------------------
    /**std::vector<Vertex> vVert;
    int x = 0;
    for (int i = 0; i < 40000; ++i) {
        Vertex vertex(x,x+1,x+2);
        vVert.push_back(vertex);
        x++;
    }

    std::vector<Face> vFace;
    for (int i = 0; i < 80000; ++i) {
        Face face(vect);
        vFace.push_back(face);
    }

    PlyObject3D plyObject3D("pyramide.ply");
    std::string resC = plyObject3D.afficherInfo(0);
    std::cout << "Infomation de l'objet : format court \n" + resC + "\n" << std::endl;
    std::string resL = plyObject3D.afficherInfo(1);
    std::cout << "Infomation de l'objet : format long \n" + resL + "\n" << std::endl;
    std::string resD = plyObject3D.afficherInfo(2);
    std::cout << "Infomation de l'objet : format erreur \n" + resD + "\n" << std::endl;
    */

    //-------------------------------------------------------------------------------------

    PlyObject3D obj("airplane.ply");
    std::cout << obj.afficherInfo(1) << std::endl;
    //obj.createFile("kerolamp2.ply");
    return 0;
}
