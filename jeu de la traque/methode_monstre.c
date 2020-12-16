#include "define.h"

int getRando(int nb) //initialisation du random
{
    //time_t t;
    return (rand()%nb);
}

void placementMonstre(int tab[14][29],coordonne *monstre)// procedure permettant le placement du monstre de maniere aleatoire sur le tableau de jeu
{
   int rand1,rand2;

   rand1 = getRando(13);
   rand2 = getRando(28);

   if ((tab[rand1][rand2] !=0) ||(tab[rand1 -1][rand2] !=0) ||(tab[rand1+1][rand2] !=0) ||(tab[rand1][rand2-1] !=0)||(tab[rand1][rand2+1] !=0) )
   {
       fflush(stdin);
       do
       {
        rand1 = getRando(13);
        rand2 = getRando(28);
       }while ((tab[rand1][rand2] ==0) &&(tab[rand1 -1][rand2] ==0) &&(tab[rand1+1][rand2] ==0) &&(tab[rand1][rand2-1] ==0)&&(tab[rand1][rand2+1] ==0) );
   }

   (monstre->x) = rand1;
   (monstre->y) = rand2;
   tab[rand1][rand2] =16;
}

void deplacementMonstre(int tab[14][29],coordonne *monstre)//procedure permettant le deplacement aleatoire ou via le suivie des trace des pisteurs du monstre
{
    coordonne recup;

    fflush(stdin);

    tab[monstre->x][monstre->y] =15;

    if ((tab[monstre->x -1][monstre->y] <=15) &&(tab[monstre->x+1][monstre->y] <=15) &&(tab[monstre->x][monstre->y-1] <=15)&&(tab[monstre->x][monstre->y+1] <=15))
    {
        do
        {
             recup = verifDeplaMonstreRandom (tab,monstre);
        }while ((tab[recup.x][recup.y]>13)   || (recup.x < 1) || (recup.x > 12) || (recup.y < 1) || (recup.y > 27)) ;

    }else if ((tab[monstre->x -1][monstre->y] >=100) || (tab[monstre->x+1][monstre->y] >=100) || (tab[monstre->x][monstre->y-1] >=100) || (tab[monstre->x][monstre->y+1] >=100)){

       if  ((tab[monstre->x -1][monstre->y] > tab[monstre->x+1][monstre->y] ) && (tab[monstre->x -1][monstre->y] > tab[monstre->x][monstre->y-1]) && (tab[monstre->x -1][monstre->y] > tab[monstre->x][monstre->y+1] ) )
       {
           recup.x = monstre->x -1;
           recup.y = monstre->y;
       }else if((tab[monstre->x+1][monstre->y] > tab[monstre->x -1][monstre->y]) && (tab[monstre->x+1][monstre->y] > tab[monstre->x][monstre->y-1] ) && (tab[monstre->x+1][monstre->y] > tab[monstre->x][monstre->y+1] ) )
       {
           recup.x = monstre->x +1;
           recup.y = monstre->y;
       }else if ((tab[monstre->x][monstre->y-1] > tab[monstre->x -1][monstre->y]) && (tab[monstre->x][monstre->y-1] > tab[monstre->x+1][monstre->y] ) && (tab[monstre->x][monstre->y-1] > tab[monstre->x][monstre->y+1]) )
       {
           recup.x = monstre->x;
           recup.y = monstre->y-1;
       }else if((tab[monstre->x][monstre->y+1] > tab[monstre->x -1][monstre->y]) && (tab[monstre->x][monstre->y+1] > tab[monstre->x+1][monstre->y]) && (tab[monstre->x][monstre->y+1] > tab[monstre->x][monstre->y-1] ) )
       {
            recup.x = monstre->x;
           recup.y = monstre->y+1;
       }else{
            do
            {
                recup = verifDeplaMonstreRandom (tab,monstre);
            }while ((tab[recup.x][recup.y]>13)   || (recup.x < 1) || (recup.x > 12) || (recup.y < 1) || (recup.y > 27)) ;
       }
    }


        (monstre->x) = recup.x;
        (monstre->y) = recup.y;
        tab[monstre->x][monstre->y] =16;

}


coordonne verifDeplaMonstreRandom (int tab[14][29],coordonne *monstre)// verification de la coordonée du deplacement aléatoire pour savoir si le monstre ne sors pas du tableau
{
    int rand1,nx,ny,z;
    coordonne renvoi;

    rand1 = getRando(2);
    nx =(monstre->x);
    ny =(monstre->y);


        if (rand1 ==0)
        {
            do
            {
                nx =(monstre->x);
                z = getRando(2);

                if ((z==1) && (nx <13) )
                {
                    nx += 1;
                }else if((z==0) && (nx >0)){
                    nx -= 1;
                }

            }while (((nx < 0) || (nx > 13)));

        }else{

             do
            {
                ny =(monstre->y);
                z = getRando(2);

                if ((z==1) && (ny <28))
                {
                    ny += 1;
                }else if ((z==0) && (ny >0)){
                    ny -= 1;
                }
            }while (((ny < 0) || (ny > 28) ) );
        }
    (renvoi.x) = nx;
    (renvoi.y) = ny;

    return renvoi;

}

void attaqueMonstre (int tab[14][29],coordonne *monstre)// procedure verifiant les case adjacente du monstre et detruit le pisteur a proximité
{

    if (((tab[monstre->x -1][monstre->y] > 50)&&(tab[monstre->x -1][monstre->y] < 61)) || (tab[monstre->x+1][monstre->y] > 50)&&(tab[monstre->x +1][monstre->y] < 61) ||(tab[monstre->x][monstre->y-1] >50)&&(tab[monstre->x][monstre->y-1] < 61)||(tab[monstre->x][monstre->y+1] !=0)&&(tab[monstre->x][monstre->y+1] < 61) )
    {

        if ((tab[monstre->x -1][monstre->y] > 50)&&(tab[monstre->x -1][monstre->y] < 61))
        {
            printf("oh non! le pisteur %d c est fait avoir par la creature\n", tab[monstre->x -1][monstre->y]-50);
            tab[monstre->x -1][monstre->y] = 0;
            nb_pisteur -=1;
        }
        if ((tab[monstre->x +1][monstre->y] > 50)&&(tab[monstre->x +1][monstre->y] < 61))
        {
            printf("oh non! le pisteur %d c est fait avoir par la creature\n", tab[monstre->x +1][monstre->y]-50);
            tab[monstre->x +1][monstre->y]=0;
            nb_pisteur -=1;
        }
        if ((tab[monstre->x ][monstre->y-1] > 50)&&(tab[monstre->x][monstre->y-1] < 61))
        {
            printf("oh non! le pisteur %d c est fait avoir par la creature\n", tab[monstre->x][monstre->y-1]-50);
            tab[monstre->x][monstre->y-1] = 0;
            nb_pisteur -=1;
        }
        if ((tab[monstre->x][monstre->y+1] > 50)&&(tab[monstre->x][monstre->y+1] < 61))
        {
            printf("oh non! le pisteur %d c est fait avoir par la creature\n", tab[monstre->x][monstre->y+1]-50);
            tab[monstre->x][monstre->y+1]=0;
            nb_pisteur -=1;
        }
    }

}

void effacementTrace(int tab[14][29])// procedure d effacement progressifs des traces
{
     for (int v = 0; v<14;v++)
        {
            for (int j = 0; j<29;j++)
            {
                if ((tab[v][j]<=15) && (tab[v][j]>0) )
                {
                    tab[v][j]-=1;
                }
                if (tab[v][j]== -3 )
                {
                    tab[v][j]=0;
                }
                if (tab[v][j]> 99 )
                {
                    tab[v][j]-=1;
                }
                if (tab[v][j]== 99 )
                {
                    tab[v][j]=0;
                }
            }
        }
}
