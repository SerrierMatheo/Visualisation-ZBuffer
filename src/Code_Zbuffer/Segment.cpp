//
// Created by Stages on 06/03/2023.
//
#include <cmath>
#include "Segment.h"
#include <vector>

void recupererPixelsLigne(PointImage p1, PointImage p2, std::vector<PointImage> listePixelsFace){
    // Calculer le delta en x et en y
    int dx = abs(p2.col - p1.col);
    int dy = abs(p2.lig - p1.lig);

    // Calculer les pas en x et en y
    int sx = (p1.col < p2.col) ? 1 : -1;
    int sy = (p1.lig < p2.lig) ? 1 : -1;

    // Initialiser l'erreur
    int err = dx - dy;

    // Boucler sur chaque pixel du segment
    while (true) {
        // Dessiner le pixel courant
        //ColoriePixel(p1.col, p1.lig, coul, image);
        listePixelsFace.push_back(p1);

        // Vérifier si on a atteint la fin du segment
        if (p1.col == p2.col && p1.lig == p2.lig) {
            break;
        }

        // Calculer l'erreur pour le prochain pixel
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            p1.col += sx;
        }
        if (e2 < dx) {
            err += dx;
            p1.lig += sy;
        }
    }
}

void DrawSegment(PointImage p1, PointImage p2, Couleur coul, SDL_Surface *image) {
    // Calculer le delta en x et en y
    int dx = abs(p2.col - p1.col);
    int dy = abs(p2.lig - p1.lig);

    // Calculer les pas en x et en y
    int sx = (p1.col < p2.col) ? 1 : -1;
    int sy = (p1.lig < p2.lig) ? 1 : -1;

    // Initialiser l'erreur
    int err = dx - dy;

    // Boucler sur chaque pixel du segment
    while (true) {
        // Dessiner le pixel courant
        ColoriePixel(p1.col, p1.lig, coul, image);

        // Vérifier si on a atteint la fin du segment
        if (p1.col == p2.col && p1.lig == p2.lig) {
            break;
        }

        // Calculer l'erreur pour le prochain pixel
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            p1.col += sx;
        }
        if (e2 < dx) {
            err += dx;
            p1.lig += sy;
        }
    }
}


void TestSegment(SDL_Surface *image)
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
    DrawSegment(A, B, rouge, image);
    DrawSegment(C, D, vert, image);
    DrawSegment(E, F, bleu, image);

}