typedef char ElemType;
#define MaxSize 30

#include <stdio.h>
#include <stdlib.h>

//typedef enum {Link, Thread}PointerTag; //Link=0: point child//Thread=1: point priorP
typedef struct ThrNode{
    ElemType data;
    struct ThrNode *lc, *rc;
    //PointerTag lt, rt;
    int lt, rt;
}ThrNode, *ThrTree;

void initThrTree(ThrTree *T){
    *T = NULL;
}

int con = 0;
char bt[MaxSize] = "ABD@G@@EH@@I@@CF@J@@@";
//No need to input
void createThrTree_NR(ThrTree *T){
    ElemType ch;
    ch = bt[con++];
    if(ch == '@')
        *T = NULL;
    else{
        *T = (ThrTree)malloc(sizeof(ThrNode));
        if(!(*T))
            exit(0);
        (*T)->data = ch;
        createThrTree_NR(&((*T)->lc));
        createThrTree_NR(&((*T)->rc));
    }
}

void inThread(ThrTree *p, ThrTree *pre){
    if(*p){
        inThread(&(*p)->lc, &(*pre));
        if(!(*p)->lc){
            (*p)->lc = *pre;
            (*p)->lt = 1;
        }
        if(*pre && !(*pre)->rc){
            (*pre)->rc = *p;
            (*pre)->rt = 1;
        }
        *pre = *p;
        inThread(&(*p)->rc, &(*pre));
    }
}

//create thread BitTree in order 
void createInThread(ThrTree T){
    ThrTree pre = NULL;
    if(T){
        inThread(&T, &pre);
        pre->rc = NULL;
        pre->rt = 1;
    }
}

ThrNode *firstNode(ThrNode *p){
    while(p->lt == 0)
        p = p->lc;
    return p;
}

ThrNode *lastNode(ThrNode *p){  //2bs
    while(p->rt == 0)
        p = p->rc;
    return p;
}

ThrNode *nextNode(ThrNode *p){
    if(p->rt == 0)
        return firstNode(p->rc);
    else
        return p->rc;
}

ThrNode *priorNode(ThrNode *p){ //2bs
    if(p->lt == 0)
        return lastNode(p->lc);
    else
        return p->lc;
}

void inOrder(ThrTree T){
    ThrNode *p;
    for(p=firstNode(T);p!=NULL;p=nextNode(p))
        printf("%c ", p->data);
}

void main(){
    ThrTree T;

    initThrTree(&T);
    puts("Create BiTree by preOrderQueue(end with @)");
    printf("%s\n", bt);
    createThrTree_NR(&T);
    printf("It's over\n");

    inOrder(T);
}
