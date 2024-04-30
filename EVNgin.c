#include "EVNgin.h"
#include "EVN_window.h"
#include <SDL2/SDL.h>

int EVN_init(){
	if(SDL_Init(SDL_INIT_VIDEO)){
		printf("Could not init SDL");
		return 0;
	}

	EVN_initDraw(4096,256);
}

int EVN_quit(){
	EVN_destroyDrawMemory();
	EVN_quitWindow();
	SDL_Quit();
}
