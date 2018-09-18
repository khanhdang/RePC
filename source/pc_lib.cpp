#include "pc_lib.h"
#include <stdio.h>

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