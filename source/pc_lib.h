#ifndef PC_LIB_H
#define PC_LIB_H
#define COL 5
#define ROW 4
#define DYNAMIC_2D 1
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
enum fault_distribution
{
	_UNIFORM_DIS,
	_ADJACENT_DIS,
	_BURST_DIS,
	_ADJACENT_AND_BURST_DIS,
	_MIXED_DIS
};

void printMatrix(int * matrix, int row, int col);
void printPMatrix(int ** matrix, int row, int col);
#ifndef DYNAMIC_2D
    void encoding(int * din, int rnum, int cnum, int *dout);
#else
    void encoding(int (* din)[COL], int rnum, int cnum, int (* dout)[COL+1]);
#endif
void decoding(int *din, int rnum, int cnum, int *dout, int * rcheck, int * ccheck);

void fault_injection(int *din, int *dout, int * fault_vector, int rnum, int cnum);

void fault_gen(int * fault_vector, fault_distribution dis, int fnum,  int rnum, int cnum);
#endif