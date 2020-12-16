#include "define.h"
SDL_Window *pWindow = NULL ;
SDL_Renderer *pRenderer= NULL;
SDL_Surface* image = NULL;
SDL_Texture* pTextureImage= NULL;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        SDL_Log("unable to initialize SDL : %s", SDL_GetError());
        return 1;
    }else{
        pWindow = SDL_CreateWindow("an SDL2 window",250,255,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);

        if (pWindow)
        {
            pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
        }
    }
   SDL_Event events;
   SDL_bool isOpen = SDL_TRUE;



     vie_monstre = 4;
     monstre_blesse = 0;


    fflush(stdin);
    coordonne pos_monstre;

    int tableau_jeu[14][29];
    int verif_victoire = 0;

    srand(time(NULL));//initialisation d un random

    intialisationPisteur();
    pisteur_global = nb_pisteur;
    initialisationTableau(&tableau_jeu);
    placementPisteur(&tableau_jeu);

    placementMonstre(&tableau_jeu,&pos_monstre);

    do
    {
        while ((isOpen) && (verif_victoire == 0))
    {
         while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = SDL_FALSE ;
                break;
            }
        }

        fflush(stdin);
        gestionPisteur(&tableau_jeu);
        system("cls");

       // gotoxy(0,0);

        deplacementMonstre(&tableau_jeu,&pos_monstre);
        effacementTrace(&tableau_jeu);
        gotoxy(0,1);
        attaqueMonstre(&tableau_jeu,&pos_monstre);

        afficheTableau(&tableau_jeu);
        getchar();

        if (monstre_blesse>0)
        {
            monstre_blesse--;
        }


        system("cls");


        if ((nb_pisteur==0) || (vie_monstre ==0))
        {
            verif_victoire = 1;
        }


    }

    }while(verif_victoire ==0 );

    system("cls");
    gotoxy(0,0);
    if (nb_pisteur ==0)
    {
        printf("GAME OVER, tous les pisteurs se sont fait avoir...");
    }else{
        printf("FELICITATION, vous avez vaincu la creature");
    }


    return 0;
}






