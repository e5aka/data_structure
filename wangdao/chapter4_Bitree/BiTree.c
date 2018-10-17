typedef char ElemType;
#define MaxSize 20;

#include <stdio.h>
#include <stdbool.h>

typedef struct BNode{
    ElemType data;
    struct BNode *lc;
    struct BNode *rc;
}Node,*BiTree;      //not origin

void initBiTree(BiTree *T);
void destroy(BiTree *T);
void createBiTree(BiTree *T);
bool insLeftC(BiTree p, BiTree c);
bool insRightC(BiTree p, BiTree c);
BiTree locateElem(BiTree T, ElemType e);
ElemType getLeftC(BiTree T, ElemType e);
ElemType getRightC(BiTree T, ElemType e);
bool DelLeftC(BiTree p);
bool DelRightC(BiTree p);

void initBiTree(BiTree *T){


}
void destroy(BiTree *T);
void createBiTree(BiTree *T);
bool insLeftC(BiTree p, BiTree c);
bool insRightC(BiTree p, BiTree c);
BiTree locateElem(BiTree T, ElemType e);
ElemType getLeftC(BiTree T, ElemType e);
ElemType getRightC(BiTree T, ElemType e);
bool DelLeftC(BiTree p);
bool DelRightC(BiTree p);

void main(){
    puts("It's finally over");
}
