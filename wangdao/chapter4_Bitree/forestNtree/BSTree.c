typedef int ElemType;
#define MaxSize 20

typedef struct BSTNode{
    ElemType key;
    struct BSTNode *lc, *rc;
}BSTNode,*BiTree;      //not origin

#include <stdio.h>
#include <stdlib.h>

BSTNode *search_BST_nr(BiTree T, ElemType key);
BSTNode search_BST(BiTree T, ElemType key);
int insert_BST(BiTree *T, ElemType k);
void create_BST(BiTree *T, ElemType str[], int n);
void delNode(BiTree *T);
int delete_BST(BiTree *T, ElemType x);

BSTNode *search_BST_nr(BiTree T, ElemType key){
    BSTNode *p = NULL;
    while(T && key!=T->key){
        p = T;
        if(key < T->key)
            T = T->lc;
        else
            T = T->rc;
    }
    return T;
}

BSTNode search_BST(BiTree T, ElemType key);

int insert_BST(BiTree *T, ElemType k){
    if(!(*T)){
        (*T) = (BSTNode*)malloc(sizeof(BSTNode));
        (*T)->key = k;
        (*T)->lc = (*T)->rc = NULL;
        return 1;
    }
    else if(k == (*T)->key)
        return 0;
    else if(k < (*T)->key)
        return insert_BST(&(*T)->lc, k);
    else
        return insert_BST(&(*T)->rc, k);
}


void create_BST(BiTree *T, ElemType *str, int n){
    int i = 0;
    *T = NULL;

    while(i<n){
        insert_BST(&(*T), str[i]);
        i++;
    }
}

void inOrder(BiTree T){
    if(T){
        inOrder(T->lc);
        printf("%d ", T->key);
        inOrder(T->rc);
    }
}

void delNode(BiTree *T);
    
int delete_BST(BiTree *T, ElemType x);

void main(){
    ElemType str[] = {37, 32, 35, 62, 82, 95, 73, 12, 5};
    int i, len = sizeof(str)/sizeof(str[0]);
    BiTree p, T=NULL;

    create_BST(&T, str, len);
    printf("InOredr Traverse:");
    inOrder(T);
    putchar('\n');

    ElemType x=71;
    printf("search fo %d\n", x);
    p = search_BST_nr(T, x);
    if(p)
        printf("Success, %d exist\n", x);
    else
        printf("Error\n");

    //delete_BST(&T, x);
    printf("After deleted %d, inorder traverse:\n", x);
    inOrder(T);
    putchar('\n');

    puts("\nDevil may cry");

}
