//
// Created by Stages on 06/03/2023.
//

#ifndef INFOGRAPHIE_SEGMENT_H
#define INFOGRAPHIE_SEGMENT_H

#include "donnees.h"
#include "base.h"
#include <vector>

extern void DrawSegment(PointImage p1, PointImage p2, Couleur coul, SDL_Surface *image);

extern std::vector<PointImage> recupererPixelsLigne(PointImage p1, PointImage p2);

void TestSegment(SDL_Surface *image);

#endif //INFOGRAPHIE_SEGMENT_H
