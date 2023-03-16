#ifndef TROISD_H
#define TROISD_H

#include "donnees.h"   // Structures de données
#include "matrices.h"  // Structures de matrices

///////////////////////////////////////////
// Types pour les objets 3D et la caméra
///////////////////////////////////////////
typedef struct { // Caméra
  Vec pos;           // Position 3D de la caméra
  Vec cible;         // Cible 3D visée par la caméra
  double echelle;    // Échelle d'affichage (nb pixels par unité du monde virtuel)
} Camera;

typedef struct { // Face d'un objet
  vector<int> points;    // Indices des sommets de la face
  vector<PointImage> uv; // Liste des coordonnées textures des sommets de la face
  Vec normale; // Normale à la face
  Couleur c; // couleur de la face
} Face;

typedef struct { // Objet complet
  Mat points;            // Liste des points 3D de l'objet
  vector<Face> faces;    // Liste des faces de l'objet
} Objet;

///////////////////////////////////////////
// Calcul de la matrice de la caméra
///////////////////////////////////////////
extern void matriceCamera(Camera &cam, Mat &mat, double echelle);

///////////////////////////////////////////
// Dessin d'un objet 3D
///////////////////////////////////////////
extern void dessineObjet(Objet &obj, Camera &cam, SDL_Surface *image);

///////////////////////////////////////////
// Construction d'une caisse 3D
///////////////////////////////////////////
extern void constructionCaisse(Objet &obj);

///////////////////////////////////////////
// Test des fonctions de dessin d'objets 3D
///////////////////////////////////////////
extern void Test3D(SDL_Surface *image);

#endif
