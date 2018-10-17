typedef char ElemType;
#define MaxSize 30

#include <stdio.h>
#include "LinkBiTree.h"

void fcreateBiTree(BiTree *T, char s[]);

void main(){
    BiTree T, root;
    char bt[MaxSize] = "ABD@G@@EH@@I@@CF@J@@@";

    initBiTree(&T);
    puts("Create BiTree by preOrderQueue(end with @)");
    fcreateBiTree(&T, bt);
    printf("It's over\n");

    puts("The preOrderQueue:");
    preOrderTraverse(T);
    putchar('\n');
    puts("The inOrderQueue:");
    inOrderTraverse(T);
    putchar('\n');
    puts("The postOrderQueue:");
    postOrderTraverse(T);
    putchar('\n');

    puts("\nDeleting BiTree ...");
    destroyBiTree(&T);
}


void fcreateBiTree(BiTree *T, char s[]){
    ElemType ch;
    printf("s = %s\n", s);
    sscanf(s, "%1c", &ch);
    puts("sscanf over");
    if(ch == '@')
        *T = NULL;
    else{
        *T = (BiTree)malloc(sizeof(BNode));
        if(!(*T))
            exit(0);
        (*T)->data = ch;
        createBiTree(&((*T)->lc));
        createBiTree(&((*T)->rc));
        puts("creating...");
    }
    puts("fcreate over");
}
