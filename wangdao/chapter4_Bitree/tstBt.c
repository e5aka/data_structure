typedef char ElemType;
#define MaxSize 30

char bt[MaxSize] = "ABD@G@@EH@@I@@CF@J@@@";
int con = 0;

#include <stdio.h>
#include "LinkBiTree.h"

void main(){
    BiTree T, root;

    initBiTree(&T);
    puts("Create BiTree by preOrderQueue(end with @)");
    printf("%s\n", bt);
    //createBiTree(&T);
    createBiTree_NR(&T);
    printf("It's over\n");

    puts("The preOrderQueue:");
    preOrderTraverse(T);
    putchar('\n');
    puts("The preOrder,NoRecursive:");
    preOrder_nr(T);
    printf("\n\n");

    puts("The inOrderQueue:");
    inOrderTraverse(T);
    putchar('\n');
    puts("The inOrder,NoRecursive:");
    inOrder_nr(T);
    printf("\n\n");

    puts("The postOrderQueue:");
    postOrderTraverse(T);
    putchar('\n');
    puts("The preOrder,NoRecursive:");
    postOrder_nr(T);
    printf("\n\n");

    puts("\nDeleting BiTree ...");
    destroyBiTree(&T);
}
