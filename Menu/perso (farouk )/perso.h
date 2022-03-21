

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

/*typedef struct vie 
{SDL_Surface *vie ;
SDL_Rect posvie ;
} vie ;
typedef struct score 
{SDL_Surface *texte;
SDL_Rect textepos ;
} score ;*/
typedef struct
{//int id;
    SDL_Rect position;
    SDL_Surface *sprite;
    //vie v;
    int score;
    double vitesse;
    double acceleration;
    int sol ;
}personnage;

void initialiser_personnage(personnage *p);

void afficher_perso1(personnage p, SDL_Surface *ecran,SDL_Surface *background,SDL_Rect positionFond);
void animperso (int *i , SDL_Event *event, personnage *p);
void jump (personnage *p);
void deplacerperso (personnage *p,int *continuer, SDL_Event *event);








