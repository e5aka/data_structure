#define MaxSize 10

#include <stdio.h>
#include <stdlib.h>
#include "D_SqList.h"

void delElem(SqList *A, SqList B);

int main(){
    int i, j, flag;
    ElemType e;
    SqList A, B;

    initList(&A);
    initList(&B);
    for(i=1;i<=10;i++)
        listInsert(&A, i, i);
    for(i=1,j=1;j<=6;i=i+2,j++)
        listInsert(&B, j, i);

    printf("Seq A is:");
    traverseList(A);
    printf("Seq B is:");
    traverseList(B);

    printf("After A-B:");
    delElem(&A, B);
    traverseList(A);

    return 0;
}

void delElem(SqList *A, SqList B){
    int i, pos;
    ElemType e;
    for(i=0;i<B.length;i++){
        if(getElem(B, i, &e)){
            pos = locateElem(*A, e);
            if(pos>0)
                listDelete(A, pos-1, &e);
        }
    }
}
