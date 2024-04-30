#ifndef EVN_WINDOW
#define EVN_WINDOW

#include <SDL2/SDL.h>

#define EVN_WINDOWED 0
#define EVN_FULLSCREEN 1

extern short int EVN_WINDOW_W;
extern short int EVN_WINDOW_H;

extern SDL_Window * window;
extern SDL_Renderer * renderer;

int EVN_createWindowAndRenderer(char * window_title, short int window_w, short int window_h,
				int fullscreen);

int EVN_quitWindow();

#endif
