#ifndef FORMESSIMPLES_H
#define FORMESSIMPLES_H

#include "donnees.h"
#include "base.h"

///////////////////////////////////////////
// Dessin d'un rectangle de couleur coul
// défini par sa diagonale AB
///////////////////////////////////////////
extern void RectanglePlein(PointImage A, PointImage B, Couleur coul, SDL_Surface *image);

///////////////////////////////////////////
// Dessin du disque de couleur coul
// et de centre et rayon spécifiés
///////////////////////////////////////////
extern void Disque(PointImage centre, int rayon, Couleur coul, SDL_Surface *image);

///////////////////////////////////////////
// Fonction de test des fonctions de dessin des formes simples
///////////////////////////////////////////
extern void FormesSimples(SDL_Surface *image);

#endif
