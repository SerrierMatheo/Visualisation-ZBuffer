/*
  Programme de dessin avec SDL
*/

// Inclusion bibliothèques standard
#include <cmath>
#include <cstdio>
#include <unistd.h>
#include <iostream>

// Inclusion fichiers locaux
#include "donnees.h"
#include "base.h"
#include "formesSimples.h"
#include "triangles.h"
#include "Segment.h"
#include "Object3D.h"
#include "3D.h"

///////////////////////////////////////////
// Fonction principale d'affichage appelée en boucle par le programme
// L'affichage à faire à chaque appel est identifié par une action
///////////////////////////////////////////
void AffichagePrincipal (Etat &etat, Objet o)
{
    Couleur blanc = {255, 255, 255, 0};  // Couleur : blanc
    Couleur noir = {0, 0, 0, 0};  // Couleur : noir

    // Affichage seulement s'il n'a pas déjà été fait (pour éviter charge CPU inutile)
    if(!etat.dejaFait){

        ColorieImage(blanc, etat.image); // Vidage de l'image
        etat.dejaFait = true;           // Indique que les dessins sont faits

        // Filtrage de l'action courante
        switch(etat.action){

            case FORMESSIMPLES: // Formes simples (rectangle et disque)
                printf("FORMESSIMPLES\n");
                FormesSimples(etat.image);
                break;

            case SEGMENTS:  // Cylindres des couleurs
                printf("SEGMENTS\n");
                TestSegment(etat.image);
                break;
            case TRIANGLES:  // Cylindres des couleurs
                printf("TRIANGLES\n");
                TestTriangles(etat.image);
                break;
            case PROJECTION:
                printf("PROJECTION\n");
                Test3D(etat.image);
                break;
            case CONV:
                printf("Test conversion\n");
                //méthode de test sur cubeNorm
                AfficherObjet(etat, o);
                break;
        }

        // Mise à jour de l'affichage de la fenêtre SDL
        MiseAJour(etat.image);
    }
}

///////////////////////////////////////////
// Gestion des touches du clavier pour les interactions éventuelles
///////////////////////////////////////////
bool GestionEvts(Etat &etat)
{
    //TODO ajouter un zoom avec + et -
    bool ret = false; // Valeur de retour de la fonction (vrai pour signaler l'arrêt)

    switch (etat.evt.type){ // Types d'événements pris en compte
        case SDL_QUIT:
            ret = true;
            break;

        case SDL_KEYDOWN:      // Touche enfoncée
            switch (etat.evt.key.keysym.sym){
                case SDLK_ESCAPE:    // Arrêt du programme
                    ret = true;
                    break;
                default:
                    break;
            }
            break;
        case SDL_KEYUP:        // Touche relâchée
            switch (etat.evt.key.keysym.sym){
                case SDLK_BACKSPACE: // Vide la fenêtre
                {
                    Couleur noir = {0,0,0,0};
                    ColorieImage(noir, etat.image);
                }
                    break;
                case 'q':            // Arrêt du programme
                    ret = true;
                    break;
                case '=':
                    printf("zoom");
                    //Doit augmenter la valeur de cam.echelle
                    break;
                case '-':
                    printf("dezoom");
                    //Doit diminuer la valeur de cam.echelle
                    break;
                case ' ' :           // Changement de l'action d'affichage
                {
                    Couleur noir = {0,0,0,0};
                    ColorieImage(noir, etat.image);
                    etat.action = (etat.action + 1) % etat.nbActions; // Passage à l'action suivante
                    etat.dejaFait = false; // Nouvelle action pas encore faite
                }
                    break;
                default:
                    break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN: // Clic souris ou
        case SDL_MOUSEMOTION:     // Déplacement souris
        {
            // Filtrage avec clic bouton gauche : inversion du pixel correspondant
            if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
                // AJOUTER LA RÉCUPÉRATION DE LA COULEUR DU PIXEL CORRESPONDANT À LA POSITION SOURIS
                // Couleur coul = ...;
                // MODIFIER coul POUR OBTENIR UNE "INVERSION VIDÉO"
                // coul.R = ...;
                // coul.V = ...;
                // coul.B = ...;
                // COLORIER LE PIXEL À LA POSITION SOURIS AVEC LA NOUVELLE VALEUR DE coul
                // ColoriePixel(...);
                // METTRE À JOUR L'AFFICHAGE DE LA FENÊTRE SDL
                // MiseAJour(...);
            }
        }
            break;
        default:
            break;
    }

    return ret;
}

///////////////////////////////////////////
// Fonction de lancement du programme
///////////////////////////////////////////
int main(int argc, char **argv)
{
    O::Object3D obj("cubeNorm.ply");
    std::cout << obj.afficherInfo(1) << std::endl;
    //obj.createFile("cubeNorm2");
    Objet o;
    o = O::Object3D::Object3DtoObjet(obj);

    Uint32 configuration;            // Configuration de la fenêtre SDL
    bool fini = false;               // Indique quant le programme doit s'arrêter
    Etat etat;                       // État global du programme
    Uint32 debut, temps;             // Heure de début et durée d'une itération
    Uint32 dureeIteration = 1000/30; // Durée fixée de chaque itération (selon le framerate)

    // Init état global
    etat.action = CONV;//FORMESSIMPLES;
    etat.dejaFait = false;
    etat.nbActions = NBACTIONS;

    // Initialisation Vidéo SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ){
        printf("Problème d’initialisation SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Initialisation des dimensions de la fenêtre
    etat.Largeur = 1250;
    etat.Hauteur = 800;

    // Création fenêtre SDL
    configuration  = SDL_HWSURFACE | SDL_DOUBLEBUF;  // Spécification du type de fenêtre SDL
    // configuration |= SDL_FULLSCREEN; // (accélération et plein écran)
    if (!(etat.image = SDL_SetVideoMode(etat.Largeur, etat.Hauteur, 32, configuration))){
        printf("Problème de création de la fenêtre SDL : %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Gestion des événements
    while(!fini){ // Boucle principale du programme (tant que non terminé)

        debut = SDL_GetTicks();            // Horloge au départ de l'itération

        AffichagePrincipal(etat, o);          // Affichage

        while(SDL_PollEvent(&(etat.evt))){ // Gestion des événements
            fini = GestionEvts(etat);
        }

        temps = SDL_GetTicks() - debut;    // Durée de l'itération

        if(temps < dureeIteration){        // Temporisation avant nouvelle itération
            SDL_Delay(dureeIteration - temps);
        }
    }
    // Terminaison SDL
    SDL_Quit();

    // Fin du programme
    return EXIT_SUCCESS;
}
