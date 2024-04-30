#include "EVN_window.h"
#include <SDL2/SDL.h>

short int EVN_window_w;
short int EVN_window_h;

SDL_Window* window;
SDL_Renderer* renderer;

//returns 0 if success, 1 if error
int EVN_createWindowAndRenderer(const char * window_title, short int window_w, short int window_h,
				int fullscreen){
	
	EVN_window_w = window_w;
	EVN_window_h = window_h;

	Uint32 flags = SDL_WINDOW_RESIZABLE | fullscreen;
	
	window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
					EVN_window_w, EVN_window_h, flags);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
					
}

int EVN_quitWindow(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
