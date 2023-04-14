#include <cmath>
#include "3D.h"
#include "formesSimples.h"
#include "Segment.h"
#include "triangles.h"
#include "matrices.h"
#include <iostream>
#include <cstdio>

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

    mat[0][0]=Xc[0];
    mat[0][1]=Xc[1];
    mat[0][2]=Xc[2];
    mat[0][3]=prodScal(Xc, CO);

    mat[1][0]=Yc[0];
    mat[1][1]=Yc[1];
    mat[1][2]=Yc[2];
    mat[1][3]=prodScal(Yc, CO);

    mat[2][0]=Zc[0];
    mat[2][1]=Zc[1];
    mat[2][2]=Zc[2];
    mat[2][3]=prodScal(Zc, CO);

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
  Disque(lstPts[0], 3, blanc, image); // Origine
  Disque(lstPts[1], 3, rouge, image); // X
  Disque(lstPts[2], 3, vert, image);  // Y
  Disque(lstPts[3], 3, bleu, image);  // Z

  DrawSegment(lstPts[0], lstPts[1], rouge, image); //X
  DrawSegment(lstPts[0], lstPts[2], vert, image); //Y
  DrawSegment(lstPts[0], lstPts[3], bleu, image); //Z

}

void dessinePoint(Mat &matProj, Vec p1, Couleur c, SDL_Surface *image)
{
    Vec pt(4);                          // Point projeté
    vector<Vec> pts3D;               // Liste des 4 points dans le monde virtuel
    vector<PointImage> lstPts(2);       // Liste des 4 points dans l'image
    pts3D.push_back(p1);

    // Projection des sommets de l'objet
    for(size_t i=0; i<pts3D.size(); ++i){ // Parcours des points
        // Projection du point dans le repère caméra
        projection(matProj, pts3D[i], pt);
        positionDansImage(pt, lstPts[i], image);
    }

    // Dessine le point
    Disque(lstPts[0], 10, c, image);

}

void dessineVecteur(Mat &matProj,Vec p1, Vec p2, Couleur c,SDL_Surface *image)
{
    Vec pt(4);                          // Point projeté
    vector<Vec> pts3D;               // Liste des 4 points dans le monde virtuel
    vector<PointImage> lstPts(2);       // Liste des 4 points dans l'image
    pts3D.push_back(p1);
    pts3D.push_back(p2);

    // Projection des sommets de l'objet
    for(size_t i=0; i<pts3D.size(); ++i){ // Parcours des points
        // Projection du point dans le repère caméra
        projection(matProj, pts3D[i], pt);
        positionDansImage(pt, lstPts[i], image);
    }

    // Dessin des é points
    Disque(lstPts[0], 3, c, image);
    Disque(lstPts[1], 3, c, image);

    DrawSegment(lstPts[0], lstPts[1], c, image);
}

void dessineObjetBase(Objet &obj, Mat &matProj, SDL_Surface *image){
    Vec pt;                    // Point projeté
    vector<PointImage> lstPts; // Liste des points dans l'image
    Couleur blanc = {255, 255, 255, 200}; // Couleurs pour les traits et points
    Couleur rouge = {255, 0, 0, 0};
    Couleur bleu = {0, 0, 255, 0};
    Couleur jaune = {255, 255, 0, 0};
    Couleur noir = {0, 0, 0, 0};

    // Projection des sommets de l'objet
    pt.resize(4);
    lstPts.resize(obj.points.size());

    for(size_t i=0; i<obj.points.size(); ++i){ // Parcours des points
        // Projection du point dans le repère caméra
        projection(matProj, obj.points[i], pt);
        positionDansImage(pt, lstPts[i], image);
    }
    // project 3D point and fill uv vector
    vector<PointImage> vecPtI = ProjectObjet(obj, matProj, image);
    for(size_t it=0; it<obj.faces.size(); it++) {
        Face &f = obj.faces.at(it);
        for(size_t it_bis = 0; it_bis< f.points.size(); it_bis++) {
            f.uv.push_back(vecPtI.at(f.points.at(it_bis)));
        }
    }

    //affiche toutes les faces
    for(size_t i=0; i<obj.faces.size(); ++i)
    {
        Face f = obj.faces[i];
        //Triangle(f.uv, f.c, image);

        for(size_t j=0; j<f.points.size(); ++j){
            int indA = f.points[j];
            int indB = f.points[(j+1) % f.points.size()]; // Indice du sommet suivant, en prenant en compte le dernier sommet qui doit être relié au premier sommet
            // Coloriage du sommet courant avec un point de rayon 5 pixels
            Disque(lstPts[indA], 1, noir, image);
            DrawSegment(lstPts[indA],lstPts[indB],noir, image);
        }
    }
}

///////////////////////////////////////////
// Dessin d'un objet 3D
///////////////////////////////////////////
void dessineObjet(Objet &obj, Mat &matProj, Camera &cam, Etat &etat)
{
  Vec pt;                    // Point projeté
  vector<PointImage> lstPts; // Liste des points dans l'image
  Couleur blanc = {255, 255, 255, 200}; // Couleurs pour les traits et points
  Couleur rouge = {255, 0, 0, 0};
  Couleur bleu = {0, 0, 255, 0};
  Couleur jaune = {255, 255, 0, 0};
  Couleur noir = {0, 0, 0, 0};
  vector<Couleur> vc;
  vc.push_back(jaune);

  // Projection des sommets de l'objet
  pt.resize(4);
  lstPts.resize(obj.points.size());

  for(size_t i=0; i<obj.points.size(); ++i){ // Parcours des points
    // Projection du point dans le repère caméra
    projection(matProj, obj.points[i], pt);
    positionDansImage(pt, lstPts[i], etat.image);
  }
  // project 3D point and fill uv vector
  vector<PointImage> vecPtI = ProjectObjet(obj, matProj, etat.image);
  for(size_t it=0; it<obj.faces.size(); it++) {
      Face &f = obj.faces.at(it);
      for(size_t it_bis = 0; it_bis< f.points.size(); it_bis++) {
          f.uv.push_back(vecPtI.at(f.points.at(it_bis)));
      }
  }
  //récupérer les faces visibles via backface culling
    vector<Face> visibleFaces;
    visibleFaces = backfaceCulling(obj, cam);

    //affiche uniquement les faces visibles depuis la caméra
    for(size_t i=0; i<visibleFaces.size(); ++i)
    //for(size_t i=0; i<obj.faces.size(); ++i)
    {
        Face f = visibleFaces[i];
        //Face f = obj.faces[i];
        Triangle(f.uv, f.c, etat.image);
        //Dessin normal vector of the face

        //initialise barycentre
        Vec barycentre;
        Vec sommet1 = obj.points[f.points[0]];
        Vec sommet2 = obj.points[f.points[1]];
        Vec sommet3 = obj.points[f.points[2]];

        barycentre = computeBarycenter(sommet1, sommet2, sommet3);

        //dessineVecteur(matProj, barycentre, f.normale, jaune, etat.image);
        Vec test;
        test.resize(3,0);
        //dessineVecteur(matProj, test, cam.pos, jaune, etat.image);
        //dessiner les arrêtes des faces:

        for(size_t j=0; j<f.points.size(); ++j){
            int indA = f.points[j];
            int indB = f.points[(j+1) % f.points.size()]; // Indice du sommet suivant, en prenant en compte le dernier sommet qui doit être relié au premier sommet
            // Coloriage du sommet courant avec un point de rayon 5 pixels
            //Disque(lstPts[indA], 1, rouge, image);
            //DrawSegment(lstPts[indA],lstPts[indB],rouge, image);
        }
    }
}

void dessineObjetZbuffer(Objet &obj, Mat &matProj, Camera &cam, Etat &etat){
    Vec pt;                    // Point projeté
    vector<PointImage> lstPts; // Liste des points dans l'image
    Couleur blanc = {255, 255, 255, 200}; // Couleurs pour les traits et points
    Couleur jaune = {255, 255, 0, 0};

    // Projection des sommets de l'objet
    pt.resize(4);
    lstPts.resize(obj.points.size());

    for(size_t i=0; i<obj.points.size(); ++i){ // Parcours des points
        // Projection du point dans le repère caméra
        projection(matProj, obj.points[i], pt);
        positionDansImage(pt, lstPts[i], etat.image);
    }

    // project 3D point and fill uv vector
    vector<PointImage> vecPtI = ProjectObjet(obj, matProj, etat.image);
    for(size_t it=0; it<obj.faces.size(); it++) {
        Face &f = obj.faces.at(it);
        for(size_t it_bis = 0; it_bis< f.points.size(); it_bis++) {
            f.uv.push_back(vecPtI.at(f.points.at(it_bis)));
        }
    }
    //récupérer les faces visibles via backface culling
    vector<Face> visibleFaces;
    visibleFaces = backfaceCulling(obj, cam);

    //créer la matrice de profondeur Z-Buffer sur le tas
    double** zbuffer = new double*[etat.Largeur];
    for(int i = 0; i < etat.Largeur; i++) {
        zbuffer[i] = new double[etat.Hauteur];
    }

    //créer la matrice des couleurs des pixels sur le tas
    Couleur** couls = new Couleur*[etat.Largeur];
    for(int i = 0; i < etat.Largeur; i++) {
        couls[i] = new Couleur[etat.Hauteur];
    }

    zBuffer(obj, cam, etat.Hauteur, etat.Largeur, zbuffer, couls);

    for (int i = 0; i < etat.Largeur; ++i) {
        for (int j = 0; j < etat.Hauteur; ++j) {
            ColoriePixel(i,j,couls[i][j],etat.image);
        }
    }
}

void dessineCaisse(Objet &obj, Mat &matProj, Camera &cam, SDL_Surface *image)
{
    Vec pt;                    // Point projeté
    vector<PointImage> lstPts; // Liste des points dans l'image
    Couleur blanc = {255, 255, 255, 200}; // Couleurs pour les traits et points
    Couleur rouge = {255, 0, 0, 0};
    Couleur bleu = {0, 0, 255, 0};
    Couleur jaune = {255, 255, 0, 0};
    Couleur noir = {0, 0, 0, 0};
    vector<Couleur> vc;
    vc.push_back(jaune);

    // Projection des sommets de l'objet
    pt.resize(4);
    lstPts.resize(obj.points.size());

    for(size_t i=0; i<obj.points.size(); ++i){ // Parcours des points
        // Projection du point dans le repère caméra
        projection(matProj, obj.points[i], pt);
        positionDansImage(pt, lstPts[i], image);
    }
    // project 3D point and fill uv vector
    vector<PointImage> vecPtI = ProjectObjet(obj, matProj, image);
    for(size_t it=0; it<obj.faces.size(); it++) {
        Face &f = obj.faces.at(it);
        for(size_t it_bis = 0; it_bis< f.points.size(); it_bis++) {
            f.uv.push_back(vecPtI.at(f.points.at(it_bis)));
        }
    }

    //affiche toutes les faces
    for(size_t i=0; i<obj.faces.size(); ++i)
    {
        Face f = obj.faces[i];
        for(size_t j=0; j<f.points.size(); ++j){
            int indA = f.points[j];
            int indB = f.points[(j+1) % f.points.size()]; // Indice du sommet suivant, en prenant en compte le dernier sommet qui doit être relié au premier sommet
            // Coloriage du sommet courant avec un point de rayon 5 pixels
            Disque(lstPts[indA], 1, jaune, image);
            DrawSegment(lstPts[indA],lstPts[indB],rouge, image);
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

void AfficherObjetBase(Etat &etat, Objet obj){
    static Objet objet = obj;
    static Camera cam;              // Caméra
    static Mat matProj;             // Matrice de projection du monde virtuel vers la caméra
    static bool objetInit = false; // Indique si l'objet est construit
    static bool cameraInit = false; // Indique si la caméra est initialisée
    static double angle = -M_PI/4;  // Position de la caméra autour de la caisse
    double rayon = 3;               // Rayon du cercle décrit par la caméra

    // Construction de l'objet s'il n'est pas déjà construit
    if(!objetInit){
        objetInit = true;
    }

    // Initialisation de la caméra si elle n'est pas déjà initialisée
    if(!cameraInit){
        cam.cible.resize(3, 0);
        cam.pos.resize(3, 0);
        cam.pos[2] = 3;
        cam.echelle = 35; // Ratio entre unité monde et nombre de pixels
        cameraInit = true;
    }else{ // Sinon mise à jour de l'angle de rotation de la caméra
        angle += 0.1;
    }

    // Mise à jour position X, Y de la caméra
    cam.pos[0] = (rayon * cos(angle));
    cam.pos[1] = (rayon * sin(angle));

    // Construction de la matrice de projection
    matriceMondeVersCamera(cam, matProj);

    cout << std::to_string(cam.pos[0]) +" "+ std::to_string(cam.pos[1]) +" "+ std::to_string(cam.pos[2]) << endl;

    // Dessin de l'objet
    dessineObjetBase(obj, matProj, etat.image);

    // Dessin du repère 3D
    dessineRepere(matProj, etat.image);
}

void AfficherObjetVisible(Etat &etat, Objet obj){
    static Objet objet = obj;
    static Camera cam;              // Caméra
    static Mat matProj;             // Matrice de projection du monde virtuel vers la caméra
    static bool objetInit = false; // Indique si l'objet est construit
    static bool cameraInit = false; // Indique si la caméra est initialisée
    static double angle = -M_PI/4;  // Position de la caméra autour de la caisse
    double rayon = 3;               // Rayon du cercle décrit par la caméra

    // Construction de l'objet s'il n'est pas déjà construit
    if(!objetInit){
        objetInit = true;
    }

    // Initialisation de la caméra si elle n'est pas déjà initialisée
    if(!cameraInit){
        cam.cible.resize(3, 0);
        cam.pos.resize(3, 0);
        cam.pos[2] = 3;
        cam.echelle = 35; // Ratio entre unité monde et nombre de pixels
        cameraInit = true;
    }else{ // Sinon mise à jour de l'angle de rotation de la caméra
        angle += 0.1;
    }

    // Mise à jour position X, Y de la caméra
    cam.pos[0] = (rayon * cos(angle));
    cam.pos[1] = (rayon * sin(angle));
    /*cam.pos[0] = -100;
    cam.pos[1] = 100;
    cam.pos[2] = 200;*/

    // Construction de la matrice de projection
    matriceMondeVersCamera(cam, matProj);

    cout << std::to_string(cam.pos[0]) +" "+ std::to_string(cam.pos[1]) +" "+ std::to_string(cam.pos[2]) << endl;

    // Dessin de l'objet
    dessineObjet(obj, matProj, cam, etat);

    // Dessin du repère 3D
    dessineRepere(matProj, etat.image);
}

void AfficherObjet(Etat &etat, Objet obj){
    static Objet objet = obj;
    static Camera cam;              // Caméra
    static Mat matProj;             // Matrice de projection du monde virtuel vers la caméra
    static bool objetInit = false; // Indique si l'objet est construit
    static bool cameraInit = false; // Indique si la caméra est initialisée
    static double angle = -M_PI/4;  // Position de la caméra autour de la caisse
    double rayon = 3;               // Rayon du cercle décrit par la caméra

    // Construction de l'objet s'il n'est pas déjà construit
    if(!objetInit){
        objetInit = true;
    }

    // Initialisation de la caméra si elle n'est pas déjà initialisée
    if(!cameraInit){
        cam.cible.resize(3, 0);
        cam.pos.resize(3, 0);
        cam.pos[2] = 3;
        cam.echelle = 35; // Ratio entre unité monde et nombre de pixels
        cameraInit = true;
    }else{ // Sinon mise à jour de l'angle de rotation de la caméra
        angle += 0.1;
    }

    // Mise à jour position X, Y de la caméra
    cam.pos[0] = (rayon * cos(angle));
    cam.pos[1] = (rayon * sin(angle));
    /*cam.pos[0] = -100;
    cam.pos[1] = 100;
    cam.pos[2] = 200;*/

    // Construction de la matrice de projection
    matriceMondeVersCamera(cam, matProj);

    cout << std::to_string(cam.pos[0]) +" "+ std::to_string(cam.pos[1]) +" "+ std::to_string(cam.pos[2]) << endl;

    // Dessin de l'objet
    //dessineObjet(obj, matProj, cam, etat);

    //dessin de la caméra
    //dessinePoint(matProj, cam.pos, BLANC, etat.image);

// Dessin du repère 3D
    //dessineRepere(matProj, etat.image);

    dessineObjetZbuffer(obj,matProj,cam,etat);
}

/**
 * Test3D : method used to test if the visualization of 3D objects works correctly.
 * @param image an SDL_Surface
 */
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
    angle += 0.05;
  }

  // Mise à jour position X, Y de la caméra
  cam.pos[0] = rayon * cos(angle);
  cam.pos[1] = rayon * sin(angle);

  // Construction de la matrice de projection
  matriceMondeVersCamera(cam, matProj);

  // Dessin du repère 3D
  dessineRepere(matProj, image);

  // Dessin de la caisse
  dessineCaisse(caisse, matProj, cam, image);
}

vector<PointImage> ProjectObjet(Objet obj, Mat &matProj, SDL_Surface *image) {
    Vec pt;                    // Point projeté
    PointImage pi;
    vector<PointImage> uv;
    for(size_t i=0; i<obj.points.size(); ++i){ // Parcours des points
        // Projection du point dans le repère caméra
        projection(matProj, obj.points[i], pt);
        positionDansImage(pt, pi, image);
        uv.push_back(pi);
    }
    return uv;
}

/**
 * backfaceCulling :
method implementing the backface culling algorithm allowing to recover only the faces of the object which are visible from the point of view of the camera
 * @param obj an Objet
 * @param cam a Camera
 * @return vector<Face> : the list of visible faces
 */
vector<Face> backfaceCulling(Objet obj, Camera cam){
    //liste des faces visibles d'un obj
    vector<Face> visibleFaces;

    //parcourir l'ensemble des faces de l'objet
    for (int i = 0; i < obj.faces.size(); ++i) {
        Face face = obj.faces[i];

        //recupère la normale de la face précédement calculée
        Vec normale = face.normale;

        //calcul le centre du triangle
        Vec barycentre; //= computeCenter(obj, face);

        Vec sommet1 = obj.points[face.points[0]];
        Vec sommet2 = obj.points[face.points[1]];
        Vec sommet3 = obj.points[face.points[2]];

        barycentre = computeBarycenter(sommet1, sommet2, sommet3);

        //Calculer le vecteur de la caméra en direction de la face
        Vec cameraVector;
        double x = barycentre[0] - cam.pos[0];
        double y =  barycentre[1] - cam.pos[1];
        double z =  barycentre[2] - cam.pos[2];
        cameraVector.push_back(x);
        cameraVector.push_back(y);
        cameraVector.push_back(z);

        //Calcule du produit scalaire
        double dotProduct = prodScal( normale, cameraVector);

        //s'il est négatif, la face est orientée vers la caméra, on ajoute la face à la liste
        if (dotProduct < 0){
            visibleFaces.push_back(obj.faces[i]);
        }
    }
    //retourne la liste remplie
    return visibleFaces;
}

//TODO a completer
/**
 * zBuffer : compute and fill the Z-Buffer of a 3D scene
 * @param obj an 3D object
 * @param cam a camera
 * @param etat an Etat
 * @param tampon a table of double
 * @param couleurs a table of colors
 */
void zBuffer(Objet obj, Camera cam, int hauteur, int largeur, double** tampon, Couleur** couleurs){

    //récupérer hauteur et largeur de la fenêtre
    int height = hauteur;
    int width = largeur;

    //créer la matrice de profondeur Z-Buffer sur le tas
    double** zBuffer = new double*[width];
    for(int i = 0; i < width; i++) {
        zBuffer[i] = new double[height];
    }

    //créer la matrice des couleurs des pixels sur le tas
    Couleur** colors = new Couleur*[width];
    for(int i = 0; i < width; i++) {
        colors[i] = new Couleur[height];
    }

    //Initialiser la matrice Z-Buffer à -∞
    //Initialiser la matrice de couleur avec la couleur de fond
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            zBuffer[i][j] = -std::numeric_limits<double>::infinity();
            colors[i][j] = BLANC;
            //cout << "i : " +std::to_string(i) + "; j : " + std::to_string(j) << endl;
        }
    }

    //récupérer les faces visibles via backface culling
    vector<Face> visibleFaces;
    visibleFaces = backfaceCulling(obj, cam);

    //parcours des faces de l'objet
    for (int i = 0; i<visibleFaces.size() ; ++i) {
        //récupère la face courante
        Face face = visibleFaces[i];

        //récupère les coordonnées 3D des 3 sommets
        Vec A = obj.points[face.points[0]];
        Vec B = obj.points[face.points[1]];
        Vec C = obj.points[face.points[2]];

        vector<Vec> sommets;
        sommets.push_back(A);
        sommets.push_back(B);
        sommets.push_back(C);
        /*
        //récupère les PointImage correspondant aux sommets de la face
        PointImage A2 = face.uv[0];
        PointImage B2 = face.uv[1];
        PointImage C3 = face.uv[2];*/

        //récupérer les pixels de la face
        vector<PointImage> listePixels = recupererPixels(face.uv);
        Mat listePoints;
        for (int j = 0; j < listePixels.size(); ++j) {
            //interpolation
            //récupère la liste des coordonnées 3D des pixels de la face courante
            //un point 3D pour 1 pixel
             listePoints.push_back(interpolation(face.uv,sommets,listePixels[j]));
        }

        //calcul distance
        for (int j = 0; j < listePixels.size(); ++j) {
            Vec pts3D = listePoints[j];
            //calculer profondeur cam-listePoints[j]
            double profondeur = length(cam.pos[0],cam.pos[1],cam.pos[2],pts3D[0],pts3D[1],pts3D[2]);

            //si profondeur < valeur stockée, on remplace par profondeur et colors reçoit la couleur de la face
            if(zBuffer[listePixels[j].col][listePixels[j].lig] < profondeur){
                zBuffer[listePixels[j].col][listePixels[j].lig] = profondeur;
                colors[listePixels[j].col][listePixels[j].lig] = face.c[0];
            }
        }
    }

    // Assigner les valeurs de la matrice Z-Buffer au tableau de pointeurs "tampon", de même pour couleurs
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            tampon[i][j] = zBuffer[i][j];
            couleurs[i][j] = colors[i][j];
        }
    }
}

//TODO à corriger
Vec interpolation(vector<PointImage> uv, vector<Vec> sommets, PointImage p){

    Vec pts3D;

    PointImage A2 = uv[0];
    PointImage B2 = uv[1];
    PointImage C2 = uv[2];

    PointImage A2P, B2C2;
    A2P.lig = p.lig - A2.lig;
    A2P.col = p.col - A2.col;
    B2C2.lig = C2.lig - B2.lig;
    B2C2.col = C2.col - B2.col;

    //trouver l'intersection de A2P et B2C2
    //On cherche pour A2P y=mx+b
    //Cherchons m (la pente)
    double m;
    if (B2C2.col - A2P.col == 0) {
        m = 1e9; // ou -1e9 si B2C2.lig - A2P.lig < 0
    } else {
        m = (B2C2.lig - A2P.lig)/(B2C2.col - A2P.col);
    }
    //Cherchons b (origine)
    double b = A2P.lig - m*A2P.col;

    double m2;
    if (A2P.col - B2C2.col == 0) {
        m2 = 1e9; // ou -1e9 si B2C2.lig - A2P.lig < 0
    } else {
        m2 = (A2P.lig - B2C2.lig)/(A2P.col - B2C2.col);
    }
    double b2 = B2C2.lig - m2*B2C2.col;

    //trouvons x
    double x = (b2-b)/(m2-m);
    double y = (m*x)+b;

    //On trouve D2 l'intersection de A2P et B2C2
    PointImage D2;
    D2.col = x;
    D2.lig = y;

    //cherchons alpha et beta
    double beta;
    double ODminusOBx = D2.col - B2.col;
    double ODminusOBy = D2.lig - B2.lig;
    Vec num;
    num.push_back(ODminusOBx);
    num.push_back(ODminusOBy);
    normaliser2D(num);

    double B2C2x = C2.col - B2.col;
    double B2C2y = C2.lig - B2.lig;
    Vec denum;
    denum.push_back(B2C2x);
    denum.push_back(B2C2y);
    normaliser2D(denum);

    double res1 = num[0] / denum[0];
    double res2 = num[1] / denum[1];
    beta = res1 / res2;

    double alpha;
    double OPminusOAx = p.col - A2.col;
    double OPminusOAy = p.lig - A2.lig;

    num.push_back(OPminusOAx);
    num.push_back(OPminusOAy);
    normaliser2D(num);

    double A2px = p.col - A2.col;
    double A2py = p.lig - A2.lig;

    denum.push_back(A2px);
    denum.push_back(A2py);
    normaliser2D(denum);

    res1 = num[2] / denum[2];
    res2 = num[3] / denum[3];
    alpha = res1 / res2;

    //Trouvons les coordonnées de p3D et D

    return pts3D;
}

void normaliser2D(Vec w){
    double norm = sqrt(w[0]*w[0] + w[1]*w[1]);
    w[0]= w[0]/norm;
    w[1]= w[1]/norm;
}


/**
 * computeBarycenter : compute the face barycenter
 * @param vertexA a vector<double>
 * @param vertexB a vector<double>
 * @param vertexC a vector<double>
 * @return a vector<double> : the face barycenter
 */
vector<double> computeBarycenter(vector<double> vertexA, vector<double> vertexB, vector<double> vertexC) {
    // Calcul des coordonnées du barycentre
    double x = (vertexA[0] + vertexB[0] + vertexC[0]) / 3.0;
    double y = (vertexA[1] + vertexB[1] + vertexC[1]) / 3.0;
    double z = (vertexA[2] + vertexB[2] + vertexC[2]) / 3.0;

    // Création d'un vecteur pour stocker les coordonnées du barycentre
    vector<double> barycenter;
    barycenter.push_back(x);
    barycenter.push_back(y);
    barycenter.push_back(z);

    return barycenter;
}

//calcul la distance entre 2 points 3D
double length(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}


