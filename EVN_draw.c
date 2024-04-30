#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "EVNgin.h"

EVN_Sprite * EVN_sprites_to_render;
int EVN_num_of_sprites = 0;
EVN_RenderRect * EVN_rects_to_render;
int EVN_num_of_rects = 0;
int EVN_sprite_ptr_size;
int EVN_rect_ptr_size;

int EVN_initDraw(int sprite_ptr_size, int rect_ptr_size){
	EVN_num_of_sprites = 0;
	EVN_num_of_rects = 0;
	EVN_sprite_ptr_size = sprite_ptr_size;
	EVN_rect_ptr_size = rect_ptr_size;
	EVN_sprites_to_render = malloc(sprite_ptr_size * sizeof(EVN_Sprite));
	EVN_rects_to_render = malloc(rect_ptr_size * sizeof(EVN_RenderRect));
}

int EVN_drawFrame(){
	
	//clear renderer
	SDL_SetRenderDrawColor(renderer, 0,0,0,255);
	SDL_RenderClear(renderer);

	//render sprites
	for (int i=0; i < EVN_num_of_sprites; i++){
		if(EVN_sprites_to_render[i].visible){
			EVN_Sprite cur_sprite = EVN_sprites_to_render[i];
			SDL_Rect sprite_rect = {cur_sprite.x,
						cur_sprite.y,
						cur_sprite.w * cur_sprite.scale_x,
						cur_sprite.h * cur_sprite.scale_y};
			SDL_RenderCopy(renderer, EVN_sprites_to_render[i].texture, NULL, &sprite_rect);
		}
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


EVN_Sprite* EVN_createSprite(int x, int y, const char * filename){
	//this function will automatically add the
	//sprite to the render ptr
	
	EVN_Sprite new_sprite = {.x = x, .y = y};
	new_sprite.visible = 1;
	//now load the image to get w and h
	SDL_Surface * new_surf = IMG_Load(filename);
	
	if(!new_surf){
		printf("could not load image!");
		return NULL;
	}

	new_sprite.w = new_surf -> w;
	new_sprite.h = new_surf -> h;
	SDL_Texture * new_texture = SDL_CreateTextureFromSurface(renderer, new_surf);
	SDL_FreeSurface(new_surf);
	
	new_sprite.scale_x = 1;
	new_sprite.scale_y = 1;

	SDL_SetTextureBlendMode(new_texture, SDL_BLENDMODE_BLEND);
	
	new_sprite.texture = new_texture;

	//add the sprite to the sprite bank
	EVN_num_of_sprites += 1;
	if(EVN_num_of_sprites >= EVN_sprite_ptr_size){
		EVN_num_of_sprites = 0;
		printf("WARNING!!! Went over max sprite amount");
	}
	EVN_sprites_to_render[EVN_num_of_sprites - 1] = new_sprite;


	return &EVN_sprites_to_render[EVN_num_of_sprites - 1];

}

int EVN_createRectToRender(int x, int y, int w, int h, int r, int g, int b, int fill){
	EVN_num_of_rects += 1;
	if(EVN_num_of_rects >= EVN_rect_ptr_size){
		EVN_num_of_rects = 0;
		printf("WARNING!!! Went over max rect amount.");
	}
	EVN_RenderRect new_rect = {x,y,w,h,r,g,b,fill};
	EVN_rects_to_render[EVN_num_of_rects - 1] = new_rect;
}


int EVN_destroyDrawMemory(){
	//sprites
	for (int i=0; i < EVN_num_of_sprites; i++){
		SDL_DestroyTexture(EVN_sprites_to_render[i].texture);
		//printf("%d - %d\n", i, EVN_sprites_to_render[i].x);
	}
	free(EVN_sprites_to_render);

	//render rects
	free(EVN_rects_to_render);
}
