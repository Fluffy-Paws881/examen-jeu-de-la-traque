#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#define WINDOW_WIDTH 780
#define WINDOW_HEIGHT 400

SDL_Window *pWindow ;
SDL_Renderer *pRenderer;
SDL_Surface* image ;
SDL_Texture* pTextureImage;
typedef struct coordonnee{
    int x;
    int y;
}coordonne;

extern void sdlAffiche (int tab[14][29]);
extern void deplacementPisteur(coordonne *pisteur,int tab[14][29]);
extern void tire();
extern void verifPisteur(coordonne *pisteur,int tab[14][29]);
extern void gestionPisteur(int tab[14][29]);
extern void effacementTrace(int tab[14][29]);
extern void attaqueMonstre (int tab[14][29],coordonne *monstre);
extern coordonne verifDeplaMonstreRandom (int tab[14][29],coordonne *monstre);
extern void deplacementMonstre(int tab[14][29],coordonne *monstre);
extern void placementMonstre(int tab[14][29],coordonne *monstre);
extern int getRando(int nb);
extern void verifCoordPisteur(int tab[14][29],int nbpist);
extern void placementPisteur(int tab[14][29]);
extern void initialisationTableau(int tab[14][29]);
extern void afficheTableau(int tab[14][29]);
extern void gotoxy(short x, short y);
extern void intialisationPisteur();

int pisteur_global;
int nb_pisteur;
int vie_monstre;
int monstre_blesse ;


#endif // DEFINE_H_INCLUDED
