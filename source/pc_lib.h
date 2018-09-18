#define COL 4
#define ROW 4
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

void encoding(int * din, int rnum, int cnum, int *dout);


void decoding(int *din, int rnum, int cnum, int *dout, int * rcheck, int * ccheck);
