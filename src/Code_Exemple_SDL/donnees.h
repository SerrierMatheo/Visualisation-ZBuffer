#ifndef DONNEES_H
#define DONNEES_H

#include <SDL.h>       // Bibliothèque d'affichage 2D
#include <SDL_image.h> // Bibliothèque SDL image

///////////////////////////////////////////
// Énumération des différents affichages au cours des TPs successifs
///////////////////////////////////////////
typedef enum {FORMESSIMPLES=0, SEGMENTS, TRIANGLES, NBACTIONS} Action;

///////////////////////////////////////////
// Types de couleurs
///////////////////////////////////////////
typedef unsigned char octet; // Codage d'une composante 
                             // de base sur un octet
typedef struct {             // Structure de couleur
  octet R, V, B, A;          // composée des 3 bases + le canal alpha
} Couleur;                   // Nom du type couleur

typedef struct {             // Structure de couleur
  double H, S, L, A;         // composée des 3 bases + le canal alpha
} HSL;                       // Nom du type avec codage HSL

typedef struct {             // Structure de couleur
  double H, S, V, A;         // composée des 3 bases + le canal alpha
} HSV;                       // Nom du type avec codage HSV

///////////////////////////////////////////
// Types de points
///////////////////////////////////////////
typedef struct {             // Structure d'un point image
  int col, lig;              // Coordonnées colonne et ligne dans l'image
} PointImage;

typedef struct {             // Structure d'un point réel
  double x, y;               // Coordonnées x et y dans le plan réel
} PointReel;

///////////////////////////////////////////
// Structure pour les infos globales du programme
///////////////////////////////////////////
typedef struct { // Structure de l'état global
  SDL_Surface *image; // Image à afficher
  SDL_Event evt;      // Événement SDL (hors cadre du cours)
  int Largeur;        // Nombre de colonnes de l'image
  int Hauteur;        // Nombre de lignes de l'image
  int action;         // Indique quelle est l'action courante à effectuer
  int nbActions;      // Nombre d'actions d'affichage valides
  bool dejaFait;      // Indique si tracé déjà fait ou non
} Etat;

#endif
