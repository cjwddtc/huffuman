#include "bit.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

using namespace std;

typedef struct
{
    unsigned char bitposition:3;
    unsigned char ptrposition:29;
} position;

unsigned char readbit(unsigned char *a,long *pos)
{
    return (a[((position *)pos)->ptrposition]<<((position*)pos)->bitposition)&0b10000000;
}

unsigned int addone(unsigned char *a,long *pos,unsigned char value)
{
    if(value)
    {
        a[((position *)pos)->ptrposition]|=(0b10000000>>((position*)pos)->bitposition);
    }
    (*pos)++;
    return ((position*)pos)->ptrposition;
}
