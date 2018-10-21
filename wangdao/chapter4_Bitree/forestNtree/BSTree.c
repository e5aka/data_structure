typedef char ElemType;
#define MaxSize 20

typedef struct BSTNode{
    ElemType data;
    struct BSTNode *lc, *rc;
}BSTNode,*BiTree;      //not origin

#include <stdio.h>
//#include "../LinkBiTree.h"

BSTNode search_BST_nr(BiTree T, ElemType key, BSTNode *p);
BSTNode search_BST(BiTree T, ElemType key, BSTNode *p);
int insert_BST(BiTree *T, ElemType k);
void create_BST(BiTree *T, ElemType str[], int n);


void main(){

    puts("Devil may cry");

}
