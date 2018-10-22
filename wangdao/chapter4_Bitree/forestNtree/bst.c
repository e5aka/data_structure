typedef int ElemType;
#define MaxSize 20

#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

void main(){
    ElemType str[] = {37, 32, 35, 62, 82, 95, 73, 12, 5};
    ElemType str2[] = {55, 43, 66, 88, 18, 80, 33 ,21, 72};
    int i, len = sizeof(str)/sizeof(str[0]);
    BSTree p, T=NULL;

    create_BST(&T, str2, len);
    printf("InOredr Traverse:\n");
    inOrder(T);
    putchar('\n');

    ElemType x=66;
    p = search_BST_nr(T, x);
    if(p)
        printf("Success, %d exist\n", x);
    else
        printf("Error\n");

    delete_BST(&T, x);
    printf("After deleted %d, inorder traverse:\n", x);
    inOrder(T);
    putchar('\n');

    puts("\nDevil may cry");

}
