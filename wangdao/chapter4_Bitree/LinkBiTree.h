//typedef char ElemType;
//#define MaxSize 20

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> //malloc,free,exit

typedef struct BNode{
    ElemType data;
    struct BNode *lc, *rc;
}BNode,*BiTree;      //not origin

void initBiTree(BiTree *T);
void destroyBiTree(BiTree *T);
void createBiTree(BiTree *T);
bool insLeftC(BiTree p, BiTree c);
bool insRightC(BiTree p, BiTree c);
BiTree point(BiTree T, ElemType e);//search for specified value node
ElemType getLeftC(BiTree T, ElemType e);
ElemType getRightC(BiTree T, ElemType e);
bool delLeftC(BiTree p);
bool delRightC(BiTree p);

//traverse BiTree
void preOrderTraverse(BiTree T);
void preOrderNoRecur(BiTree T);
void inOrderTraverse(BiTree T);
void inOrderNoRecur(BiTree T);
void postOrderTraverse(BiTree T);
void postOrderNoRecur(BiTree T);

void initBiTree(BiTree *T){
    *T = NULL;
}

void destroyBiTree(BiTree *T){
    if(*T){
        if((*T)->lc)
            destroyBiTree(&((*T)->lc));
        if((*T)->rc)
            destroyBiTree(&((*T)->rc));
        free(*T);
        *T = NULL;
    }
}

//recursively create BiTree
void createBiTree(BiTree *T){
    ElemType ch;
    scanf("%c", &ch);
    if(ch == '@')
        *T = NULL;
    else{
        *T = (BiTree)malloc(sizeof(BNode));
        if(!(*T))
            exit(0);
        (*T)->data = ch;
        createBiTree(&((*T)->lc));
        createBiTree(&((*T)->rc));
    }
}

//c ins into p as LeftC
bool insLeftC(BiTree p, BiTree c){
    if(p){
        c->rc = p->lc;
        p->rc = c;
        return true;
    }
    return false;
}

bool insRightC(BiTree p, BiTree c){
    if(p){
        c->rc = p->rc;
        p->rc = c;
        return true;
    }
    return false;
}

BiTree point(BiTree T, ElemType e){
    BiTree Q[MaxSize];
    int front = 0;
    int rear = 0;
    BNode *p;

    if(T){
        Q[rear++] = T;  //enQueue

        while(front !=rear){ //no empty queue
            p = Q[front++]; //deQueue
            if(p->data == e)
                return p;
            if(p->lc)
                Q[rear++] = p->lc;
            if(p->rc)
                Q[rear++] = p->rc;
        }
    }
    return NULL;
}

ElemType getLeftC(BiTree T, ElemType e){
    BiTree p;
    if(T){
        p = point(T, e);
        if(p && p->lc)
            return p->lc->data;
    }
    return -1;
}

ElemType getRightC(BiTree T, ElemType e){
    BiTree p;
    if(T){
        p = point(T, e);
        if(p && p->rc)
            return p->rc->data;
    }
    return -1;
}

bool delLeftC(BiTree T){
    if(T){
        destroyBiTree(&(T->lc));
        return true;
    }
    return false;
}

bool delRightC(BiTree T){
    if(T){
        destroyBiTree(&(T->rc));
        return true;
    }
    return false;
}

void preOrderTraverse(BiTree T){
    if(T){
        printf("%2c", T->data); //assume ElemType = char
        preOrderTraverse(T->lc);
        preOrderTraverse(T->rc);
    }
}

void preOrderNoRecur(BiTree T){
    BiTree stack[MaxSize];
    //top point at stacktop elem
    int top = -1;
    //int top = 0;
    //top point at stacktop elem's hat
    //push: top++
    //pop:  --top
    BNode *p = T;

    while(p || top>=0){     //is not empty
        if(p != NULL){
            printf("%2c", p->data);
            stack[++top] = p;   //2bs
            p = p->lc;
        }
        else{               //is not empty
            p = stack[top--];
            p = p->rc;
        }
    }
}

void inOrderTraverse(BiTree T){
    if(T){
        inOrderTraverse(T->lc);
        printf("%2c", T->data);
        inOrderTraverse(T->rc);
    }
}

void inOrderNoRecur(BiTree T){
    BiTree stack[MaxSize];    
    int top = 0;
    BNode *p = T;

    while(p || top>0){
        if(p){
            stack[top++] = p;
            p = p->lc;
        }
        else{
            p = stack[--top];
            printf("%2c", p->data);
            p = p->rc;
        }
    }
}

void postOrderTraverse(BiTree T){
    if(T){
        postOrderTraverse(T->lc);
        postOrderTraverse(T->rc);
        printf("%2c", T->data);
    }
}

void postOrderNoRecur(BiTree T){
    BiTree stack[MaxSize];
    int top =0;
    BNode *p, *q;
    p = T;
    q = NULL;

    while(p || top>0){
        if(p){
            stack[top++] = p;
            p = p->lc;
        }
        else{
            p = stack[top-1];
            if(p->rc==NULL || p->rc==q){
                printf("%2c", p->data);
                q = p;
                p = NULL;
                top--;
            }
            else
                p = p->rc;
        }
    }
}
