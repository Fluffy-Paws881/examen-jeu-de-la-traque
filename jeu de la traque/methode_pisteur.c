#include "define.h"
void gestionPisteur(int tab[14][29])//procedure de gestion d un pisteur
{
    int verif = 0;
    coordonne recup_pisteur;

    for (int i=0;i<pisteur_global;i++)
    {
        system("cls");
        gotoxy(0,5+i);
         for (int v = 0; v<14;v++)
        {
            for (int j = 0; j<29;j++)
            {
               if (tab[v][j]== 51+i)
               {
                   fflush(stdin);

                   recup_pisteur.x =v;
                   recup_pisteur.y =j;

                  afficheTableau(tab);
                  gotoxy(41+recup_pisteur.y,10+recup_pisteur.x);
                  printf("!");


                   verifPisteur(&recup_pisteur,tab);
                    getchar();
               }
            }
        }
    }


        for (int i=0;i<pisteur_global;i++)
    {
        fflush(stdin);
        system("cls");
        gotoxy(0,5+i);
         for (int v = 0; v<14;v++)
        {
            for (int j = 0; j<29;j++)
            {
               if ((tab[v][j]== 51+i) && (verif ==0) )
               {
                   fflush(stdin);

                   recup_pisteur.x =v;
                   recup_pisteur.y =j;

                  afficheTableau(tab);
                  gotoxy(41+recup_pisteur.y,10+recup_pisteur.x);
                  printf("?");


                   deplacementPisteur(&recup_pisteur,tab);
                    verif=1;
               }
            }

        }


    verif = 0;
    }
}

void verifPisteur(coordonne *pisteur,int tab[14][29])// verification des 8 case adjacente du pisteur
{

    for (int i = 0;i<8;i++)
    {
        gotoxy(0,1+i);
       // printf("%d",tab[pisteur->x][pisteur->y]);
       switch (i)
        {
            case 0:
                if((tab[pisteur->x-1][pisteur->y-1]>0) && (tab[pisteur->x-1][pisteur->y-1]<16) && (pisteur->x-1 >= 0) && (pisteur->y-1 >= 0) )
                {
                    printf("le pisteur %d a trouve des trace en case %d d une fraicheur de %d\n",tab[pisteur->x][pisteur->y]-50,i+1,tab[pisteur->x-1][pisteur->y-1]);
                    gotoxy(41+pisteur->y-1,10+pisteur->x-1);
                    printf("o");

                }else if(tab[pisteur->x-1][pisteur->y-1]==16){
                    gotoxy(41+pisteur->y-1,10+pisteur->x-1);
                    printf("M");
                    gotoxy(0,1+i);

                    printf("attention! le monstre est dans la case %d\n",i+1);
                    tire();

                }else{
                    printf("le pisteur %d n a rien dans la case %d\n",tab[pisteur->x][pisteur->y]-50,i+1);
                }
                break;


            case 1:
                if((tab[pisteur->x-1][pisteur->y]>0) && (tab[pisteur->x-1][pisteur->y]<16) && (pisteur->x-1 >= 0))
                {
                    printf("le pisteur %d a trouve des trace en case %d d une fraicheur de %d",tab[pisteur->x][pisteur->y]-50,i+1,tab[pisteur->x-1][pisteur->y]);
                    gotoxy(41+pisteur->y,10+pisteur->x-1);
                    printf("o");

                }else if(tab[pisteur->x-1][pisteur->y]==16){
                    gotoxy(41+pisteur->y,10+pisteur->x-1);
                    printf("M");
                    gotoxy(0,1+i);

                    printf("attention! le monstre est dans la case %d\n",i+1);
                    tire();

                }else{
                    printf("le pisteur %d n a rien dans la case %d\n",tab[pisteur->x][pisteur->y]-50,i+1);
                }
                break;


             case 2:
                if((tab[pisteur->x-1][pisteur->y+1]>0) && (tab[pisteur->x-1][pisteur->y+1]<16) && (pisteur->x-1 >= 0) && (pisteur->y+1 <= 28))
                {
                    printf("le pisteur %d a trouve des trace en case %d d une fraicheur de %d",tab[pisteur->x][pisteur->y]-50,i+1,tab[pisteur->x-1][pisteur->y+1]);
                    gotoxy(41+pisteur->y+1,10+pisteur->x-1);
                    printf("o");

                }else if(tab[pisteur->x-1][pisteur->y+1]==16){
                    gotoxy(41+pisteur->y+1,10+pisteur->x-1);
                    printf("M");
                    gotoxy(0,1+i);

                    printf("attention! le monstre est dans la case %d\n",i+1);
                    tire();

                }else{
                    printf("le pisteur %d n a rien dans la case %d\n",tab[pisteur->x][pisteur->y]-50,i+1);
                }
                break;


             case 3:
                if((tab[pisteur->x][pisteur->y+1]>0) && (tab[pisteur->x][pisteur->y+1]<16) && (pisteur->y+1 <= 28))
                {
                    printf("le pisteur %d a trouve des trace en case %d d une fraicheur de %d",tab[pisteur->x][pisteur->y]-50,i+1,tab[pisteur->x][pisteur->y+1]);
                    gotoxy(41+pisteur->y+1,10+pisteur->x);
                    printf("o");

                }else if(tab[pisteur->x][pisteur->y+1]==16){
                    gotoxy(41+pisteur->y+1,10+pisteur->x);
                    printf("M");
                    gotoxy(0,1+i);

                    printf("attention! le monstre est dans la case %d\n",i+1);
                    tire();

                }else{
                    printf("le pisteur %d n a rien dans la case %d\n",tab[pisteur->x][pisteur->y]-50,i+1);
                }
                break;


             case 4:
                if((tab[pisteur->x+1][pisteur->y+1]>0) && (tab[pisteur->x+1][pisteur->y+1]<16) && (pisteur->x+1 <= 13) && (pisteur->y+1 <= 28))
                {
                    printf("le pisteur %d a trouve des trace en case %d d une fraicheur de %d",tab[pisteur->x][pisteur->y]-50,i+1,tab[pisteur->x+1][pisteur->y+1]);
                    gotoxy(41+pisteur->y+1,10+pisteur->x+1);
                    printf("o");

                }else if(tab[pisteur->x+1][pisteur->y+1]==16){
                    gotoxy(41+pisteur->y+1,10+pisteur->x+1);
                    printf("M");
                    gotoxy(0,1+i);

                    printf("attention! le monstre est dans la case %d\n",i+1);
                    tire();

                }else{
                    printf("le pisteur %d n a rien dans la case %d\n",tab[pisteur->x][pisteur->y]-50,i+1);
                }
                break;


             case 5:
                if((tab[pisteur->x+1][pisteur->y]>0) && (tab[pisteur->x+1][pisteur->y]<16) && (pisteur->x+1 <= 13))
                {
                    printf("le pisteur %d a trouve des trace en case %d d une fraicheur de %d",tab[pisteur->x][pisteur->y]-50,i+1,tab[pisteur->x+1][pisteur->y]);
                    gotoxy(41+pisteur->y,10+pisteur->x+1);
                   printf("o");

                }else if(tab[pisteur->x+1][pisteur->y]==16){
                    gotoxy(41+pisteur->y,10+pisteur->x+1);
                    printf("M");
                    gotoxy(0,1+i);

                    printf("attention! le monstre est dans la case %d\n",i+1);
                    tire();

                }else{
                    printf("le pisteur %d n a rien dans la case %d\n",tab[pisteur->x][pisteur->y]-50,i+1);
                }
                break;


             case 6:
                if((tab[pisteur->x+1][pisteur->y-1]>0) && (tab[pisteur->x+1][pisteur->y-1]<16) && (pisteur->x+1 <= 13) && (pisteur->y-1 >= 0))
                {
                    printf("le pisteur %d a trouve des trace en case %d d une fraicheur de %d",tab[pisteur->x][pisteur->y]-50,i+1,tab[pisteur->x+1][pisteur->y-1]);
                    gotoxy(41+pisteur->y-1,10+pisteur->x+1);
                    printf("o");

                }else if(tab[pisteur->x+1][pisteur->y-1]==16){
                    gotoxy(41+pisteur->y-1,10+pisteur->x+1);
                    printf("M");
                    gotoxy(0,1+i);

                    printf("attention! le monstre est dans la case %d\n",i+1);
                    tire();

                }else{
                    printf("le pisteur %d n a rien dans la case %d\n",tab[pisteur->x][pisteur->y]-50,i+1);
                }
                break;


             case 7:
                if((tab[pisteur->x][pisteur->y-1]>0) && (tab[pisteur->x][pisteur->y-1]<16) && (pisteur->y-1 >= 0))
                {
                    printf("le pisteur %d a trouve des trace en case %d d une fraicheur de %d",tab[pisteur->x][pisteur->y]-50,i+1,tab[pisteur->x][pisteur->y-1]);
                    gotoxy(41+pisteur->y-1,10+pisteur->x);
                    printf("o");

                }else if(tab[pisteur->x][pisteur->y-1]==16){
                    gotoxy(41+pisteur->y-1,10+pisteur->x);
                    printf("M");
                    gotoxy(0,1+i);

                    printf("attention! le monstre est dans la case %d\n",i+1);
                    tire();

                }else{
                    printf("le pisteur %d n a rien dans la case %d\n",tab[pisteur->x][pisteur->y]-50,i+1);
                }
                break;
        }
    }
}

void tire()// procedure permetant de tirer sur la creature sur cerataine condition
{
    int rand;
    char c;

    gotoxy(0,10);
    fflush(stdin);
    printf("entree T pour tirer sur le monstre\n");
    scanf("%c",&c);

     if (c != 't')

        {
            do{
                    fflush(stdin);
                printf("entree T pour tirer sur le monstre \n");
                scanf("%c",&c);
            }while(c != 't');
        }
    rand = getRando(9);

    if ((rand >= 0) && (rand < 4))
    {
        printf("bravo, votre pisteur a blesse la creature");
        vie_monstre -=1;
        monstre_blesse = 4;
    }else{
        printf("mince, vous l avez rate de peu");
    }
    getchar();

}

void deplacementPisteur(coordonne *pisteur,int tab[14][29])// procedure de deplacement du pisteur
{
    int x,y;
    int z ;

    system("cls");
    afficheTableau(tab);
    gotoxy(41+pisteur->y,10+pisteur->x);
    printf("?");

    gotoxy(0,0);
    fflush(stdin);

    printf("de combien de case souhaitez vous deplacez le pisteur %d (1 - 4)\n",tab[pisteur->x][pisteur->y]-50);
    scanf("%d",&x);

     if ((x < 1) || (x > 4))

        {
            do{
                    fflush(stdin);
                printf("mauvaise valeur, choisissez entre 1 et 4\n");
                scanf("%d",&x);
            }while((x < 1) || (x > 4));
        }

     fflush(stdin);
     printf("dans quelle direction souhaitez vous deplacer le pisteur %d (1:haut | 2:droite | 3:bas | 4:gauche)\n",tab[pisteur->x][pisteur->y]-50);
     scanf("%d",&y);

     if ((y < 1) || (y > 4))

        {
            do{
                    fflush(stdin);
                printf("mauvaise valeur, choisissez entre 1 et 4 (1:haut | 2:droite | 3:bas | 4:gauche)\n");
                scanf("%d",&y);
            }while((y < 1) || (y > 4));
        }
        z=1;

    switch (y)
    {

        case 1 :

            if ((pisteur->x - x)<0)
            {
                fflush(stdin);
                z = 0;
            }else if((tab[pisteur->x-x][pisteur->y] == 16) || (tab[pisteur->x-x-1][pisteur->y]==16) || (tab[pisteur->x-x][pisteur->y+1]==16) || (tab[pisteur->x-x+1][pisteur->y]==16) || (tab[pisteur->x-x][pisteur->y-1]==16) )
            {
                fflush(stdin);
                    z = 2;

            }else{
                for (int i =1;i<x+1;i++)
                {
                    fflush(stdin);
                     if ((tab[pisteur->x-i][pisteur->y] >50) && (tab[pisteur->x-i][pisteur->y] <61))
                     {
                         z =0;
                     }else if (tab[pisteur->x-i][pisteur->y] ==16)
                     {
                          z = 2;
                     }
                }
            }
            break;

        case 2 :

            if ((pisteur->y + x)>28)
            {
                fflush(stdin);
                z = 0;
            }else if((tab[pisteur->x][pisteur->y+x] == 16) || (tab[pisteur->x-1][pisteur->y+x]==16) || (tab[pisteur->x][pisteur->y+x+1]==16) || (tab[pisteur->x+1][pisteur->y+x]==16) || (tab[pisteur->x][pisteur->y+x-1]==16) )
            {
                fflush(stdin);
                    z = 2;

            }else{
                for (int i =1;i<x+1;i++)
                {
                    fflush(stdin);
                     if ((tab[pisteur->x][pisteur->y+i] >50) && (tab[pisteur->x][pisteur->y+i] <61))
                     {
                         z =0;
                     }else if (tab[pisteur->x][pisteur->y+i] == 16)
                     {
                         z = 2;
                     }
                }
            }
            break;

        case 3 :

            if ((pisteur->x + x)>13)
            {
                fflush(stdin);
                z = 0;
            }else if((tab[pisteur->x+x][pisteur->y] == 16) || (tab[pisteur->x+x-1][pisteur->y]==16) || (tab[pisteur->x+x][pisteur->y+1]==16) || (tab[pisteur->x+x+1][pisteur->y]==16) || (tab[pisteur->x+x][pisteur->y-1]==16) )
            {
                fflush(stdin);
                    z = 2;

            }else{
                for (int i =1;i<x+1;i++)
                {
                    fflush(stdin);
                     if ((tab[pisteur->x+i][pisteur->y] >50) && (tab[pisteur->x+i][pisteur->y] <61))
                     {
                         z =0;
                     }else if (tab[pisteur->x+i][pisteur->y] ==16)
                     {
                         z = 2;
                     }
                }
            }
            break;

        case 4 :

            if ((pisteur->y - x)<0)
            {
                fflush(stdin);
                z = 0;
            }else if((tab[pisteur->x][pisteur->y-x] == 16) || (tab[pisteur->x-1][pisteur->y-x]==16) || (tab[pisteur->x][pisteur->y-x+1]==16) || (tab[pisteur->x+1][pisteur->y-x]==16) || (tab[pisteur->x][pisteur->y-x-1]==16) )
            {
                fflush(stdin);
                    z = 2;

            }else{
                for (int i =1;i<x+1;i++)
                {
                    fflush(stdin);
                     if ((tab[pisteur->x][pisteur->y-i] >50) && (tab[pisteur->x][pisteur->y-i] <61))
                     {
                         z =0;
                     }else if (tab[pisteur->x][pisteur->y-i] == 16)
                     {
                         z = 2;
                     }
                }
            }
            break;

    }

    fflush(stdin);
    if (z ==0)
    {
        fflush(stdin);
        printf("deplacement impossible");
        getchar();
        deplacementPisteur(pisteur,tab);

    }else if(z == 2)
    {
        fflush(stdin);
        system("cls");
        printf("oh non! le pisteur %d c est jeter dans la gueule du loup",tab[pisteur->x][pisteur->y]-50);
        tab[pisteur->x][pisteur->y]=0;
        afficheTableau(tab);
        getchar();
        nb_pisteur-=1;


    }else{

        for (int i =0;i<x;i++)
        {
            fflush(stdin);

            switch (y)
            {
                case 1 :

                    tab[pisteur->x-1][pisteur->y] = tab[pisteur->x][pisteur->y];
                    tab[pisteur->x][pisteur->y] = 103+i;
                    pisteur->x-=1;
                    break;

                case 2 :
                    tab[pisteur->x][pisteur->y+1] = tab[pisteur->x][pisteur->y];
                    tab[pisteur->x][pisteur->y] = 103+i;
                    pisteur->y+=1;
                    break;

                case 3 :
                    tab[pisteur->x+1][pisteur->y] = tab[pisteur->x][pisteur->y];
                    tab[pisteur->x][pisteur->y] = 103+i;
                    pisteur->x+=1;
                    break;

                case 4 :
                    tab[pisteur->x][pisteur->y-1] = tab[pisteur->x][pisteur->y];
                    tab[pisteur->x][pisteur->y] = 103+i;
                    pisteur->y-=1;
                    break;

            }
        }
    }

}

void sdlAffiche (int tab[14][29])
{
    //SDL_Rect src ={0, 0, 0, 0};
    SDL_Rect dst={ 0, 0, 25, 25 };

    SDL_Surface* image = IMG_Load("./image/caillou.JPG");
    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);
    SDL_FreeSurface(image);

    SDL_SetRenderDrawColor(pRenderer, 0, 0, 230, 255);
    SDL_RenderClear(pRenderer);

    for (int i = 1;i<30;i++)
    {
        dst.y=0;
        dst.x = 25*i;
        SDL_RenderCopy(pRenderer, pTextureImage, NULL,&dst); // Affiche ma texture sur touts l'écran

         dst.y=375;
        SDL_RenderCopy(pRenderer, pTextureImage, NULL,&dst);

    }
    for (int i = 1;i<15;i++)
    {
        dst.x = 0;
        dst.y=25*i;

        SDL_RenderCopy(pRenderer, pTextureImage, NULL,&dst); // Affiche ma texture sur touts l'écran

        dst.x = 750;

        SDL_RenderCopy(pRenderer, pTextureImage, NULL,&dst);

    }

        dst.x = 25;
        dst.y = 25;


     for (int i = 0; i<14;i++)
    {
        dst.x = 25;

        for (int j = 0; j<29;j++)
        {
            if (tab[i][j]== 16)
            {
                   SDL_Surface* image = IMG_Load("./image/mort.PNG");
                    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);
                    SDL_FreeSurface(image);

                    SDL_RenderCopy(pRenderer, pTextureImage, NULL,&dst);

            }else if ((tab[i][j]>50 ) && (tab[i][j]<61 ))
            {
                    SDL_Surface* image = IMG_Load("./image/pisteur.PNG");
                    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);
                    SDL_FreeSurface(image);

                    SDL_RenderCopy(pRenderer, pTextureImage, NULL,&dst);
            }else{
                    SDL_Surface* image = IMG_Load("./image/buisson.PNG");
                    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);
                    SDL_FreeSurface(image);

                    SDL_RenderCopy(pRenderer, pTextureImage, NULL,&dst);

            }
            dst.x+=25;
        }
         dst.y+=25;
    }



    SDL_RenderPresent(pRenderer);

}


void intialisationPisteur()// procedure permettant la saisie du nombre de pisteur
{
    printf("combien voulez vous de pisteur (10 maximum)\n");
    scanf("%d",&nb_pisteur);
    system("cls");

    if ((nb_pisteur < 1) || (nb_pisteur >10))
    {
         do{
            fflush(stdin);
            printf("mauvaise valeur, choisissez un nombre entre 1 et 10 \n");
            scanf("%d",&nb_pisteur);
            system("cls");
        }while((nb_pisteur < 1) || (nb_pisteur >10));
    }
}

void afficheTableau(int tab[14][29])// procedure permettant d'afficher le tableau de jeu ainsi que l interface
{
    fflush(stdin);
    int w = 10;

   gotoxy(40,9);
   printf("*******************************");

   for (int i = 0;i<15;i++)
   {
       gotoxy(40,9+i);
       printf("*");
   }



   for (int i = 0; i<14;i++)
    {
        fflush(stdin);
        gotoxy(41,w++);

        for (int j = 0; j<29;j++)
        {
            if ((tab[i][j]>50)&& (tab[i][j]<61) )
            {
                printf("P");
            }/*else if(tab[i][j]==16){
            printf("M");}
            */else if((tab[i][j]==14) && (monstre_blesse>0) ){
            printf("x");
            }/*else if(tab[i][j]>99){
            printf("x");
            }*/else{
            printf(" ");
            }
        }
    }

    for (int i = 0;i<15;i++)
   {
       gotoxy(70,9+i);
       printf("*");
   }

    gotoxy(40,24);
    printf("*******************************");

    gotoxy(40,25);
    printf("pisteur: %d",nb_pisteur);
    gotoxy(40,26);
    printf("vie du monstre: %d",vie_monstre);

    gotoxy(75,10);
    printf("les cases de verification des pisteurs :");

    gotoxy(85,12);
    printf("1 2 3 ");
    gotoxy(85,13);
    printf("8 P 4 ");
    gotoxy(85,14);
    printf("7 6 5 ");

    gotoxy(0,1);
sdlAffiche (tab);


}

void gotoxy(short x, short y)//procedure permettant de creer le gotoxy
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Pos={x,y};
    SetConsoleCursorPosition(hConsole,Pos);
}

void initialisationTableau(int tab[14][29])//procedure permettant d initialiser tout le tableau de jeu a 0
{
    for (int i = 0; i<14;i++)
    {
        for (int j = 0; j<29;j++)
        {
            tab[i][j]=0;
        }
    }
}

void placementPisteur(int tab[14][29]) //procedure permettant de mettre en place le placement des pisteurs
{

    for (int i=0;i<nb_pisteur;i++)
    {

        verifCoordPisteur(tab,i);

        afficheTableau(tab);

    }
}

void verifCoordPisteur(int tab[14][29],int nbpist)//procedure permettant de saisie des coordonné des pisteurs et verification de l emplacement donnés
{
     int x=0;
     int y=0;

        fflush(stdin);
        gotoxy(0,0);
        printf("choisissez la colone du pisteur %d (entre 1 - 29)\n",nbpist+1);
        afficheTableau(tab);
        scanf("%d",&y);
        system("cls");

        if ((y < 1) || (y >29))
        {
            do{
                printf("mauvaise valeur, choisissez un nombre entre 1 et 29 \n");
                afficheTableau(tab);
                scanf("%d",&y);
                system("cls");
            }while((y < 1) || (y >29));
        }
        y -=1;

        printf("choisissez la ligne du pisteur %d (entre 1 - 14)\n",nbpist+1);
        afficheTableau(tab);
        scanf("%d",&x);
        system("cls");

        if ((x < 1) || (x >14))
        {
            do{
                printf("mauvaise valeur, choisissez un nombre entre 1 et 14 \n");
                afficheTableau(tab);
                scanf("%d",&x);
                system("cls");
            }while((x < 1) || (x >14));
        }
        x -=1;

        system("cls");

        if (tab[x][y]==0)
        {
            tab[x][y]=50 + nbpist+1;
        }else{
            gotoxy(0,2);
            printf("coordonnee deja prise, veuillez recomencer");

            verifCoordPisteur(tab,nbpist);
        }
}
