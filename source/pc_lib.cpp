#include "pc_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
	srand((int)time(NULL));

	printf("fposi= ");
	while(k < fnum) {
		int r = rand() % (cnum*rnum);
		if (*(fault_vector+r) == 0) {
			k++;
			*(fault_vector+r) = 1;
			printf("%d ",r);
		}	
	}
	printf("\r\n");
	switch (dis)
	{
		case _UNIFORM_DIS:
			/* code */
			break;
		case _ADJACENT_DIS:
			break;
		case _BURST_DIS:
			break;

		case _ADJACENT_AND_BURST_DIS:
			break;
		case _MIXED_DIS:

		default:
			break;
	}
}