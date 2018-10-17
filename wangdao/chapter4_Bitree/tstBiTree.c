typedef char ElemType;
#define MaxSize 30

#include <stdio.h>
#include "LinkBiTree.h"

void main(){
    BiTree T, root;
    char bt[MaxSize] = "ABD@G@@EH@@I@@CF@J@@@";

    initBiTree(&T);
    puts("Create BiTree by preOrderQueue(end with @)");
    printf("%s\n", bt);
    createBiTree(&T);
    printf("It's over\n");

    puts("The preOrderQueue:");
    preOrderTraverse(T);
    putchar('\n');
    puts("The preOrder,NoRecursive:");
    preOrderNoRecur(T);
    printf("\n\n");

    puts("The inOrderQueue:");
    inOrderTraverse(T);
    putchar('\n');
    puts("The inOrder,NoRecursive:");
    inOrderNoRecur(T);
    printf("\n\n");

    puts("The postOrderQueue:");
    postOrderTraverse(T);
    putchar('\n');
    puts("The preOrder,NoRecursive:");
    postOrderNoRecur(T);
    printf("\n\n");

    puts("\nDeleting BiTree ...");
    destroyBiTree(&T);
}
