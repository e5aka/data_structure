#define MaxSize 100
#define ElemType int

#include <stdio.h>
#include "SqList.h"

void a_minus_b(SqList *A, SqList B);

int main()
{
    int i, j, flag;
    ElemType e;
    SqList A,B;
    
    //初始化AB
    initList(&A);
    for(i=1;i<=10;i++){
        if(!listInsert(&A,i,i)){
            printf("插入位置非法");
            return 0;
        }
    }

    initList(&B);
    for(i=1,j=1;j<=6;i=i+2,j++){
        if(!listInsert(&B,j,i*2)){
            printf("插入位置非法");
            return 0;
        }
    }

    //输出AB元素
    printf("Seqlist A is:");
    printList(A);
    printf("Seqlist B is:");
    printList(B);

    //A-B之后A的元素
    a_minus_b(&A, B);
    printf("After A minus B:");
    printList(A);

    return 1;
}

void a_minus_b(SqList *A, SqList B)
{
    int i, pos;
    ElemType e;
    for(i=0;i<B.length;i++){
        if(getElem(B, i, &e))
            pos=locateElem(*A, e);
        if(pos>0){
            listDelete(A, pos, &e);
            printf("Deleted %d\n", e);
        }
    }
}
