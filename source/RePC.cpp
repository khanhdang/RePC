#include <stdio.h>
#include <stdlib.h>
#include "pc_lib.h"

int main () {
	printf("----------------------------\r\n\tRecursive Product Code!\r\n----------------------------\r\n");
	int a[5] = {0, 1, 2, 3, 4};
	int *b = encoding(a);
	for(int i = 0; i < sizeof(b); i++) {
		printf("b[%d]  = %d", i, b[i]);
	}
	return 0;

}
