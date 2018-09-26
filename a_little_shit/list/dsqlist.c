#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef int ElemType;
typedef struct{
    int *elem;
    int length;
    int listsize;
}Sqlist;

void initSqlist(Sqlist *L){
    L->elem = (int *)malloc(MaxSize*sizeof(ElemType));
    if(!L->elem)    exit (0);
    L->length = 0;
    L->listsize = MaxSize;
}

void insertSqlist(Sqlist *L, int i, ElemType item){
    ElemType *base, *insertPtr, *p;
    if(i<1 || i>L->length+1)
        exit (0);
    if(L->length>=L->listsize){
        base=(ElemType*)realloc(L->elem, (L->listsize+10)*sizeof(ElemType));
        L->elem=base;
        L->listsize=L->listsize+100;
    }
    insertPtr=&(L->elem[i-1]);
    for(p=&(L->elem[L->length-1]);p>=insertPtr;p--)
        *(p+1)=*p;
    *insertPtr=item;
    L->length++;
}

void delSqlist(Sqlist *L, int i){
    ElemType *delItem, *q;
    if(i<1 || i>L->length) exit(0);
    delItem=&(L->elem[i-1]);
    q=L->elem + L->length-1;
    for(++delItem;delItem<=q;++delItem)
        *(delItem-1)=*delItem;
    L->length--;
}

void main(){
    Sqlist l;
    int i;
    initSqlist(&l);
    for(i=0;i<15;i++)
        insertSqlist(&l,i+1,i+1);
    printf("\nThe content of the list is:\n");
    for(i=0;i<l.length;i++)
        printf("%-2d ",l.elem[i]);
    delSqlist(&l,5);
    printf("\nDelete the element\n");
    for(i=0;i<l.length;i++)
        printf("%-2d ",l.elem[i]);
    printf("\n");
}
