//
// Created by Serrier Mathéo on 22/02/2023.
//

#include <fstream>
#include <sstream>
#include "ReadPlyFile.h"

/**PlyObject3D Lply::ReadPlyFile::ReadFile(string file) {
    PlyObject3D obj;
    string filePath = "../../Ressources/" + file;
    ifstream flow(filePath, ios::in);
    string s = "";

    if(!flow.is_open())
    {
        cerr << "ERROR : Could not open file " << file << endl;
        return obj;
    }
    else
    {
        string line;
        int num_Vertex = 0;
        int num_Faces = 0;
        bool read_header = false;
        while (getline(flow, line)){
            if(!read_header) {
                if(line == "end_header") {
                    read_header = true;
                } else if (line.substr(0,14) == "element vertex") {
                    num_Vertex = stoi(line.substr(15));
                } else if (line.substr(0,12) == "element face") {
                    num_Faces = stoi(line.substr(13));
                }
            } else {
                if (num_Vertex > 0) {
                    double x, y, z;
                    unsigned char r, g, b, a;
                    sscanf(line.c_str(), "%lf %lf %lf %hhu %hhu %hhu %hhu" , &x, &y, &z, &r, &g, &b, &a);
                    V::Vertex vertex(x,y,z,r,g,b,a);
                    obj.getV().push_back(vertex);
                    num_Vertex--;
                } else if (num_Faces > 0) {
                    int n = 0;
                    vector<int> vertex_indices;
                    unsigned char r, g, b, a;
                    stringstream stringS(line);
                    stringS >> n;
                    for (int i=0; i < n; i++) {
                        int index;
                        stringS >> index;
                        vertex_indices.push_back(index);
                    }
                    F::Face f(vertex_indices, r, g, b, a);
                    obj.getF().push_back(f);
                    num_Faces--;
                }
            }
        }
    }
    flow.close();
    return obj;

}*/
