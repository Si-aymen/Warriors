#include "play.h"
#include "background.h"
#include "perso.h"
void jouer(SDL_Surface* ecran)
{	SDL_Event event;
	int continuer=1,i=0;;
	background back;
	personnage p;
	
	initBack(&back);

	initialiser_personnage(&p);
   while (continuer)
  {	
	deplacerperso(&p,&continuer,&event,&back);
	switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
			
                        
			scrolling(&back,0);
                        break;
                    case SDLK_LEFT:
			
                        
			scrolling(&back,1);
                        break;
                }
                break;
       }
animperso(&i,&event,&p);
        
 	afficheBack(back,ecran);
	afficher_perso1(p,ecran);
	SDL_Flip(ecran);
  }
	SDL_FreeSurface(p.sprite);
}
