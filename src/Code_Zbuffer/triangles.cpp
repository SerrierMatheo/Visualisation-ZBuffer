#include <cmath>
#include "triangles.h"
#include "formesSimples.h"
#include "Segment.h"
#include <unistd.h>
#include <iostream>




///////////////////////////////////////////
// Dessin d'un triangle défini par les pts
// et les couleurs spécifiés
// Arrêt au sommet central
///////////////////////////////////////////
void DemiTriangle(PointImage A, PointImage B, PointImage C, Couleur coul, SDL_Surface *image){
    //Met les points dans l'ordre croissant de lig
    PointImage AB, AC;
    AB.col = B.col - A.col;
    AB.lig = B.lig - A.lig;
    AC.col = C.col - A.col;
    AC.lig = C.lig - A.lig;

    if (AB.lig != 0){   //traitement du cas général où A n'est pas sur la même ligne que B
        int senslig = 1;    //Détermination du sens de parcours des lignes
        if (A.lig > B.lig){
            senslig = -1;
        }

        int l = 0;
        while(l != AB.lig+senslig){
            PointImage pAB,pAC;
            pAB.col = A.col + AB.col * l / AB.lig;   //Point courant sur AB
            pAB.lig = A.lig + l;
            pAC.col = A.col + AC.col * l / AC.lig;   //Point courant sur AC
            pAC.lig = pAB.lig;

            DrawSegment(pAB, pAC, coul, image); //Dessin du segment horizontal de pAB à pAC
            l = l + senslig;   //Passage à la ligne suivante
        }
    } else {    //traitement du cas particulier où A est sur la même ligne que B
        DrawSegment(A, B, coul, image);
    }
}

vector<PointImage> recupererPixelsTriangle(PointImage A, PointImage B, PointImage C){
    vector<PointImage> listePixels;

    //Met les points dans l'ordre croissant de lig
    PointImage AB, AC;
    AB.col = B.col - A.col;
    AB.lig = B.lig - A.lig;
    AC.col = C.col - A.col;
    AC.lig = C.lig - A.lig;

    if (AB.lig != 0){   //traitement du cas général où A n'est pas sur la même ligne que B
        int senslig = 1;    //Détermination du sens de parcours des lignes
        if (A.lig > B.lig){
            senslig = -1;
        }

        int l = 0;
        while(l != AB.lig+senslig){
            PointImage pAB,pAC;
            pAB.col = A.col + AB.col * l / AB.lig;   //Point courant sur AB
            pAB.lig = A.lig + l;
            pAC.col = A.col + AC.col * l / AC.lig;   //Point courant sur AC
            pAC.lig = pAB.lig;

            vector<PointImage> ligne = recupererPixelsLigne(pAB, pAC);
            listePixels.insert(listePixels.end(), ligne.begin(), ligne.end());
            //DrawSegment(pAB, pAC, coul, image); //Dessin du segment horizontal de pAB à pAC
            l = l + senslig;   //Passage à la ligne suivante
        }
    } else {    //traitement du cas particulier où A est sur la même ligne que B
        vector<PointImage> ligne = recupererPixelsLigne(A, B);
        listePixels.insert(listePixels.end(), ligne.begin(), ligne.end());
        //DrawSegment(A, B, coul, image);
    }
    return listePixels;
}

///////////////////////////////////////////
// Dessin d'un triangle défini par les pts
// et les couleurs spécifiés
///////////////////////////////////////////
void Triangle(vector<PointImage> &pts, vector<Couleur> &couls, SDL_Surface *image)
{
  // À COMPLÉTER !!
    PointImage haut = pts[0];
    PointImage bas = pts[1];
    PointImage milieu = pts[2];

    bool sort = true;
    //traiter le cas ou un côté est horizontal
    if((haut.lig == milieu.lig) || (haut.lig == bas.lig) || (milieu.lig == bas.lig)){
        sort = false;
    }

    while (sort){
        if(((haut.lig < milieu.lig) && (haut.lig < bas.lig)) && ((bas.lig > haut.lig) && (bas.lig > milieu.lig)))
            break;
        if ((haut.lig > milieu.lig) && (haut.lig > bas.lig)) {
            // haut.lig est le plus grand
            std::swap(haut.lig, bas.lig);
            std::swap(haut.col, bas.col);
        } else if ((bas.lig < haut.lig) && (bas.lig < milieu.lig)) {
            // bas.lig est le plus petit
            std::swap(haut.lig, bas.lig);
            std::swap(haut.col, bas.col);
        } else {
            // milieu.lig est le milieu
            std::swap(haut.lig, milieu.lig);
            std::swap(haut.col, milieu.col);
        }
    }

    DrawSegment(milieu, haut, couls[0], image);
    DrawSegment(milieu, bas, couls[0], image);
    DrawSegment(haut, bas, couls[0], image);


    //si haut.lig = milieu.lig
    if(haut.lig == milieu.lig){
        DemiTriangle(bas, milieu, haut, couls[0], image);
    }else if(bas.lig == milieu.lig){
        DemiTriangle(haut, milieu, bas, couls[0], image);
    }else if(haut.lig == bas.lig){
        std::swap(bas,milieu);
        if(bas.lig < haut.lig){
            swap(bas,haut);
            DemiTriangle(haut,milieu,bas, couls[0], image);
        }else{
            DemiTriangle(bas, milieu, haut, couls[0], image);
        }
    }else{
        DemiTriangle(haut, milieu, bas, couls[0], image);
        DemiTriangle(bas, milieu, haut, couls[0], image);
    }
}

vector<PointImage> recupererPixels(vector<PointImage> &uv){
    vector<PointImage> listePixels;

    PointImage haut = uv[0];
    PointImage bas = uv[1];
    PointImage milieu = uv[2];

    bool sort = true;
    //traiter le cas ou un côté est horizontal
    if((haut.lig == milieu.lig) || (haut.lig == bas.lig) || (milieu.lig == bas.lig)){
        sort = false;
    }

    while (sort){
        if(((haut.lig < milieu.lig) && (haut.lig < bas.lig)) && ((bas.lig > haut.lig) && (bas.lig > milieu.lig)))
            break;
        if ((haut.lig > milieu.lig) && (haut.lig > bas.lig)) {
            // haut.lig est le plus grand
            std::swap(haut.lig, bas.lig);
            std::swap(haut.col, bas.col);
        } else if ((bas.lig < haut.lig) && (bas.lig < milieu.lig)) {
            // bas.lig est le plus petit
            std::swap(haut.lig, bas.lig);
            std::swap(haut.col, bas.col);
        } else {
            // milieu.lig est le milieu
            std::swap(haut.lig, milieu.lig);
            std::swap(haut.col, milieu.col);
        }
    }

    vector<PointImage> ligne = recupererPixelsLigne(milieu, haut);
    listePixels.insert(listePixels.end(), ligne.begin(), ligne.end());

    ligne = recupererPixelsLigne(milieu, bas);
    listePixels.insert(listePixels.end(), ligne.begin(), ligne.end());

    ligne = recupererPixelsLigne(haut, bas);
    listePixels.insert(listePixels.end(), ligne.begin(), ligne.end());

    //si haut.lig = milieu.lig
    if(haut.lig == milieu.lig){
        ligne = recupererPixelsTriangle(bas, milieu, haut);
        listePixels.insert(listePixels.end(), ligne.begin(), ligne.end());
    }else if(bas.lig == milieu.lig){
        ligne = recupererPixelsTriangle(haut, milieu, bas);
        listePixels.insert(listePixels.end(), ligne.begin(), ligne.end());
    }else if(haut.lig == bas.lig){
        std::swap(bas,milieu);
        if(bas.lig < haut.lig){
            swap(bas,haut);
            ligne = recupererPixelsTriangle(haut, milieu, bas);
            listePixels.insert(listePixels.end(), ligne.begin(), ligne.end());
        }else{
            ligne = recupererPixelsTriangle(bas, milieu, haut);
            listePixels.insert(listePixels.end(), ligne.begin(), ligne.end());
        }
    }else{
        //DemiTriangle(haut, milieu, bas, couls[0], image);
        ligne = recupererPixelsTriangle(haut, milieu, bas);
        listePixels.insert(listePixels.end(), ligne.begin(), ligne.end());
        //DemiTriangle(bas, milieu, haut, couls[0], image);
        ligne = recupererPixelsTriangle(bas, milieu, haut);
        listePixels.insert(listePixels.end(), ligne.begin(), ligne.end());
    }

    return listePixels;
}

///////////////////////////////////////////
// Test de la fonction de dessin des triangles pleins
///////////////////////////////////////////
void TestTriangles(SDL_Surface *image)
{
  vector<PointImage> pts;          // Liste des points 
  vector<PointImage> ptex1, ptex2; // Liste des points avec texturage
  vector<PointImage> ctex1, ctex2; // Liste des coordonnées de textures des points
  vector<Couleur> couls;           // Liste des couleurs
  static float t1 = -M_PI, t2 = t1 + 2 * M_PI / 3, t3 = t2 + 2 * M_PI / 3;
    
  // Init liste des points
  pts.resize(3);
  ptex1.resize(3);
  ctex1.resize(3);
  ptex2.resize(3);
  ctex2.resize(3);

  // Init liste des couleurs
  couls.resize(3);
  //couls[0] = {255, 0, 0, 0};
  couls[0].R = 255;
  couls[0].V = 0; 
  couls[0].B = 0; 
  couls[0].A = 0;
  //couls[1] = {0, 255, 0, 0};
  couls[1].R = 0;
  couls[1].V = 255;
  couls[1].B = 0; 
  couls[1].A = 0;
  //couls[2] = {0, 0, 255, 0};
  couls[2].R = 0;
  couls[2].V = 0; 
  couls[2].B = 255; 
  couls[2].A = 0;

  // Parcours de 3 cercles qui déterminent les déplacements des 3 sommets
  pts[0].col = (int)rint(400 + 250 * cos(t1));
  pts[0].lig = (int)rint(500 + 250 * sin(t1));
  pts[1].col = (int)rint(400 + 250 * cos(t2));
  pts[1].lig = (int)rint(500 + 250 * sin(t2));
  pts[2].col = (int)rint(400 + 250 * cos(t3));
  pts[2].lig = (int)rint(500 + 250 * sin(t3));

  Triangle(pts, couls, image);

  // Mise à jour des angles
  t1 += 0.01;
  t2 += 0.01;
  t3 += 0.01;
}
