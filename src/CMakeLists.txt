cmake_minimum_required(VERSION 3.0)
project(Visualisation_ZBuffer)
aux_source_directory(. SRC_LIST)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} ${SRC_LIST} Code_Exemple_SDL/Object3D.cpp Code_Exemple_SDL/Object3D.h Code_Exemple_SDL/Vertex.cpp Code_Exemple_SDL/Vertex.h Code_Exemple_SDL/Face.cpp Code_Exemple_SDL/Face.h)

FIND_PACKAGE(SDL REQUIRED)
if ( SDL_FOUND )
    message(SDL_FOUND >>>>> ${SDL_INCLUDE_DIRS})
endif()
INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIRS})
LINK_DIRECTORIES(${SDL_LIBRARY_DIRS})

add_definitions(-g)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL_LIBRARIES})