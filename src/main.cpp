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
    Vertex v(10,15,20);
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
    /**std::string resC = plyObject3D.afficherInfo(0);
    std::cout << "Infomation de l'objet : format court \n" + resC + "\n" << std::endl;
    std::string resL = plyObject3D.afficherInfo(1);
    std::cout << "Infomation de l'objet : format long \n" + resL + "\n" << std::endl;
    std::string resD = plyObject3D.afficherInfo(2);
    std::cout << "Infomation de l'objet : format erreur \n" + resD + "\n" << std::endl;
    */

    //-------------------------------------------------------------------------------------

    //TODO 
    ifstream file("../../Ressources/test.ply", ios::in);
    std::string s = "";

    if(file)
    {
        string ligne;
        printf("Ligne pas ligne\n");
        while(getline(file, ligne))
            s += ligne + " \n";
        printf("mot par mot\n");
        file.clear();
        file.seekg(0, ios::beg);
        string mot;
        while(file >> mot)
            cout << mot << endl;
        printf("caractere par caractere\n");
        file.clear();
        file.seekg(0, ios::beg);
        char c;
        while(file.get(c))
        {
            cout << c << endl;
            int pos = file.tellg();
        }
        file.close();
    }
    else
        cout << "Impossible d'ouvrir le fichier !" << endl;

    std::cout << s << std::endl;
    return 0;
}
