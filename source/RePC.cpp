/* Project: Recursive Product Code
*  Authors: Khanh N. Dang 
*  Email: khanh.n.dang@ieee.org
*  Affiliation: SISLAB, Vietnam National University, Hanoi, Vietnam
*/
#include <stdio.h>
#include <stdlib.h>
#include "pc_lib.h"

int codeword[ROW+1][COL+1];
int raw_dat[ROW][COL] = {{0, 1, 0, 0, 1},
                        {1, 1, 1, 1, 0},
                        {1, 1, 1, 0, 1},
                        {1, 0, 1, 0, 1}};
int decoded_dat[ROW][COL];
int rcheck[ROW+1];
int ccheck[COL+1];
int * fcodeword;
int * faults;



int main () {
	printf("---------------------------- \r\n");
	printf("|  Recursive Product Code! | \r\n");
	printf("---------------------------- \r\n");
	// printMatrix(raw_dat, ROW, COL);
	#ifndef DYNAMIC_2D
		encoding(&raw_dat[0][0], ROW, COL, &codeword[0][0]);
	#else
		encoding(raw_dat, ROW, COL, codeword);
	#endif
	// printMatrix(&codeword[0][0], ROW+1, COL+1);
	faults = (int *)calloc((ROW+1)*(COL+1), sizeof(int));
	fault_gen(faults, _ADJACENT_DIS, 2, ROW+1, COL+1);
	printf("fault matrix:\r\n");
	printMatrix(faults, ROW+1, COL+1);
	fcodeword = (int *)calloc((ROW+1)*(COL+1), sizeof(int));
	fault_injection(&codeword[0][0], fcodeword, faults, ROW+1, COL+1);
	free(faults);
	// decoding(&codeword[0][0], ROW+1, COL+1, &decoded_dat[0][0], rcheck, ccheck);
	decoding(fcodeword, ROW+1, COL+1, &decoded_dat[0][0], rcheck, ccheck);
	printf("row check:\r\n");
	printMatrix(rcheck, 1, ROW+1);
	printf("col check:\r\n");
	printMatrix(ccheck, 1, COL+1);
	return 0;
}
