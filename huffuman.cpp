#include <stdio.h>
#include <algorithm>
#include "huffuman.h"
#include <assert.h>
#include "string.h"
#define LEFTNODE 0b1
#define RIGHTNODE 0b10
#define ISROOT 0b100

class huffuman_tree_node;

huffuman_tree_node *list[MAX];
huffuman_tree_node *order[MAX];
int remain=MAX;

class huffuman_tree_node
{
public:
    huffuman_tree_node *father;
    huffuman_tree_node *left;
    huffuman_tree_node *right;
    unsigned char type;
    long freq;
    unsigned char ch;
    huffuman_tree_node(char ch,long freq)
    {
        this->ch=ch;
        father=0;
        left=0;
        right=0;
        this->freq=freq;
        this->type=0;
    }
    huffuman_tree_node(huffuman_tree_node *left,huffuman_tree_node *right)
    {
        this->left=left;
        this->right=right;
        this->type|=ISROOT;
        father=0;
        this->ch=-1;
        left->father=this;
        left->type|=LEFTNODE;
        right->father=this;
        right->type|=RIGHTNODE;
        freq=left->freq+right->freq;
    }
    bool operator<(huffuman_tree_node &a)
    {
        return freq>a.freq;
    }
    int getlen()
    {
        int i=0;
        huffuman_tree_node *a=this;
        while(a->father!=0)
        {
            a=a->father;
            i++;
        }
        return i;
    }
    void print()
    {
        static long n=0;
        if(!(type&ISROOT))
        {
            //printf("%ld\tchar:%5d\tlen:%d\n",freq,(int)ch,getlen());
            n+=freq*getlen();
            printf("%ld\n",n);
        }
        if(left!=0)
        {
            left->print();
        }
        if(right!=0)
        {
            right->print();
        }
    }
};

void getfreq(FILE *fp,unsigned long freq[MAX])
{
    memset(freq,0,sizeof(long)*MAX);
    unsigned char ch=fgetc(fp);
    while(!feof(fp))
    {
        assert(ch>=0);
        freq[ch]++;
        ch=fgetc(fp);
    }
}

void init(unsigned long freq[MAX])
{
    for(int i=0; i<MAX; i++)
    {
        list[i]=(new huffuman_tree_node(i,freq[i]));
        order[i]=list[i];
    }
}

bool is_small(huffuman_tree_node *a,huffuman_tree_node *b)
{
    return a->freq>b->freq;
}

void maketree()
{
    std::make_heap(list,list+remain,is_small);
    while(remain>1)
    {
        std::pop_heap(list,list+remain--,is_small);
        std::pop_heap(list,list+remain,is_small);
        list[remain-1]=new huffuman_tree_node(list[remain-1],list[remain]);
        std::push_heap(list,list+remain,is_small);
    }
}

unsigned char *codetobit(FILE *fp,unsigned long *n)
{
    fseek(fp,0,2);
    long len=ftell(fp);
    rewind(fp);
    unsigned char *ptr=(unsigned char *)malloc(len);
    len=0;
    unsigned char ch=fgetc(fp);
    unsigned char a[256];
    while(!feof(fp))
    {
        int i=0;
        huffuman_tree_node *node=order[ch];
        while(node->father!=0)
        {
            a[i++]=!(node->type&LEFTNODE);
            node=node->father;
        }
        while(i-->0)
        {
            addone(ptr,&len,a[i]);
        }
        ch=fgetc(fp);
    }
    *n=len>>3;
    return ptr;
}

