//2 b solved
#define MaxSize 100
typedef int ElemType;

#include <stdio.h>
//#include <malloc.h>
//#include <stdlib.h>
#include "Circle_Lin.h"

LinkList link(LinkList h1, LinkList h2);

void main(){
    LinkList A, B;
    int i;
    int a[] = {1,2,3};
    int b[] = {4,5,6};

    printf("The \\n = %d\n", '\n');
    
    puts("Create CirLinkList A:");
    createList2_nh(&A);
    printf("A->data = %d\n", A->data);
    printf("List A is:");
    traverseList(A);

//    initList(&A);
//    for(i=1;i<=sizeof(a)/sizeof(a[0]);i++)
//        insList(A, i, a[i-1]);
//    initList(&B);
//    for(i=1;i<=sizeof(b)/sizeof(b[0]);i++)
//        insList(B, i, b[i-1]);
    puts("Devil may cry");
    
    puts("Create CirLinkList B:");
    createList2_nh(&B);
    printf("B->data = %d\n", B->data);
    printf("List B is:");
    traverseList(B);

    A = link(A, B);
    puts("The new list is :");
    traverseList(A->next);
}

LinkList link(LinkList A, LinkList B){
    LinkList p = A;
    while(p->next != A)
        p = p->next;
    LinkList q = B;
    while(q->next != B)
        q = q->next;

    p->next = B;
    q->next = A;
    return A;
}
