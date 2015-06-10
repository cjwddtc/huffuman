#include "huffuman.h"
int main()
{
    FILE *fp=fopen("D:\\word4.rar","rb");
    printf("inti()\n");
    unsigned long freq[MAX];
    getfreq(fp,freq);
    init(freq);
    printf("maketree\n");
    rewind(fp);
    maketree();
    printf("filetobit\n");
//    long masd=0;
//    for(int i=0;i<MAX;i++){
//        printf("%ld\t%d\n",order[i]->freq,order[i]->ch);
//        masd+=order[i]->freq*order[i]->getlen();
//    }
    //printf("%ld\n",masd);
    unsigned long n;
    unsigned char *a=codetobit(fp,&n);
    printf("%ld\n",n);
    fclose(fp);
    fp=fopen("test.huf","wb");
    fwrite(a,n,1,fp);
    fclose(fp);
}
