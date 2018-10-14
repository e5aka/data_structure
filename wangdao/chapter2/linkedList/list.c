typedef int ElemType;

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Circle_Lin.h"
//#include "LinList.h"

void delElem(LinkList A, LinkList B);

void main(){
    int i;
    ElemType a[] = {1,2,3,4,5,6,7,8};
    ElemType b[] = {1,2,3,44,5,66,7,88};
    LinkList A, B, p;

    printf("Devil may cry\n");
    initList(&A);
    for(i=1;i<=sizeof(a)/sizeof(a[0]);i++)
        insList(A, i, a[i-1]);
    initList(&B);
    for(i=1;i<=sizeof(b)/sizeof(b[0]);i++)
        insList(B, i, b[i-1]);

    printf("A is :");
    traverseList(A);
    printf("B is :");
    traverseList(B);

    delElem(A, B);
    printf("After A-B,A仍有%d个元素:", getLength(A));
    traverseList(A);

    destroyList(B);

    printf("Piece of cake\n");
}

void delElem(LinkList A, LinkList B){
    int i, pos;
    ElemType e;
    LinkList p, q;
    for(i=1;i<=getLength(B);i++){
        p = getElem(B, i);
        pos = locatePos(A, p->data);
        printf("pos = %d\n", pos);
        if(pos>0){
            delList(A, pos, &e);
        }
    }
}
