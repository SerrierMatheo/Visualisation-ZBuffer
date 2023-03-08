#include "base.h"

///////////////////////////////////////////
// Accès à un pixel d'une image
///////////////////////////////////////////
Couleur CouleurPixel (int c, int l, SDL_Surface *image)
{
  Couleur coul;
  // Tests de validité de la position (x,y) -> à l'intérieur de la fenêtre
  if(c>=0 && c<image->w && l>=0 && l<image->h){
    // Affichage du pixel en SDL avec la couleur spécifiée (hors cadre du cours)
    Uint8 *pixmem8 = (Uint8*) image->pixels  + l * image->pitch + c * image->format->BytesPerPixel;
    SDL_GetRGBA(*((Uint32 *)pixmem8), image->format, &(coul.R), &(coul.V), &(coul.B), &(coul.A));
    coul.A = 255 - coul.A;
  }
  return coul;
}

///////////////////////////////////////////
// Coloriage du pixel (c,l) avec la couleur coul
///////////////////////////////////////////
void ColoriePixel (int c, int l, Couleur coul, SDL_Surface *image)
{
  // Tests de validité de la position (c,l) -> à l'intérieur de la fenêtre
  if(c>=0 && c<image->w && l>=0 && l<image->h){
    // Affichage du pixel en SDL avec la couleur spécifiée (hors cadre du cours)
    Uint8 *pixmem8 = (Uint8*) image->pixels  + l * image->pitch + c * image->format->BytesPerPixel;
    if(coul.A > 0){
      Couleur prec;
      SDL_GetRGBA(*((Uint32 *)pixmem8), image->format, &(prec.R), &(prec.V), &(prec.B), &(prec.A));
      prec.R = (coul.A * prec.R + (255 - coul.A) * coul.R) / 255;
      prec.V = (coul.A * prec.V + (255 - coul.A) * coul.V) / 255;
      prec.B = (coul.A * prec.B + (255 - coul.A) * coul.B) / 255;
      *((Uint32 *)pixmem8) = SDL_MapRGBA(image->format, prec.R, prec.V, prec.B, 255 - prec.A);
    }else{
      *((Uint32 *)pixmem8) = SDL_MapRGBA(image->format, coul.R, coul.V, coul.B, 255 - coul.A);
    }
  }
}

///////////////////////////////////////////
// Colorie tous les pixels selon la couleur spécifiée
///////////////////////////////////////////
void ColorieImage (Couleur coul, SDL_Surface *image)
{
  SDL_FillRect(image, NULL, SDL_MapRGBA(image->format, coul.R, coul.V, coul.B, 255 - coul.A));
}

///////////////////////////////////////////
// Mise à jour de l'image affichée
///////////////////////////////////////////
void MiseAJour (SDL_Surface *image)
{
  // Déblocage de l'image pour pouvoir l'afficher
  if(SDL_MUSTLOCK(image)){
    SDL_UnlockSurface(image);
  }
  // Mise à jour de l'affichage de la fenêtre SDL
  SDL_Flip(image);
  // Bloquage de l'affichage de l'image pour pouvoir écrire dedans
  if(SDL_MUSTLOCK(image)){
    SDL_LockSurface(image);
  }
}

