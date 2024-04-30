#include "EVN_tosdl.h"

SDL_Rect EVN_rectToSDLRect(EVN_Rect evn_rect){
	return (SDL_Rect){evn_rect.x, evn_rect.y, evn_rect.w, evn_rect.h};
}
