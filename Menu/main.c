#include "menu.h"
#include "play.h"
int main ()
{
    int continuee=1,a=0;
    SDL_Surface *ecran =NULL;
    Mix_Music *musique;

	  Mix_Chunk *son;
    

    Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(IMG_Load("logo.png"), NULL); // L'icône doit être chargée avant SDL_SetVideoMode
    ecran = SDL_SetVideoMode(1366, 678,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Cursed island", NULL);
    SDL_Event event;

if (ecran==NULL)
{
printf("error: %s ",SDL_GetError());
exit(EXIT_FAILURE);
}
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
  {printf("%s",Mix_GetError()); }
          
	   musique=Mix_LoadMUS("music2.mp3");
           Mix_PlayMusic(musique,-1);

	Mix_AllocateChannels(3);
    Mix_Volume(1, MIX_MAX_VOLUME/2);
    
    son = Mix_LoadWAV("BREF.wav");

    Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);
		printf("%d \n",a);
while (continuee)
{

a=menu(ecran,musique);
printf("%d \n",a);
switch(a)
{case 1 : jouer(ecran);
break;
case 2 : setting(ecran,son,musique);
break;
case 3 : continuee=0;
break;
}
}

Mix_FreeMusic(musique);
Mix_CloseAudio();
SDL_FreeSurface(ecran);
SDL_Quit();
return EXIT_SUCCESS;
}




