
/*
*Autor: Junior Fomba Tagang
*Aufgabe: Spiel (Le Pendu)
*Datum: ab November 2020
*Bemerkung: Variablen, Funktionen und Ausgaben wurden auf Franzoesisch geschrieben, Kommatare sind aber auf Deutsch
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

int piocherMot(char* motSecret);
int numAleatoire(int nombreMot);
void viderBuffer();
int lire(char *chaine, int longueur);
long lireLong(char *chaine, int longueur);
int gagnePartie(int lettreTrouvee[], int taillemot);
char lireCaractere();
int rechercheCaractere(char lettre, char motSecret[], int lettreTrouvee[]);
void maskPasswort(char pass[]);

int main(int argc, char* argv[])
{
    FILE *sauvegarde=NULL;
    int coupsRestants=0;
    int *lettreTrouvee=NULL;
    char motSecret[100]={0};
    int i=0;
    char lettre=0;
    int tailleMot=0;
    long recommencerPartie=1;
    char chaineRP[100]={0};
    int nombreCoups=0;
    long nombreJoueurs=0;
    char chaineNJ[100]={0};
    long niveauDeDifficulte=0;
    char chaineND[100]={0};
    char nomJoueur[100]={0};

    while(recommencerPartie==1)
    {
    printf("\n\nBIENVENUE DANS LE PENDU!\n\nCeci est un jeu cree par le logger.\nLe but du jeu est de trouver le mot mystere\nTu as un nombre d'essais limite pour trouver le mot mystere.\nTu propose une lettre et si cette lettre fait partie du mot mystere, ton nombre de coups ne diminue pas.\nSinon le nombre de coups diminue.\nLe mot secret est en majuscule.\n\n");
    printf("       _____        \n");
    printf("       |. .|        \n");
    printf("       | . |        \n");
    printf("       |_V_|        \n");
    printf("       __|__        \n");
    printf("       | | |        \n");
    printf("       | | |        \n");
    printf("      _| | |_       \n");
    printf("        _|_         \n");
    printf("        | |         \n");
    printf("        | |         \n");
    printf("        | |         \n");
    printf("        | |         \n");
    printf("       _| |_        \n");
    nombreJoueurs=0;
    niveauDeDifficulte=0;
    nombreCoups=0;


    printf("\nQuel est votre nom? : ");
    lire(nomJoueur,100);


    printf("\n\n===NOMBRE DE JOUEUR===\n1. UN JOUEUR : La machine choisi le nombre mystere au hasard et le joueur devine.\n2. DEUX JOUEURS : Un joueur choisi le nombre mystere et l'autre devine.\nChoisis le nombre de joueurs : ");
    while(nombreJoueurs!=1 && nombreJoueurs!=2)
    {
        printf("\nTu dois taper 1 ou 2 : ");
        nombreJoueurs=lireLong(chaineNJ,100);
    }

    printf("\n\n===NIVEAU DE DIFFICULTE===\n1. FACILE : Tu as 20 essais pour trouver le nombre mystere.\n2. MOYEN : Tu as 10 essais pour trouver le nombre mystere.\n3. DIFFICILE : Tu as 5 essais pour trouver le nombre mystere.\nChoisis le niveau de difficulte : ");
while(niveauDeDifficulte!=1 && niveauDeDifficulte!=2 && niveauDeDifficulte!=3)
{
    printf("\nTu dois taper 1, 2 ou 3 : ");
    niveauDeDifficulte=lireLong(chaineND,100);
}

    if(nombreJoueurs==1 && niveauDeDifficulte==1)
    {
        coupsRestants=20;

    if(!piocherMot(motSecret))
    {
        exit(0);
    }
    tailleMot=strlen(motSecret);
    lettreTrouvee= malloc(tailleMot*sizeof(int));
    if(lettreTrouvee==NULL)
    {
        exit(0);
    }
    for(i=0; i<tailleMot; i++)
    {
        lettreTrouvee[i] = 0;
    }
    while(coupsRestants>0 && !gagnePartie(lettreTrouvee, tailleMot))
    {

        printf("\nIl vous reste %d coups a jouer!", coupsRestants);
        printf("\nQuel est le mot secret ? ");
        for(i=0; i<tailleMot; i++)
        {
            if(lettreTrouvee[i])
            printf("%c",motSecret[i]);
            else
            printf("*");
        }
        printf("\nProposez une lettre : ");
        lettre=lireCaractere();
        nombreCoups++;
        if(!rechercheCaractere(lettre, motSecret, lettreTrouvee))
        {
            coupsRestants--;
        }
            switch(coupsRestants)
    {
        case 19:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("       _| |_        \n");
            break;
        case 18:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            break;
            case 15:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            break;
             case 13:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            break;
            case 10:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            break;
           case 9:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            break;
           case 8:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            break;
            case 5:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            break;
             case 3:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            break;
            case 2:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            break;

             case 0:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            break;
    }

    }
        if(gagnePartie(lettreTrouvee, tailleMot))
        {
            printf("\nGagne ! Le mot secret etait bel et bien : %s", motSecret);
            printf("\n\nVous avez trouvez le mot mystere en %d coups!\n", nombreCoups);
        }
        else
        {
            printf("\n Vous avez perdu! Vous etes pendu! Le mot secret etait :%s ", motSecret);
        }
        free(lettreTrouvee);
    }
    if(nombreJoueurs==1 && niveauDeDifficulte==2)
    {
        coupsRestants=10;

    if(!(piocherMot(motSecret)))
    {
        exit(0);
    }
    tailleMot=strlen(motSecret);
    lettreTrouvee= malloc(tailleMot*sizeof(int));
    for(i=0;i<tailleMot;i++)
    {
        lettreTrouvee[i]=0;
    }
    while(coupsRestants>0 && !gagnePartie(lettreTrouvee, tailleMot))
    {
        printf("\nIl vous reste %d coups a jouer!", coupsRestants);
        printf("\nQuel est le mot secret ? ");
        for(i=0; i<tailleMot; i++)
        {
            if(lettreTrouvee[i])
            printf("%c",motSecret[i]);
            else
            printf("*");
        }
        printf("\nProposez une lettre : ");
        lettre=lireCaractere();
        nombreCoups++;

        if(!rechercheCaractere(lettre, motSecret, lettreTrouvee))
        {

            coupsRestants--;
        }
             switch(coupsRestants)
    {
        case 9:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("       _| |_        \n");
            break;

            case 8:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            break;
             case 7:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            break;
            case 6:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            break;
           case 5:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            break;
           case 4:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            break;
            case 3:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            break;
             case 2:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            break;
            case 1:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            break;

             case 0:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            break;
    }

    }
        if(gagnePartie(lettreTrouvee, tailleMot))
        {
            printf("\nGagne ! Le mot secret etait bel et bien : %s", motSecret);
            printf("\n\nVous avez trouvez le mot mystere en %d coups!\n", nombreCoups);
        }
        else
        {
            printf("\n Vous avez perdu! Vous etes pendu! Le mot secret etait :%s", motSecret);
        }
        free(lettreTrouvee);
    }


     if(nombreJoueurs==1 && niveauDeDifficulte==3)
    {
        coupsRestants=5;

    if(!(piocherMot(motSecret)))
    {
        exit(0);
    }
    tailleMot=strlen(motSecret);
    lettreTrouvee= malloc(tailleMot*sizeof(int));
    for(i=0;i<tailleMot;i++)
    {
        lettreTrouvee[i]=0;
    }
    while(coupsRestants>0 && !gagnePartie(lettreTrouvee, tailleMot))
    {
        printf("\nIl vous reste %d coups a jouer!", coupsRestants);
        printf("\nQuel est le mot secret ? ");
        for(i=0; i<tailleMot; i++)
        {
            if(lettreTrouvee[i])
            printf("%c",motSecret[i]);
            else
            printf("*");
        }
        printf("\nProposez une lettre : ");
        lettre=lireCaractere();
        nombreCoups++;
        if(!rechercheCaractere(lettre, motSecret, lettreTrouvee))
        {

            coupsRestants--;
        }
            switch(coupsRestants)
        {
         case 5:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            break;

            case 3:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            break;
             case 2:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            break;
            case 1:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            break;

             case 0:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            break;
    }

    }
        if(gagnePartie(lettreTrouvee, tailleMot))
        {
            printf("\nGagne ! Le mot secret etait bel et bien : %s", motSecret);
            printf("\n\nVous avez trouvez le mot mystere en %d coups!\n", nombreCoups);
        }
        else
        {
            printf("\n Vous avez perdu! Vous etes pendu! Le mot secret etait :%s", motSecret);
        }
        free(lettreTrouvee);
    }
    if(nombreJoueurs==2 && niveauDeDifficulte==1)
    {
        coupsRestants=20;

    printf("\nLe premier joueur entre le mot secret : ");
    maskPasswort(motSecret);
    tailleMot=strlen(motSecret);
    for(i=0; i<tailleMot; i++)
    {
        motSecret[i]=toupper(motSecret[i]);
    }
    lettreTrouvee= malloc(tailleMot*sizeof(int));
    for(i=0;i<tailleMot;i++)
    {
        lettreTrouvee[i]=0;
    }
    while(coupsRestants>0 && !gagnePartie(lettreTrouvee, tailleMot))
    {
        printf("\nJoueur 2, il vous reste %d coups a jouer!", coupsRestants);
        printf("\nQuel est le mot secret ? ");
        for(i=0; i<tailleMot; i++)
        {
            if(lettreTrouvee[i])
            printf("%c",motSecret[i]);
            else
            printf("*");
        }
        printf("\nProposez une lettre : ");
        lettre=lireCaractere();
        nombreCoups++;
        if(!rechercheCaractere(lettre, motSecret, lettreTrouvee))
        {

            coupsRestants--;
        }
            switch(coupsRestants)
    {
        case 19:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("       _| |_        \n");
            break;
        case 18:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            break;
            case 15:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            break;
             case 13:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            break;
            case 10:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            break;
           case 9:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            break;
           case 8:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            break;
            case 5:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            break;
             case 3:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            break;
            case 2:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            break;

             case 0:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            break;
    }

    }
        if(gagnePartie(lettreTrouvee, tailleMot))
        {
            printf("\nGagne ! Le mot secret etait bel et bien : %s", motSecret);
            printf("\n\nVous avez trouvez le mot mystere en %d coups!\n", nombreCoups);
        }
        else
        {
            printf("\n Vous avez perdu! Vous etes pendu! Le mot secret etait :%s", motSecret);
        }
        free(lettreTrouvee);
    }
    if(nombreJoueurs==2 && niveauDeDifficulte==2)
    {
        coupsRestants=10;

    printf("\nLe premier joueur entre le mot secret: ");
    maskPasswort(motSecret);
    tailleMot=strlen(motSecret);
    for(i=0; i<tailleMot; i++)
    {
        motSecret[i]=toupper(motSecret[i]);
    }
    lettreTrouvee= malloc(tailleMot*sizeof(int));
    for(i=0;i<tailleMot;i++)
    {
        lettreTrouvee[i]=0;
    }
    while(coupsRestants>0 && !gagnePartie(lettreTrouvee, tailleMot))
    {
        printf("\nJoueur 2, il vous reste %d coups a jouer!", coupsRestants);
        printf("\nQuel est le mot secret ? ");
        for(i=0; i<tailleMot; i++)
        {
            if(lettreTrouvee[i])
            printf("%c",motSecret[i]);
            else
            printf("*");
        }
        printf("\nProposez une lettre : ");
        lettre=lireCaractere();
        nombreCoups++;
        if(!rechercheCaractere(lettre, motSecret, lettreTrouvee))
        {

            coupsRestants--;
        }
             switch(coupsRestants)
    {
        case 9:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("       _| |_        \n");
            break;

            case 8:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            break;
             case 7:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            printf("        | |         \n");
            break;
            case 6:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            printf("        | |         \n");
            break;
           case 5:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            break;
           case 4:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            break;
            case 3:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            break;
             case 2:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            break;
            case 1:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            break;

             case 0:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            break;
    }

    }
        if(gagnePartie(lettreTrouvee, tailleMot))
        {
            printf("\nGagne ! Le mot secret etait bel et bien : %s", motSecret);
            printf("\n\nVous avez trouvez le mot mystere en %d coups!\n", nombreCoups);
        }
        else
        {
            printf("\n Vous avez perdu! Vous etes pendu! Le mot secret etait :%s", motSecret);
        }
        free(lettreTrouvee);
    }
    if(nombreJoueurs==2 && niveauDeDifficulte==3)
    {
        coupsRestants=5;

    printf("\nLe premier joueur entre le mot secret : ");
    maskPasswort(motSecret);
    tailleMot=strlen(motSecret);
    for(i=0; i<tailleMot; i++)
    {
        motSecret[i]=toupper(motSecret[i]);
    }
    lettreTrouvee= malloc(tailleMot*sizeof(int));
    for(i=0;i<tailleMot;i++)
    {
        lettreTrouvee[i]=0;
    }
    while(coupsRestants>0 && !gagnePartie(lettreTrouvee, tailleMot))
    {
        printf("\nJoueur 2, il vous reste %d coups a jouer!", coupsRestants);
        printf("\nQuel est le mot secret ? ");
        for(i=0; i<tailleMot; i++)
        {
            if(lettreTrouvee[i])
            printf("%c",motSecret[i]);
            else
            printf("*");
        }
        printf("\nProposez une lettre : ");
        lettre=lireCaractere();
        nombreCoups++;
        if(!rechercheCaractere(lettre, motSecret, lettreTrouvee))
        {

            coupsRestants--;
        }
            switch(coupsRestants)
        {
         case 4:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            printf("      _| | |_       \n");
            printf("        _|_         \n");
            break;

            case 3:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            printf("       | | |        \n");
            break;
             case 2:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            printf("       | | |        \n");
            break;
            case 1:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            printf("       __|__        \n");
            break;

             case 0:
            printf("       _____        \n");
            printf("       |. .|        \n");
            printf("       | . |        \n");
            printf("       |_-_|        \n");
            break;
    }

    }
        if(gagnePartie(lettreTrouvee, tailleMot))
        {
            printf("\nGagne ! Le mot secret etait bel et bien : %s", motSecret);
            printf("\n\nVous avez trouvez le mot mystere en %d coups!\n", nombreCoups);
        }
        else
        {
            printf("\n Vous avez perdu! Vous etes pendu! Le mot secret etait :%s", motSecret);
        }
        free(lettreTrouvee);

    }

        printf("\n\nSi vous voulez voir les caracteristiques des parties precedentes, ouvrez le fichier : VOLTAGE situe dans le dossier d'installation du jeu\n");
        printf("\nSi vous voulez rejouer tapez 1 sinon tapez 0! ");
        recommencerPartie=lireLong(chaineRP,100);
        while(recommencerPartie!=0 && recommencerPartie!=1)
        {
            printf("\nVous devez tapez 0 ou 1!\n");
            recommencerPartie=lireLong(chaineRP,100);
        }
        sauvegarde=fopen("VOLTAGE", "a");
        if(sauvegarde!=NULL)
        {
            fprintf(sauvegarde, "\nLa partie a ete jouee par %s.\nLe nombre de joueur etait %ld.\nLe nombre de coups restants etait %d.\nLe niveau de difficulte etait %ld.\nLe mot secret etait %s.\n", nomJoueur, nombreJoueurs, coupsRestants, niveauDeDifficulte, motSecret);
            fclose(sauvegarde);
        }
        }

    return 0;
}

void viderBuffer()
{
int c = 0;
while (c != '\n' && c != EOF)
{
c = getchar();
}
}

int lire(char *chaine, int longueur)
{
char *positionEntree = NULL;
if (fgets(chaine, longueur, stdin) != NULL)
{
positionEntree = strchr(chaine, '\n');
if (positionEntree != NULL)
{
*positionEntree = '\0';
}
else
{
viderBuffer();
}
return 1;
}
else
{
viderBuffer();
return 0;
}
}

long lireLong(char *chaine, int longueur)
{
    if(lire(chaine, longueur))
    {
        return strtol(chaine, NULL, 10);
    }
    else
    {
        return 0;
    }
}

int piocherMot(char* motSecret)
{
    int nombreMot=0;
    FILE *dico=NULL;
    int numMot=0;
    char caractereLu=0;
    dico=fopen("dico.txt","r");
    if(dico==NULL)
    {
        printf("\n\nImpossible d'ouvrir le dictionnaire de mot\n");
        return 0;
    }
    do
    {
        caractereLu=fgetc(dico);
        if(caractereLu=='\n')
        {
            nombreMot++;
        }
    }while(caractereLu!=EOF);
    numMot=numAleatoire(nombreMot);
    rewind(dico);
    while(numMot>0)
    {
        caractereLu=fgetc(dico);
        if(caractereLu=='\n')
        {
            numMot--;
        }
    }
    fgets(motSecret, 100, dico);
    motSecret[strlen(motSecret)-1]='\0';
    fclose(dico);

    return 1;
}

int numAleatoire(int nombreMot)
{
    srand(time(NULL));
    return (rand()% (nombreMot+1));
}

int gagnePartie(int lettreTrouvee[], int tailleMot)
{
    int gagne=1;
    int i=0;
    for(i=0; i<tailleMot; i++)
    {
    if(lettreTrouvee[i]==0)
    {
        gagne=0;
    }
    }
    return gagne;
}

char lireCaractere()
{
    char caractere=0;
    caractere=getchar();
    caractere=toupper(caractere);
    while(getchar()!='\n');
    return caractere;
}

int rechercheCaractere(char lettre, char motSecret[], int lettreTrouvee[])
{
    int i=0;
    int trouvee=0;
    for(i=0; motSecret[i] !='\0'; i++)
    {
        if(lettre==motSecret[i])
        {
            trouvee=1;
            lettreTrouvee[i]=1;
        }
    }
    return trouvee;
}

void maskPasswort(char pass[]){
    char ch;
    int i = 0;

    while(1){
        ch = getch();
        if(ch == ENTER){
            pass[i] = '\0';
            break;
        }
        else if(ch == BKSP){
            if(i>0){
                i--;
                printf("\b \b");
            }
        }
        else if(ch == TAB || ch == SPACE){
            continue;
        }
        else{
            pass[i] = ch;
            i++;
            printf("*");
        }
    }
}


