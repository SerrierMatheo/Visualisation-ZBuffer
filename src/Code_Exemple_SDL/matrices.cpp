#include <math.h>
#include "matrices.h"

///////////////////////////////////////////
// Matrice identité
///////////////////////////////////////////
void identite(Mat &mat)
{
  mat.resize(4);
  for(int l=0; l<4; ++l){
    mat[l].resize(4,0);
    mat[l][l] = 1;
  }    
}

///////////////////////////////////////////
// Matrice de rotation d'angle teta
// autour de l'axe spécifié
///////////////////////////////////////////
void rotation(Mat &mat, double teta, char axe)
{
  double cost = cos(teta), sint = sin(teta);

  identite(mat);
  switch(axe){
  case 'X':
    mat[1][1] =  cost;
    mat[1][2] = -sint;
    mat[2][1] =  sint;
    mat[2][2] =  cost;
    break;
  case 'Y':
    mat[0][0] =  cost;
    mat[0][2] =  sint;
    mat[2][0] = -sint;
    mat[2][2] =  cost;
    break;
  case 'Z':
    mat[0][0] =  cost;
    mat[0][1] = -sint;
    mat[1][0] =  sint;
    mat[1][1] =  cost;
    break;
  }
}

///////////////////////////////////////////
// Ajoute la translation tr à la matrice mat
///////////////////////////////////////////
void translation(Mat &mat, Vec &tr)
{
  for(int l=0; l<3; ++l){
    mat[l][3] = tr[l];
  }
}

///////////////////////////////////////////
// Matrice de perspective avec focale f
// et centre optique (cx,cy)
///////////////////////////////////////////
void perspective(Mat &mat, double f, double cx, double cy)
{
  identite(mat);
  mat[0][2] = cx / f;
  mat[1][2] = cy / f;
  mat[3][2] =  1 / f;
  mat[3][3] =      0;
}

///////////////////////////////////////////
// Multiplication de 2 matrices A et B dans C
///////////////////////////////////////////
void matMul(Mat &A, Mat& B, Mat &C)
{
  identite(C);
  for(int l=0; l<4; ++l){
    for(int c=0; c<4; ++c){
      C[l][c] = 0;
      for(int k=0; k<4; ++k){
        C[l][c] += A[l][k] * B[k][c];
      }
    }
  }
}

///////////////////////////////////////////
// Multiplication d'une matrice par un coefficient
///////////////////////////////////////////
void matCoef(Mat &A, double coef)
{
  for(int l=0; l<4; ++l){
    vecCoef(A[l], coef);
  }
}

///////////////////////////////////////////
// Multiplication d'un vecteur par un coefficient
///////////////////////////////////////////
void vecCoef(Vec &vec, double coef)
{
  for(int l=0; l<4; ++l){
    vec[l] *= coef;
  }
}

///////////////////////////////////////////
// Produit scalaire de deux vecteurs
///////////////////////////////////////////
double prodScal(Vec &v1, Vec &v2)
{
  double res = 0;
  for(size_t l=0; l<v1.size(); ++l){
    res += v1[l] * v2[l];
  }
  return res;
}

///////////////////////////////////////////
// Produit vectoriel de deux vecteurs
///////////////////////////////////////////
void prodVec(Vec &v1, Vec &v2, Vec &res)
{
  int dim = 3;
  if(v1.size() == 2){
    dim--;
  }
  res.resize(dim);
  for(int l=0; l<dim; ++l){
    int a = (l+1) % dim;
    int b = (l+2) % dim;
    res[l] = v1[a] * v2[b] - v1[b] * v2[a];
  }
}

///////////////////////////////////////////
// Différence entre deux vecteurs
///////////////////////////////////////////
void vecDiff(Vec &v1, Vec &v2, Vec &res)
{
  res.resize(v1.size());
  for(size_t l=0; l<v1.size(); ++l){
    res[l] = v1[l] - v2[l];
  }
}

///////////////////////////////////////////
// Normalisation d'un vecteur
///////////////////////////////////////////
void normalisation(Vec &v)
{
  double norme = 0;

  for(size_t l=0; l<v.size(); ++l){
    norme += v[l] * v[l];
  }
  if(norme > 1e-10){ // Norme suffisamment grande
    norme = sqrt(norme);
    for(size_t l=0; l<v.size(); ++l){
      v[l] /= norme;
    }
  }
}

///////////////////////////////////////////
// Transformation d'un Point3D en vecteur homogène
///////////////////////////////////////////
void projection(Mat &mat, Vec &ptMonde, Vec &ptCamera)
{
  ptCamera.resize(4);
  for(int l=0; l<4; ++l){
    ptCamera[l] = 0;
    for(int c=0; c<4; ++c){
      ptCamera[l] += mat[l][c] * ptMonde[c];
    }
  }
}
