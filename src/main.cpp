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
    PlyObject3D obj("cubeNorm.ply");
    std::cout << obj.afficherInfo(1) << std::endl;
    obj.createFile("airplane2.ply");
    return 0;
}
