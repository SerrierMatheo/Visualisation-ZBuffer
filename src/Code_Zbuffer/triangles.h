#ifndef TRIANGLES_H
#define TRIANGLES_H

#include <vector>
#include "donnees.h"
#include "base.h"

using namespace std;

void recupererPixelsTriangle(PointImage A, PointImage B, PointImage C, vector<PointImage> listePixels);

///////////////////////////////////////////
// Dessin d'un triangle défini par les pts
// et les couleurs spécifiés
// Arrêt au sommet centrale
///////////////////////////////////////////
extern void DemiTriangle(PointImage A, PointImage B, PointImage C, Couleur coul, SDL_Surface *image);

///////////////////////////////////////////
// Dessin d'un triangle défini par les pts
// et les couleurs spécifiés
///////////////////////////////////////////
extern void Triangle(vector<PointImage> &pts, vector<Couleur> &couls, SDL_Surface *image);

extern vector<PointImage> recupererPixels(vector<PointImage> &uv);

///////////////////////////////////////////
// Test de la fonction de dessin des courbes de Bézier
///////////////////////////////////////////
extern void TestTriangles(SDL_Surface *image);

#endif
