//typedef char ElemType;
//#define MaxSize 20

#include <stdbool.h>
#include <stdlib.h> //malloc,free,exit

typedef struct BNode{
    ElemType data;
    struct BNode *lc, *rc;
}BNode,*BiTree;      //not origin

void initBiTree(BiTree *T);
void destroyBiTree(BiTree *T);
void createBiTree(BiTree *T);
void createBiTree_NR(BiTree *T, ElemType *bt, int *con);//preOrder
bool insLeftC(BiTree p, BiTree c);
bool insRightC(BiTree p, BiTree c);
BNode *point(BiTree T, ElemType e);     //search for specified value node
ElemType getLeftC(BiTree T, ElemType e);//if(point),return point(T,e)->lc
ElemType getRightC(BiTree T, ElemType e);
bool delLeftC(BiTree p);    
bool delRightC(BiTree p);

//traverse BiTree
void preOrderTraverse(BiTree T);
void preOrder_nr(BiTree T);
void inOrderTraverse(BiTree T);
void inOrder_nr(BiTree T);
void postOrderTraverse(BiTree T);
void postOrder_nr(BiTree T);

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

//recursively create BiTree by preOrder
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

//No need to input
void createBiTree_NR(BiTree *T, ElemType *bt, int *con){
    ElemType ch;
    ch = bt[(*con)++];
    if(ch == '@')
        *T = NULL;
    else{
        *T = (BiTree)malloc(sizeof(BNode));
        if(!(*T))
            exit(0);
        (*T)->data = ch;
        createBiTree_NR(&((*T)->lc), bt, con);
        createBiTree_NR(&((*T)->rc), bt, con);
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

//search for the point of node which Elem=e 
BNode *point(BiTree T, ElemType e){
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

//top point at stacktop elem's hat
//int top = 0;
//push: top++//pop:  --top
void preOrder_nr(BiTree T){
    BiTree stack[MaxSize];
    int top = -1;       //top point at stacktop elem
    BNode *p = T;

    while(p || top>=0){     //is not empty
        if(p){              //or (while,if)
            printf("%2c", p->data);
            stack[++top] = p;   //2bs
            p = p->lc;
            printf("i");
        }
        else{               //is not empty
            p = stack[top--];
            p = p->rc;
            printf("o");
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

void inOrder_nr(BiTree T){
    BiTree stack[MaxSize];      //save bnode point
    int top = 0;    //init
    BNode *p = T;

    while(p || top>0){          //1.recursion end conditon
        if(p){
            stack[top++] = p;   //2.push stack with returnV, Actual parameters
            p = p->lc;
        }
        else{
            p = stack[--top];   //3.pop stack
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

void postOrder_nr(BiTree T){
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
