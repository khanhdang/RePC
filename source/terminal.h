#include <stdio.h>
#include <stdlib.h>
#include "pc_lib.h"


class Transmitter
{
private:
    int ** local_fifo;
public:
    Transmitter();
    ~Transmitter();
};

Transmitter::Transmitter()
{
}

Transmitter::~Transmitter()
{
}



class Receiver
{
private:
    int ** local_fifo;
public:
    Receiver();
    ~Receiver();
};

Receiver::Receiver()
{
}

Receiver::~Receiver()
{
}
