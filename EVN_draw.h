#include <SDL2/SDL.h>

#ifndef EVN_DRAWSOME
#define EVN_DRAWSOME
typedef struct EVN_RenderRect{
	int x,y,w,h;
	int r,g,b;
	int fill;
}EVN_RenderRect;

//Eventually move Sprite struct
//to its own Sprite.h file
typedef struct EVN_Sprite{
	int x,y;
	int w,h;
	int scale_x, scale_y;
	SDL_Texture * texture;
	int visible;
	//animation section
	int sprite_sheet; //1 if true
	int frame_w;
	int frame_h;
	int frame_index;
}EVN_Sprite;


extern EVN_Sprite * EVN_sprites_to_render;
extern int EVN_num_of_sprites;
extern EVN_RenderRect * EVN_rects_to_render;
extern int EVN_num_of_rects;
extern int EVN_sprite_ptr_size;
extern int EVN_rect_ptr_size;

int EVN_initDraw(int sprite_ptr_size, int rect_ptr_size);

int EVN_drawFrame();

int EVN_drawRect();

EVN_Sprite* EVN_createSprite(int x, int y, const char * filename);

//int EVN_addSpriteToRender();

int EVN_createRectToRender(int x,int y,int w,int h,int r,int g,int b,int fill);

int EVN_destroyDrawMemory();

#endif
