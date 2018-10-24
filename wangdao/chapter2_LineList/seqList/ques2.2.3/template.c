typedef int ElemType;
#define MaxSize 100

#include <stdio.h>
#include "../SqList.h"

void a_minus_b(SqList *A, SqList B);    //test function

int main()
{
    int i, j, flag;
    ElemType e;
    SqList A,B;
    ElemType arr1[] = {1,2,3,4,5,6,7,8,9,10};
    
    //初始化AB
    initList(&A);
    for(i=1;i<=10;i++){
        if(!insList(&A,i,i)){
            printf("插入位置非法");
            return 0;
        }
    }

    initList(&B);
    for(i=1,j=1;j<=6;i=i+2,j++){
        if(!insList(&B,j,i*2)){
            printf("插入位置非法");
            return 0;
        }
    }

    //输出AB元素
    printf("Seqlist A is:");
    traverseList(A);
    printf("Seqlist B is:");
    traverseList(B);

    a_minus_b(&A, B);
    printf("After function exe:\n");
    traverseList(A);

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
            delList(A, pos, &e);
            printf("Deleted %d\n", e);
        }
    }
}
