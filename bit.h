#ifndef BIT_H_INCLUDED
#define BIT_H_INCLUDED
#include "stdio.h"
typedef struct
{
    unsigned char bitposition:3;
unsigned int ptrposition:
    sizeof(long)*8-3;
} position;

unsigned char readbit(unsigned char *a,long *pos);
unsigned int addone(unsigned char *a,long *pos,unsigned char value);

#endif // BIT_H_INCLUDED
