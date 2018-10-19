typedef char ElemType;
#define MaxSize 30

#include <stdio.h>
#include "TraverseAPP.h"

char bt[MaxSize] = "ABD@G@@EH@@I@@CF@J@@@";
int con = 0;

void main(int argc, char *argv[]){
    BiTree T, root;

    initBiTree(&T);
    puts("Create BiTree by preOrderQueue(end with @)");
    printf("%s\n", bt);
    //createBiTree(&T);
    createBiTree_NR(&T);
    printf("It's over\n\n");

    puts("LeverOrder display:");
    levelOrder(T);
    printf("\n");

    printf("The BiTree have %d leaves\n", leafNum(T));

}
