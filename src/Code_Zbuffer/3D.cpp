#include <math.h>
#include "3D.h"
#include "triangles.h"
#include "formesSimples.h"
#include "Segment.h"

///////////////////////////////////////////
// Calcul de la matrice projetant les points 
// du monde dans le repère de la caméra
///////////////////////////////////////////
void matriceMondeVersCamera(Camera &cam, Mat &mat)
{
  Vec Xc(3), Yc(3), Zc(3); // Vecteurs unitaires du repère caméra
  Vec verticale(3,0);      // Vecteur 3D donnant la verticale du monde virtuel
  Vec CO;                  // Vecteur allant du centre de la caméra à l'origine du monde virtuel
  Vec O (3, 0);
  Vec C (3, 0);
  C[0] = cam.pos[0];
  C[1] = cam.pos[1];
  C[2] = cam.pos[2];

  //>>>>>>>>>> À COMPLÉTER <<<<<<<<<<
  //CHAQUE PARTIE INDIQUÉE CI-DESSOUS

  // Vecteur CO (verticale est le vecteur nul à ce stade)
  vecDiff(O,C,CO);

    // La verticale du monde virtuel est unitaire sur l'axe Z
    verticale[2] = 1.0;

    // Axe Z caméra
    vecDiff(C,cam.cible,Zc);
    normalisation(Zc);

    // Axe X caméra
    prodVec(verticale, Zc, Xc);
    normalisation(Xc);

    // Axe Y caméra
    prodVec(Zc, Xc, Yc);
    normalisation(Yc);

    // Remplissage de la matrice
    identite(mat);

    for (int i = 0; i < 3; i++) {
        mat[i][0] = Xc[i];
        mat[i][1] = Yc[i];
        mat[i][2] = Zc[i];
    }
    mat[3][0]=prodScal(Xc, cam.pos);
    mat[3][1]=prodScal(Yc, cam.pos);
    mat[3][2]=prodScal(Zc, cam.pos);

    matCoef(mat,cam.echelle);
}

///////////////////////////////////////////
// Position finale dans l'image 
// d'un point exprimé dans le repère caméra
///////////////////////////////////////////
void positionDansImage(Vec &ptCamera, PointImage &pi, SDL_Surface *image)
{
  //>>>>>>>>>> À COMPLÉTER <<<<<<<<<<
  // Positionnement final du point dans l'image
  // sachant que le centre optique est au centre de l'image
  //Centre d'image = cam
  //Déplacement de ptCam avec cam = pi
  Vec cam(2);
  cam[0] = image->w/2;
  cam[1] = image->h/2;

  pi.col = (int)(ptCamera[0] + cam[0]);
  pi.lig = (int)(ptCamera[1] + cam[1]);
}

///////////////////////////////////////////
// Dessin de 4 points indiquant l'origine du repère et les 3 points unitaires
///////////////////////////////////////////
void dessineRepere(Mat &matProj, SDL_Surface *image)
{
  Vec pt(4);                          // Point projeté
  vector<Vec> pts3D(4);               // Liste des 4 points dans le monde virtuel
  vector<PointImage> lstPts(4);       // Liste des 4 points dans l'image
  Couleur blanc = {255, 255, 255, 0}; // Couleurs pour les traits et points
  Couleur rouge = {255, 0, 0, 0};
  Couleur vert  = {0, 255, 0, 0};
  Couleur bleu  = {0, 0, 255, 0};

  // Construction des 4 points dans le monde virtuel
  for(int i=0; i<4; i++){
    pts3D[i].resize(4, 0);
    if(i>0){
      pts3D[i][i-1] = 1; // Unité de l'axe courant
    }
    pts3D[i][3] = 1;
  }

  // Projection des sommets de l'objet
  for(size_t i=0; i<pts3D.size(); ++i){ // Parcours des points
    // Projection du point dans le repère caméra
    projection(matProj, pts3D[i], pt);
    positionDansImage(pt, lstPts[i], image);
  }

  // Dessin des 4 points
  Disque(lstPts[0], 5, blanc, image); // Origine
  Disque(lstPts[1], 5, rouge, image); // X
  Disque(lstPts[2], 5, vert, image);  // Y
  Disque(lstPts[3], 5, bleu, image);  // Z

    DrawSegment(lstPts[0],lstPts[1],blanc,image);
}

///////////////////////////////////////////
// Dessin d'un objet 3D
///////////////////////////////////////////
//TODO Dessiner les segments entre les points
void dessineObjet(Objet &obj, Mat &matProj, SDL_Surface *image)
{
  Vec pt;                    // Point projeté
  vector<PointImage> lstPts; // Liste des points dans l'image
  PointImage pts[3];         // Liste des sommets d'un triangle à afficher dans l'image
  PointImage uv[3];          // Liste des coords UV des sommets du triangle
  Couleur blanc = {255, 255, 255, 0}; // Couleurs pour les traits et points

  // Projection des sommets de l'objet
  pt.resize(4);
  lstPts.resize(obj.points.size());
  for(size_t i=0; i<obj.points.size(); ++i){ // Parcours des points
    // Projection du point dans le repère caméra
    projection(matProj, obj.points[i], pt);
    positionDansImage(pt, lstPts[i], image);
  }

  // Parcours des faces
  for(size_t i=0; i<obj.faces.size(); ++i){
    bool aFaire = true; // Booléen utiliser pour indiquer si l'on doit afficher la face ou non
    //>>>>>>>>>> À COMPLÉTER <<<<<<<<<<

    if(aFaire){
      //>>>>>>>>>> À MODIFIER <<<<<<<<<<
      
      // Parcours des sommets
      for(size_t j=0; j<obj.faces[i].points.size(); ++j){
        int indA = obj.faces[i].points[j];
        // Coloriage du sommet courant avec un point de rayon 5 pixels
        Disque(lstPts[indA], 5, blanc, image);
      }
    }
  }
}

///////////////////////////////////////////
// Construction d'une caisse 3D
///////////////////////////////////////////
void constructionCaisse(Objet &obj)
{
  int k = 0;                                       // Indice de point

  // Construction des sommets de la caisse
  obj.points.resize(8);
  for(int x=0; x<2; ++x){
    for(int y=0; y<2; ++y){
      for(int z=0; z<2; ++z){
        obj.points[k].resize(4);
        obj.points[k][0] = 1.5 * (2 * x - 1);
        obj.points[k][1] = 2 * y - 1;
        obj.points[k][2] = 2 * z - 1;
        obj.points[k][3] = 1;
        k++;
      }
    }
  }
    
  // Construction des 6 faces
  obj.faces.resize(6);
  for(int i=0; i<6; ++i){
    obj.faces[i].points.resize(4);
    obj.faces[i].uv.resize(4);
    obj.faces[i].normale.resize(3, 0);
    obj.faces[i].uv[0].col = 0;
    obj.faces[i].uv[0].lig = 0;
    obj.faces[i].uv[1].col = 255;
    obj.faces[i].uv[1].lig = 0;
    obj.faces[i].uv[2].col = 255;
    obj.faces[i].uv[2].lig = 255;
    obj.faces[i].uv[3].col = 0; 
    obj.faces[i].uv[3].lig = 255;
  }
  // Face 0
  obj.faces[0].points[0] = 3;
  obj.faces[0].points[1] = 1;
  obj.faces[0].points[2] = 0;
  obj.faces[0].points[3] = 2;
  obj.faces[0].normale[0] = -1;
  // Face 1
  obj.faces[1].points[0] = 7;
  obj.faces[1].points[1] = 3;
  obj.faces[1].points[2] = 2;
  obj.faces[1].points[3] = 6;
  obj.faces[1].normale[1] = 1;
  // Face 2
  obj.faces[2].points[0] = 5;
  obj.faces[2].points[1] = 7;
  obj.faces[2].points[2] = 6;
  obj.faces[2].points[3] = 4;
  obj.faces[2].normale[0] = 1;
  // Face 3
  obj.faces[3].points[0] = 1;
  obj.faces[3].points[1] = 5;
  obj.faces[3].points[2] = 4;
  obj.faces[3].points[3] = 0;
  obj.faces[3].normale[1] = -1;
  // Face 4
  obj.faces[4].points[0] = 0;
  obj.faces[4].points[1] = 4;
  obj.faces[4].points[2] = 6;
  obj.faces[4].points[3] = 2;
  obj.faces[4].normale[2] = -1;
  // Face 5
  obj.faces[5].points[0] = 3;
  obj.faces[5].points[1] = 7;
  obj.faces[5].points[2] = 5;
  obj.faces[5].points[3] = 1;
  obj.faces[5].normale[2] = 1;
}

///////////////////////////////////////////
// Test des fonctions de dessin d'objets 3D
///////////////////////////////////////////
void Test3D(SDL_Surface *image)
{
  static Objet caisse;            // Caisse 3D
  static Camera cam;              // Caméra
  static Mat matProj;             // Matrice de projection du monde virtuel vers la caméra
  static bool caisseInit = false; // Indique si la caisse est construite
  static bool cameraInit = false; // Indique si la caméra est initialisée
  static double angle = -M_PI/4;  // Position de la caméra autour de la caisse
  double rayon = 3;               // Rayon du cercle décrit par la caméra

  // Construction de la caisse si elle n'est pas déjà construite
  if(!caisseInit){
    constructionCaisse(caisse);
    caisseInit = true;
  }

  // Initialisation de la caméra si elle n'est pas déjà initialisée
  if(!cameraInit){
    cam.cible.resize(3, 0);
    cam.pos.resize(3, 0);
    cam.pos[2] = 3;
    cam.echelle = 100; // Ratio entre unité monde et nombre de pixels
    cameraInit = true;
  }else{ // Sinon mise à jour de l'angle de rotation de la caméra
    angle += 0.005;
  }

  // Mise à jour position X,Y de la caméra
  cam.pos[0] = rayon * cos(angle);
  cam.pos[1] = rayon * sin(angle);

  // Construction de la matrice de projection
  matriceMondeVersCamera(cam, matProj);

  // Dessin du repère 3D
  dessineRepere(matProj, image);  

  // Dessin de la caisse
  dessineObjet(caisse, matProj, image);  
}
