#ifndef background_H_
#define background_H_
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 1366
#define SCREEN_H 678
typedef struct
{
	SDL_Surface *imgback;
	SDL_Rect posback;
	SDL_Rect camera;
	Mix_Music *son;
}background;


void initBack(background *b);
void afficheBack (background b,SDL_Surface *ecran);
void scrolling (background *b,int direction);
#endif 
