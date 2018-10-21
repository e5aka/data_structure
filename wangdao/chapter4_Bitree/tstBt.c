typedef char ElemType;
#define MaxSize 30

#include <stdio.h>
#include "LinkBiTree.h"

//            A
//         /    \
//        B      C
//      /   \  /
//      D   E  F
//       \ / \  \
//       G H I  J
void main(){
    char bt[MaxSize] = "ABD@G@@EH@@I@@CF@J@@@";
    int con = 0;
    BiTree T, root;

    initBiTree(&T);
    puts("Create BiTree by preOrderQueue(end with @)");
    printf("%s\n", bt);
    //createBiTree(&T);
    createBiTree_NR(&T, bt, &con);
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
