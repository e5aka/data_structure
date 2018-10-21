typedef char ElemType;
#define MaxSize 30

#include <stdio.h>
#include "TraverseBT.h"

void main(int argc, char *argv[]){
    BiTree T, root;
    char bt[MaxSize] = "ABD@G@@EH@@I@@CF@J@@@";
    int con = 0;

    initBiTree(&T);
    puts("Create BiTree by preOrderQueue(end with @)");
    printf("%s\n", bt);
    //createBiTree(&T);
    createBiTree_NR(&T, bt, &con);
    printf("It's over\n\n");
    
    puts("Display by tree:");
    treePrint(T, 1);

    puts("LeverOrder display:");
    levelOrder(T);
    printf("\n");

    puts("The BiTree have");
    printf("-- %d leaf nodes\n", leafNum(T));
    printf("-- %d nonleaf nodes\n", notLeafNum(T));
    printf("-- %d depth\n", getDepth(T));
}
