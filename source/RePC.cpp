/* Project: Recursive Product Code
*  Authors: Khanh N. Dang 
*  Email: khanh.n.dang@ieee.org
*  Affiliation: SISLAB, Vietnam National University, Hanoi, Vietnam
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
int * fcodeword;
int * faults;

int main () {
	printf("----------------------------\r\n");
	printf("|  Recursive Product Code! |\r\n");
	printf("----------------------------\r\n");
	encoding(&raw_dat[0][0], ROW, COL, &codeword[0][0]);
	// for (int k=0; k<3; k++) {
		faults = (int *)calloc((ROW+1)*(COL+1), sizeof(int));
		fault_gen(faults, _UNIFORM_DIS, 2, ROW+1, COL+1);
		printf("fault=\r\n{\r\n");
		for(int i = 0; i < ROW+1; i++)
		{
			for(int j = 0; j < COL+1; j++) {
				printf("%d, ",*(faults+i*(COL+1)+j));
			}
			printf("\r\n");
		}	
		printf("}\r\n");
		// free(faults);
	// }
	fcodeword = (int *)calloc((ROW+1)*(COL+1), sizeof(int));
	fault_injection(&codeword[0][0], fcodeword, faults, ROW+1, COL+1);
	// decoding(&codeword[0][0], ROW+1, COL+1, &decoded_dat[0][0], rcheck, ccheck);
	decoding(fcodeword, ROW+1, COL+1, &decoded_dat[0][0], rcheck, ccheck);
	printf("rcheck = [ \n");
	for(int i = 0; i < ROW+1; i++)
	{
		printf("%d \n", rcheck[i]);
	}
	printf("];\r\n");
	printf("ccheck = [ ");
	for(int j = 0; j < COL+1; j++)
	{
		printf("%d ", ccheck[j]);
	}
	printf("];\r\n");
	return 0;
}
