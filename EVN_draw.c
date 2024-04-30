#include <stdlib.h>
#include <SDL2/SDL.h>
#include "EVNgin.h"

EVN_Sprite * EVN_sprites_to_render;
int EVN_num_of_sprites = 0;
EVN_RenderRect * EVN_rects_to_render;
int EVN_num_of_rects = 0;
int sprite_ptr_size;
int rect_ptr_size;

int EVN_initDraw(int sprite_ptr_size, int rect_ptr_size){
	EVN_sprites_to_render = malloc(sprite_ptr_size * sizeof(EVN_Sprite));
	EVN_rects_to_render = malloc(rect_ptr_size * sizeof(EVN_RenderRect));
}

int EVN_drawFrame(){
	
	//clear renderer
	SDL_SetRenderDrawColor(renderer, 0,0,0,255);

	//render sprites
	for (int i=0; i < EVN_num_of_sprites; i++){
		
	}

	//render rects
	for (int i=0; i < EVN_num_of_rects; i++){
		EVN_RenderRect cur_rect = EVN_rects_to_render[i];
		SDL_Rect sdl_rect = {cur_rect.x, cur_rect.y, cur_rect.w, cur_rect.h};

		SDL_SetRenderDrawColor(renderer, cur_rect.r, cur_rect.g, cur_rect.b, 255);

		if(cur_rect.fill){
			SDL_RenderFillRect(renderer, &sdl_rect);
		}else{
			SDL_RenderDrawRect(renderer, &sdl_rect);
		}
	}

	SDL_RenderPresent(renderer);
}


int EVN_createRectToRender(int x, int y, int w, int h, int r, int g, int b, int fill){
	EVN_num_of_rects += 1;
	if(EVN_num_of_rects >= rect_ptr_size){
		EVN_num_of_rects = 0;
		printf("WARNING!!! Went over max rect amount.");
	}
	EVN_RenderRect new_rect = {x,y,w,h,r,g,b,fill};
	EVN_rects_to_render[EVN_num_of_rects - 1] = new_rect;
}


int EVN_destroyDrawMemory(){
	//sprites
	free(sprite_ptr_size);

	//render rects
	free(rect_ptr_size);
}
