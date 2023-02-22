//
// Created by Serrier Mathéo on 22/02/2023.
//

#ifndef VISUALISATION_ZBUFFER_READPLYFILE_H
#define VISUALISATION_ZBUFFER_READPLYFILE_H
#include "PlyObject3D.h"

using namespace O;
using namespace std;

namespace Lply
{
    class ReadPlyFile {
    public:
        static PlyObject3D ReadFile(string file);
    };
}

#endif //VISUALISATION_ZBUFFER_READPLYFILE_H
