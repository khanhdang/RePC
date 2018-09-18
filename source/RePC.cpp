/* This is the RePC code
*
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "pc_lib.h"
int codeword[ROW+1][COL+1];
int raw_dat[ROW][COL] = {{0, 1, 0, 0},
					{1, 1, 1, 1},
					{1, 1, 1, 0},
					{1, 0, 1, 0}};;
int decoded_dat[ROW][COL];
int rcheck[ROW+1];
int ccheck[COL+1];

int main () {
	printf("----------------------------\r\n");
	printf("  Recursive Product Code!\r\n");
	printf("----------------------------\r\n");
	encoding(&raw_dat[0][0], ROW, COL, &codeword[0][0]);
	// printf("size of b = %d\n", NELEMS(dout));
	decoding(&codeword[0][0], ROW+1, COL+1, &decoded_dat[0][0], rcheck, ccheck);

	for(int i = 0; i < ROW+1; i++)
	{
		printf("rcheck[%d]  = %d\r\n", i, rcheck[i]);
	}
	for(int j = 0; j < COL+1; j++)
	{
		printf("ccheck[%d]  = %d\r\n", j, ccheck[j]);
	}
	return 0;
}
