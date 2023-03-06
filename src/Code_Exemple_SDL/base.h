#ifndef BASE_H
#define BASE_H

#include "donnees.h"   // Structures de données

///////////////////////////////////////////
// Accès à un pixel d'une image (sans palette)
///////////////////////////////////////////
extern Couleur CouleurPixel (int c, int l, SDL_Surface *image);
inline Couleur CouleurPointImage (PointImage pi, SDL_Surface *image)
{
  return CouleurPixel(pi.col, pi.lig, image);
}

///////////////////////////////////////////
// Coloriage du pixel (x,y) avec la couleur coul
///////////////////////////////////////////
extern void ColoriePixel (int x, int y, Couleur coul, SDL_Surface *image);
inline void ColoriePointImage (PointImage pi, Couleur coul, SDL_Surface *image)
{
  ColoriePixel(pi.col, pi.lig, coul, image);
}

///////////////////////////////////////////
// Colorie tous les pixels selon la couleur spécifiée
///////////////////////////////////////////
extern void ColorieImage (Couleur coul, SDL_Surface *image);

///////////////////////////////////////////
// Mise à jour de l'image affichée
///////////////////////////////////////////
void MiseAJour (SDL_Surface *image);

#endif
