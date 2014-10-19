#include "bit.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

using namespace std;

bit *getbit(){
    bit *a=(bit*)malloc(sizeof(bit));
    a->a=(unsigned char *)malloc(1);
    a->size=0;
    a->max=8;
    return a;
}

unsigned char readbit(bit *bi){

}


void addone(bit *a,unsigned char value){
    if(a->size+1>a->max){
        a->a=(unsigned char *)realloc(a->a,a->max>>2);
        memset(a->a+(a->max>>3),0,a->max>>3);
        a->max<<=1;
    }
    value<<=((a->size^0b111)&0b111);
    a->a[a->size>>3]|=value;
    a->size++;
}

void writeToFile(bit *bi,FILE *fp){
    fwrite(bi->a,bi->size>>3,1,fp);
}
