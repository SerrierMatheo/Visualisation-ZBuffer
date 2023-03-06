#include <cmath>
#include <chrono>
#include <iostream>
#include "formesSimples.h"

///////////////////////////////////////////
// Dessin d'un rectangle défini par la diagonale AB
// et rempli avec la couleur coul
///////////////////////////////////////////
void RectanglePlein(PointImage A, PointImage B, Couleur coul, SDL_Surface *image)
{
  //>>>>>>>>>> À COMPLÉTER <<<<<<<<<<
    int x1 = A.col;
    int x2 = B.col;
    int y1 = A.lig;
    int y2 = B.lig;

    //Inverse les points si mal placé
    if(x1 > x2 && y1 > y2){
        x1 = B.col;
        x2 = A.col;
        y1 = B.lig;
        y2 = A.lig;
    }
    if (x1 < x2 && y1 > y2){
        y1 = B.lig;
        y2 = A.lig;
    }
    if (x1 > x2 && y1 < y2){
        x1 = B.col;
        x2 = A.col;
    }
    //Boucle sur les col et lig et dessine le pixel
    for (int i = x1; i <= x2 ; ++i) {
        for (int j = y1; j <= y2; ++j) {
            ColoriePixel(i,j,coul,image);
        }
    }
}

void DisqueNaif(PointImage centre, int rayon, Couleur coul, SDL_Surface *image) {
    auto start = std::chrono::high_resolution_clock::now();

    //Encadre le cercle
    int x1 = centre.col - rayon;
    int y1 = centre.lig - rayon;
    int x2 = centre.col + rayon;
    int y2 = centre.lig + rayon;

    //parcour dans le carré de côté 2*rayon
    for (int i = x1; i <= x2; ++i){
        for (int j = y1; j <= y2; ++j){
            //Calculer la distance entre 2 points
            //si distance <= r, allume le pixel
            double distance;
            distance = sqrt(pow(i - centre.col, 2) + pow(j - centre.lig, 2));
            if(distance <= rayon){
                ColoriePixel(i,j,coul,image);
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Temps d'execution naif : " << duration.count() << " nanoseconds" << std::endl;
}


void Cercle(PointImage centre, int rayon, Couleur coul, SDL_Surface *image){

    //Dessinbe un cerlce à l'aide de l'algorithme de Bresenham
    int x = rayon;
    int y = 0;
    int radiusError = 1 - x;

    while (x >= y) {
        ColoriePixel(centre.col + x, centre.lig + y, coul, image);
        ColoriePixel(centre.col + y, centre.lig + x, coul, image);
        ColoriePixel(centre.col - y, centre.lig + x, coul, image);
        ColoriePixel(centre.col - x, centre.lig + y, coul, image);
        ColoriePixel(centre.col - x, centre.lig - y, coul, image);
        ColoriePixel(centre.col - y, centre.lig - x, coul, image);
        ColoriePixel(centre.col + y, centre.lig - x, coul, image);
        ColoriePixel(centre.col + x, centre.lig - y, coul, image);

        y++;
        if (radiusError < 0) {
            radiusError += 2 * y + 1;
        }
        else {
            x--;
            radiusError += 2 * (y - x) + 1;
        }
    }
}

///////////////////////////////////////////
// Dessin d'un disque rempli avec la couleur coul
///////////////////////////////////////////
void Disque(PointImage centre, int rayon, Couleur coul, SDL_Surface *image)
{
    auto start = std::chrono::high_resolution_clock::now();
  //>>>>>>>>>> À COMPLÉTER <<<<<<<<<<
    int x = 0;
    int y = rayon;
    int radiusError = 1 - y;

    while (x <= y) {
        for (int i = centre.col - x; i <= centre.col + x; i++) {
            ColoriePixel(i, centre.lig + y, coul, image);
            ColoriePixel(i, centre.lig - y, coul, image);
        }
        for (int i = centre.col - y; i <= centre.col + y; i++) {
            ColoriePixel(i, centre.lig + x, coul, image);
            ColoriePixel(i, centre.lig - x, coul, image);
        }

        x++;
        if (radiusError < 0) {
            radiusError += 2 * x + 1;
        }
        else {
            y--;
            radiusError += 2 * (x - y) + 1;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Temps d'execution bresenham : " << duration.count() << " nanoseconds" << std::endl;
}

///////////////////////////////////////////
// Test des fonctions de dessin des formes simples
///////////////////////////////////////////
void FormesSimples(SDL_Surface *image)
{
  // Sommets des rectangles
  PointImage A = {10, 10};
  PointImage B = {50, 50};
  PointImage C = {100, 10};
  PointImage D = {300, 50};
  PointImage E = {10, 100};
  PointImage F = {50, 300};
  PointImage G = {200, 200};
  PointImage H = {850, 500};

  // Couleurs
  Couleur rouge = {255, 0, 0, 0};
  Couleur vert  = {0, 255, 0, 0};
  Couleur bleu  = {0, 0, 255, 0};

  // Trois rectangles
  RectanglePlein(A, B, rouge, image);
  RectanglePlein(C, D, vert, image);
  RectanglePlein(E, F, bleu, image);

  // Deux disques
  DisqueNaif(G, 50, bleu, image);
  Disque(H, 150, vert, image);
}
