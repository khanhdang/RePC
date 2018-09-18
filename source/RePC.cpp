#include <stdio.h>
#include <stdlib.h>
#include "pc_lib.h"
int dout[ROW+1][COL+1];
int din[ROW][COL] = {{0, 1, 0, 0},
					{1, 1, 1, 1},
					{1, 1, 1, 0},
					{1, 0, 1, 0}};;
int main () {
	printf("----------------------------\r\n");
	printf("  Recursive Product Code!\r\n");
	printf("----------------------------\r\n");
	encoding(&din[0][0], ROW, COL, &dout[0][0]);
	printf("size of b = %d\n", NELEMS(dout));
	
	for(int i = 0; i < ROW+1; i++)
	{
		for(int j = 0; j < COL+1; j++)
		{
			printf("b[%d][%d]  = %d\r\n", i,j, dout[i][j]);
		}
		printf("-----------\r\n");
		
	}
	return 0;
}
