//typedef char ElemType;
//#define MaxSize 20

#include "LinkBiTree.h"

void levelOrder(BiTree T);  //display BiTree by level
int leafNum(BiTree T);

void levelOrder(BiTree T){
    BiTree queue[MaxSize];
    BNode *p;
    int front, rear;

    front = rear = -1;  //isEmptyQ
    queue[++rear] = T;  //enQueue
    
    while(front != rear){   //if not Empty
        //front = (front+1)%MaxSize;
        p = queue[++front];
        printf("%c ", p->data);
        if(p->lc != NULL){
            //rear = (rear+1)%MaxSize;
            queue[++rear] = p->lc;
        }
        if(p->rc != NULL){
            //rear = (rear+1)%MaxSize;
            queue[++rear] = p->rc;
        }
    }
}

int leafNum(BiTree T){
    if(!T)
        return 0;
    else
        if(!T->lc && !T->rc)
            return 1;
        else
            return leafNum(T->lc)+leafNum(T->rc);
}
