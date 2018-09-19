#include "pc_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printMatrix(int * matrix, int row, int col){
	for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // *(*(matrix + i) + j) is equivalent to matrix[i][j]
            printf("%d ",  *( matrix + (i*col) + j));
        }

        printf("\n");
    }
}

void printPMatrix(int ** matrix, int row, int col){
	for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // *(*(matrix + i) + j) is equivalent to matrix[i][j]
            printf("%d ",  *(*(matrix + i) + j));
        }

        printf("\n");
    }
}

#ifndef DYNAMIC_2D
void  encoding(int *din, int rnum, int cnum, int *dout){
	*(dout+(rnum+1)*(cnum+1)-1) = 0;
	for(int i = 0; i < rnum; i++)
	{	
		*(dout+(i+1)*(cnum+1)-1) = 0 ;
		for(int j = 0; j < cnum; j++)
		{
			*(dout+i*(cnum+1)+j) = *(din+i*cnum+j);
			*(dout+(rnum+1)*(cnum+1)-1) = *(dout+(rnum+1)*(cnum+1)-1) ^ *(din+i*cnum+j);
			*(dout+(i+1)*(cnum+1)-1) = *(dout+(i+1)*(cnum+1)-1) ^ *(din+i*cnum+j);
		}
		
	}
	for (int j = 0; j < cnum; j++) {
		*(dout+(rnum)*(cnum+1)+j) = *(din+j);
		for (int i = 1; i < rnum; i++) {
			*(dout+(rnum)*(cnum+1)+j) = *(dout+(rnum)*(cnum+1)+j)^*(din+i*cnum+j);
		}
	}
	// return dout;
}
#else
void encoding(int (* din)[COL], int rnum, int cnum, int (* dout)[COL+1]){
	*(*(dout+(rnum+1))+cnum) = 0;
	for(int i = 0; i < rnum; i++)
	{	
		*(*(dout+i+1)-1) = 0 ;
		for(int j = 0; j < cnum; j++)
		{
			*(*(dout+i)+j) = *(*(din+i)+j);
			*(*(dout+rnum+1)-1) = *(*(dout+rnum+1)-1) ^ *(*(din+i)+j);
			*(*(dout+i+1)-1) = *(*(dout+i+1)-1) ^ *(*(din+i)+j);
		}
		
	}
	for (int j = 0; j < cnum; j++) {
		*(*(dout+rnum)+j) = *(*(din)+j);
		for (int i = 1; i < rnum; i++) {
			*(*(dout+rnum)+j) = *(*(dout+rnum)+j)^*(*(din+i)+j);
		}
	}
}
#endif

void decoding(int *din, int rnum, int cnum, int *dout, int *rcheck, int *ccheck) {
	for(int i = 0; i < rnum; i++)
	{	
		*(rcheck+i) = 0 ;
		for(int j = 0; j < cnum; j++)
		{
			*(rcheck+i) = *(rcheck+i) ^ *(din+i*cnum+j);
		}	
	}
	for(int j = 0; j < cnum; j++)
	{	
		*(ccheck+j) = 0 ;
		for(int i = 0; i < rnum; i++)
		{
			*(ccheck+j) = *(ccheck+j) ^ *(din+i*cnum+j);
		}	
	}	

}

void fault_injection(int *din, int *dout, int * fault_vector, int rnum, int cnum) {
	for(int i = 0; i < rnum; i++)
	{	
		for(int j = 0; j < cnum; j++)
		{
			*(dout+i*cnum+j) = *(fault_vector+i*cnum+j) ^ *(din+i*cnum+j);
		}	
	}
}

void fault_gen (int * fault_vector, fault_distribution dis, int fnum, int rnum, int cnum) {
	int k=0;
	int r=0;
	srand((int)time(NULL));
	switch (dis)
	{
		case _UNIFORM_DIS:
			printf("fposi= ");
			while(k < fnum) {
				r = rand() % (cnum*rnum);
				if (*(fault_vector+r) == 0) {
					k++;
					*(fault_vector+r) = 1;
					printf("%d ",r);
				}	
			}
			printf("\r\n");
			break;
		case _ADJACENT_DIS:
			printf("Warning: this feature only supports 1D array!\r\n");
			printf("fposi= ");
			r = rand() % (cnum*rnum-fnum)+fnum/2;
			printf("%d ",r);
			printf("\r\n");
			for (int z = r-(fnum/2); z <r+float(fnum)/2; z++){
				*(fault_vector+z) = 1;
			}
			break;

		case _BURST_DIS:
			printf("Unsupported feature!\r\n");
			break;

		case _ADJACENT_AND_BURST_DIS:
			printf("Unsupported feature!\r\n");
			break;
		case _MIXED_DIS:
			printf("Unsupported feature!\r\n");
			break;
		default:
			break;
	}
}