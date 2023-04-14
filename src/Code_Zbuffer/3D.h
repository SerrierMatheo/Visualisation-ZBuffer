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
  vector<Couleur> c; // couleur de la face
} Face;

typedef struct { // Objet complet
  Mat points;            // Liste des points 3D de l'objet
  vector<Face> faces;    // Liste des faces de l'objet
} Objet;

static const Couleur BLANC = {255, 255, 255, 0};

extern vector<PointImage> ProjectObjet(Objet obj, Mat &matProj, SDL_Surface *image);

///////////////////////////////////////////
// Calcul de la matrice de la caméra
///////////////////////////////////////////
extern void matriceCamera(Camera &cam, Mat &mat, double echelle);

///////////////////////////////////////////
// Dessin (toutes les faces) d'un objet 3D
///////////////////////////////////////////
extern void dessineObjetBase(Objet &obj, Mat &matProj, SDL_Surface *image);

///////////////////////////////////////////
// Dessin (uniquement face visible) d'un objet 3D
///////////////////////////////////////////
extern void dessineObjet(Objet &obj, Mat &matProj, Camera &cam, Etat &etat);

///////////////////////////////////////////
// Dessin (à l'aide du ZBuffer) d'un objet 3D
///////////////////////////////////////////
extern void dessineObjetZbuffer(Objet &obj, Mat &matProj, Camera &cam, Etat &etat);

///////////////////////////////////////////
// Construction d'une caisse 3D
///////////////////////////////////////////
extern void constructionCaisse(Objet &obj);

///////////////////////////////////////////
// Test des fonctions de dessin d'objets 3D
///////////////////////////////////////////
extern void Test3D(SDL_Surface *image);

///////////////////////////////////////////
// permet l'affichage d'objet 3D
///////////////////////////////////////////
extern void AfficherObjet(Etat &etat, Objet obj);

///////////////////////////////////////////
// calcul le barycentre d'une face triangulaire
///////////////////////////////////////////
vector<double> computeBarycenter(vector<double> vertexA, vector<double> vertexB, vector<double> vertexC);

///////////////////////////////////////////
// implémente le backface culling
///////////////////////////////////////////
vector<Face> backfaceCulling(Objet obj, Camera cam);

///////////////////////////////////////////
// Calcul et rempli le zbuffer et les couleurs des pixels d'une scène
///////////////////////////////////////////
void zBuffer(Objet obj, Camera cam, int hauteur, int largeur, double** tampon, Couleur** couleurs);

///////////////////////////////////////////
// permet de récupérer les coords 3D d'un pixel P
///////////////////////////////////////////
Mat interpolation(vector<PointImage> uv, vector<Vec> sommets, PointImage p);

///////////////////////////////////////////
// calcul la distance entre 2 points 3D
///////////////////////////////////////////
double length(double x1, double y1, double z1, double x2, double y2, double z2);

#endif
