#include "pc_lib.h"
#include <stdio.h>

void  encoding(int *data, int rnum, int cnum, int *dout){
	*(dout+(rnum+1)*(cnum+1)-1) = 0;
	for(int i = 0; i < rnum; i++)
	{	
		*(dout+(i+1)*(cnum+1)-1) = 0 ;
		for(int j = 0; j < cnum; j++)
		{
			*(dout+i*(cnum+1)+j) = *(data+i*cnum+j);
			*(dout+(rnum+1)*(cnum+1)-1) = *(dout+(rnum+1)*(cnum+1)-1) ^ *(data+i*cnum+j);
			*(dout+(i+1)*(cnum+1)-1) = *(dout+(i+1)*(cnum+1)-1) ^ *(data+i*cnum+j);
		}
		
	}
	for (int j = 0; j < cnum; j++) {
		*(dout+(rnum)*(cnum+1)+j) = *(data+j);
		for (int i = 1; i < rnum; i++) {
			*(dout+(rnum)*(cnum+1)+j) = *(dout+(rnum)*(cnum+1)+j)^*(data+i*cnum+j);
		}
	}
	// return dout;
}
