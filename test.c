#include <stdio.h>
#include <stdlib.h>
#include "EVNgin.h"

int main(int argc, char ** argv){
	
	EVN_Rect test_rect;
	test_rect = EVN_createRect(1,1,8,8);
	
	SDL_Rect sdl_rect = EVN_rectToSDLRect(test_rect);
	printf("The width of sdl rect is %d.\n", sdl_rect.w);

	
	
	return 0;
}
