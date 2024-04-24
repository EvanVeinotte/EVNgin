#include "EVN_geometry.h"

EVN_Point EVN_createPoint(int x, int y){
	return (EVN_Point){x, y};
}

EVN_Line EVN_createLine(int x0, int y0, int x1, int y1){
	return (EVN_Line){x0, y0, x1, y1};
}

EVN_Rect EVN_createRect(int x, int y, int w, int h){
	return (EVN_Rect){x, y, w, h};
}
