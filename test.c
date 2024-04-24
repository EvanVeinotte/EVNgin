#include <stdio.h>
#include <stdlib.h>
//#include "EVNgin.h"
#include "EVN_geometry.h"

int main(int argc, char ** argv){
	
	EVN_Rect test_rect;
	test_rect = EVN_createRect(1,1,8,8);

	printf("The width is %d.\n", test_rect.w);
	
	return 0;
}
