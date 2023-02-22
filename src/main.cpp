#include <iostream>
#include "Vertex.h"
#include "Face.h"
#include "PlyObject3D.h"
#include "fstream"
#include "ReadPlyFile.h"

using namespace V;
using namespace F;
using namespace O;
using namespace Lply;
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
    //std::cout << "Infomation de la face f "<< std::endl;
    //f.afficherInfo();

    //--------------------------------------------------------------------------------------
    std::vector<Vertex> vVert;
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

    PlyObject3D plyObject3D(vVert, vFace);
    std::string resC = plyObject3D.afficherInfo(0);
    std::cout << "Infomation de l'objet : format court \n" + resC + "\n" << std::endl;
    std::string resL = plyObject3D.afficherInfo(1);
    std::cout << "Infomation de l'objet : format long \n" + resL + "\n" << std::endl;
    std::string resD = plyObject3D.afficherInfo(2);
    std::cout << "Infomation de l'objet : format erreur \n" + resD + "\n" << std::endl;
    */

    //-------------------------------------------------------------------------------------

    PlyObject3D obj = ReadPlyFile::ReadFile("test.ply");

    return 0;
}
