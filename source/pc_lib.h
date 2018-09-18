#define COL 4
#define ROW 4
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
enum fault_distribution
{
	_UNIFORM_DIS,
	_ADJACENT_DIS,
	_BURST_DIS,
	_ADJACENT_AND_BURST_DIS,
	_MIXED_DIS
};

void encoding(int * din, int rnum, int cnum, int *dout);

void decoding(int *din, int rnum, int cnum, int *dout, int * rcheck, int * ccheck);

void fault_injection(int *din, int *dout, int * fault_vector, int rnum, int cnum);

void fault_gen(int * fault_vector, fault_distribution dis, int fnum,  int rnum, int cnum);
