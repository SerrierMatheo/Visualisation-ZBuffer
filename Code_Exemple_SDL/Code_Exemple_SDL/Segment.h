//
// Created by Stages on 06/03/2023.
//

#ifndef INFOGRAPHIE_SEGMENT_H
#define INFOGRAPHIE_SEGMENT_H

#include "donnees.h"
#include "base.h"

extern void DrawSegment(PointImage p1, PointImage p2, Couleur coul, SDL_Surface *image);

void TestSegment(SDL_Surface *image);

#endif //INFOGRAPHIE_SEGMENT_H
