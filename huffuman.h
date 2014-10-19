#ifndef HUFFUMAN_H_INCLUDED
#define HUFFUMAN_H_INCLUDED
#define MAX 256
#include "bit.h"
void maketree();
void init(unsigned long freq[MAX]);
bit *codetobit(FILE *fp);
void getfreq(FILE *fp,unsigned long freq[MAX]);

#endif // HUFFUMAN_H_INCLUDED
