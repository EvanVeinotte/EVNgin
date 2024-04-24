#ifndef EVN_GEOMETRY
#define EVN_GEOMETRY

typedef struct{
	int x;
	int y;
} EVN_Point;

typedef struct{
	int x0;
	int y0;
	int x1;
	int y1;
} EVN_Line;

typedef struct{
	int x;
	int y;
	int w;
	int h;
}EVN_Rect;

EVN_Point EVN_createPoint(int x, int y);
EVN_Line EVN_createLine(int x0, int y0, int x1, int y1);
EVN_Rect EVN_createRect(int x, int y, int w, int h);

#endif
