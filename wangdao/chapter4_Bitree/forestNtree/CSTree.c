typedef int ElemType;
#define MaxSize 20

#include <stdio.h>
#include <stdlib.h>

//Child Sibling Expression
typedef struct CSNode{
    ElemType data;
    struct CSNode *fc, *ns; //first child, next sibling
}CSNode, *CSTree;

void initCSTree(CSTree *T);
void destroyCSTree(CSTree *T);
void createCSTree(CSTree *T, ElemType *e, int *index);
int getDepthCST(CSTree T);
void preTraverseCST(CSTree T);
void postTraverseCST(CSTree T);
void printCST(ElemType *e);
int getLeaves(CSTree T);

void initCSTree(CSTree *T){
    *T = 0;
}

void destroyCSTree(CSTree *T){
    CSTree p = *T;
    if(p){
        destroyCSTree(&(p->fc));
        destroyCSTree(&(p->ns));
        free(p);
        *T = 0;
    }
}

void createCSTree(CSTree *T, ElemType *e, int *index){
    if(e[*index] == 0){
        *T = 0;
        (*index)++;
    }else{
        *T = (CSNode*)malloc(sizeof(CSNode));
        (*T)->data = e[(*index)++];
        createCSTree(&((*T)->fc), e, index);    //2bt
        createCSTree(&((*T)->ns), e, index);
        return;
    }
}

int getDepthCST(CSTree T){
    CSNode *p;
    int k, d = 0;
    if(!T)
        return 0;
    p = T->fc;
    while(p){
        k = getDepthCST(p);
        if(d<k)
            d = k;
        p = p->ns;
    }
    return d+1;
}

int getDepthWD(CSTree T){
    int hc, hs;
    if(!T)
        return 0;
    else{
        hc = getDepthWD(T->fc); //fc height
        hs = getDepthWD(T->ns); //ns heigth
        if(hc+1 > hs)
            return hc+1;
        else
            return hs;
    }
}

void preTraverseCST(CSTree T){
    if(T){
        printf("%c ", T->data);
        preTraverseCST(T->fc);
        preTraverseCST(T->ns);
    }
}

void postTraverseCST(CSTree T){
    if(T){
        postTraverseCST(T->fc);
        printf("%c ", T->data);
        postTraverseCST(T->ns);
    }
}

void printCST(ElemType *e){
    printf("%c ", *e);
}

int getLeaves(CSTree T){
    if(!T)
        return 0;
    if(!T->fc)
        return getLeaves(T->ns)+1;
    else
        return getLeaves(T->fc)+getLeaves(T->ns);
}

//               A
//             / | \
//            B  C  D
//           / \     \
//          E   F     G
//            / | \
//           H  I  J
void main(){
    int test[] = {'A','B','E',0,'F','H',0,'I',0,'J',0,0,0,'C',0,'D','G',0,0,0,0};
    int h = 0;
    CSTree T;
    initCSTree(&T);
    createCSTree(&T, test, &h);
    puts("Preroot traverse Tree:");
    preTraverseCST(T);
    putchar('\n');
    puts("Postroot traverse Tree:");
    postTraverseCST(T);
    putchar('\n');

    printf("The depth of tree is : %d\n", getDepthCST(T));
    printf("depth by wda : %d\n", getDepthWD(T));
    printf("The leaves : %d\n", getLeaves(T));
    putchar('\n');

    destroyCSTree(&T);
}
