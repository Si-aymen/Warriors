
#include "perso.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

void initialiser_personnage(personnage *p)
{
    p->position.x=20;
    p->position.y=200;
    p->position.w=75;
    p->position.h=80;
p->sprite = IMG_Load("c1.png");
  	SDL_SetColorKey(p->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(p->sprite->format, 0, 0, 255));
    p->acceleration=5;
    p->vitesse=9;
    p->score=0;
    p->sol = 200 ;
   
}
void afficher_perso1(personnage p, SDL_Surface *ecran)
{
   
    SDL_BlitSurface (p.sprite,NULL,ecran,&p.position);
    
    
}


void animperso (int *i , SDL_Event *event, personnage *p)
{
 char ch[20];
    SDL_PollEvent(event);
    switch(event->type)
    {case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
        {case SDLK_RIGHT:
                (*i)++;
                if(*i>7)*i=1;
                sprintf(ch,"b%d.png",*i); 
                SDL_Delay(150);
                p->sprite = IMG_Load(ch);
                break;
            case SDLK_LEFT: (*i)++;
                if(*i>7)*i=1;
                sprintf(ch,"c%d.png",*i);
                SDL_Delay(150);
                p->sprite = IMG_Load(ch);
                break;
   
     
        }
        break; }
}


void jump (personnage *p)
{ 
//int gravite = 1 ;
  
while( p->position.y!= p->sol) 
 p->position.y+=p->vitesse;

}

void deplacerperso (personnage *p,int *continuer, SDL_Event *event)
{
    SDL_PollEvent(event);
    switch(event->type)
    {
        case SDL_QUIT:
            (*continuer)=0;
            break;
        case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
        {
            case SDLK_UP:
               if (p->position.y!=450)
                 { p->position.y-=p->vitesse;}
                break;
       
            case SDLK_RIGHT:
                p->position.x+=p->vitesse+p->acceleration*0.2;
                break;
            case SDLK_LEFT:
                p->position.x-=p->vitesse+p->acceleration*0.2;
                break;
                case SDLK_SPACE:
                 p->acceleration = 9;
                p->position.x+=p->vitesse+p->acceleration*0.2;
                break;
        }
            break;
            case SDL_KEYUP :
           if(event->key.keysym.sym==SDLK_UP)
              {
                jump(p);
              }
           if(event->key.keysym.sym==SDLK_RIGHT)
             {while ( p->acceleration !=0)
              { p->acceleration--;
              p->position.x+=p->vitesse+p->acceleration*0.2; ;}
              }
       if(event->key.keysym.sym==SDLK_SPACE)
             {while ( p->acceleration !=0)
              { p->acceleration--;
              p->position.x+=p->vitesse+p->acceleration*0.2; ;}
              } 
            break;

    }
}















