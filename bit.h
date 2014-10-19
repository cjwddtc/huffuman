#ifndef BIT_H_INCLUDED
#define BIT_H_INCLUDED
#include "stdio.h"
struct BIT{
    unsigned char *a;
    int size;
    int max;
};

typedef struct BIT bit;
bit *getbit();
unsigned char readbit(bit *bi);
void addone(bit *a,unsigned char value);
void writeToFile(bit *bi,FILE *fp);


#endif // BIT_H_INCLUDED
