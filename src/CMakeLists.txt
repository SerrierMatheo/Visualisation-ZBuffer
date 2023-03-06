cmake_minimum_required(VERSION 3.0)
project(Visualisation_ZBuffer)

set(CMAKE_CXX_STANDARD 20)

add_executable(Visualisation_ZBuffer main.cpp PlyObject3D.cpp PlyObject3D.h Vertex.cpp Vertex.h Face.cpp Face.h test/test.cpp ../Code_Exemple_SDL/infographie.cpp)
