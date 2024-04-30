#include "EVNgin.h"
#include "EVN_window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int EVN_init(){
	if(SDL_Init(SDL_INIT_VIDEO)){
		printf("Could not init SDL");
		return 0;
	}

	IMG_Init(IMG_INIT_PNG);

	EVN_initDraw(16,256);
}

int EVN_quit(){
	EVN_destroyDrawMemory();
	EVN_quitWindow();
	SDL_Quit();
}
