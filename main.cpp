#include "huffuman.h"
int main()
{
    FILE *fp=fopen("D:\\word4.txt","rb");
    printf("inti()\n");
    unsigned long freq[MAX];
    getfreq(fp,freq);
    init(freq);
    printf("maketree\n");
    fclose(fp);
    fp=fopen("D:\\word4.txt","rb");
    maketree();
    printf("filetobit\n");
//    long masd=0;
//    for(int i=0;i<MAX;i++){
//        printf("%ld\t%d\n",order[i]->freq,order[i]->ch);
//        masd+=order[i]->freq*order[i]->getlen();
//    }
    //printf("%ld\n",masd);
    unsigned char *a=codetobit(fp);
}
