#include <stdio.h>
#include <stdlib.h>
#include "EVNgin.h"
#include <SDL2/SDL.h>

SDL_Event event;


int main(int argc, char ** argv){
	
	EVN_Rect test_rect;
	test_rect = EVN_createRect(1,1,8,8);
	
	
	//init EVNgin
	EVN_init();
	
	EVN_createWindowAndRenderer("Test Window", 1080, 720, 0);
	
	EVN_createRectToRender(32,32,16,16,255,0,255,1);

	EVN_Sprite * ms = EVN_createSprite(128,256, "man.png");
	ms -> scale_x = 10;
	ms -> scale_y = 10;
	printf("%d\n", ms -> y);

	int quit = 0;
	while (!quit){
		
		//event handling loop
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				quit = 1;
			}
			if(event.type == SDL_KEYDOWN){
				switch(event.key.keysym.sym){
					case SDLK_q:
						quit = 1;
						break;
					default:
						break;	
				}
			}
		}
		
		//Render
		EVN_drawFrame();
		//add frame delay
		SDL_Delay(20);

	}	


	EVN_quit();
	
	return 0;
}
