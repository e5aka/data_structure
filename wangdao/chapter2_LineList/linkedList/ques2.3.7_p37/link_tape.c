typedef int ElemType;

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../LinList.h"

void que1_delx_recursion(LinkList *L, ElemType x){
   LNode *p;

   if((*L) == NULL)      //recur exit
       return;
   else if((*L)->data == x){       //recur body
       p = (*L);
       (*L) = (*L)->next;
       free(p);
       que1_delx_recursion(L, x);
   }else
       que1_delx_recursion(&(*L)->next, x);
}

void main(int argc, char *argv[]){
    int i, j, k;
    ElemType a[] = {1,2,3,4,5,6,7,8};
    LinkList A, B, p;

    printf("Create A:");
    initList(&A);
    for(i=1;i<=sizeof(a)/sizeof(a[0]);i++)
        insList(A, i, a[i-1]);

    printf("Before functioned,A is :\n");
    traverse_list(A);

    //delElem(A, B);
    printf("\nAfter functioned,A仍有%d个元素:\n", getLength(A));
    traverse_list(A);

    destroy_list(A);
    printf("Piece of cake\n");
}
