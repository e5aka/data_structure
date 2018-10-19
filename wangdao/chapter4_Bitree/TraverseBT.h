//typedef char ElemType;
//#define MaxSize 20

#include "LinkBiTree.h"

void levelOrder(BiTree T);  //display BiTree by level
int leafNum(BiTree T);      //count left nodes
int notLeafNum(BiTree T);
void treePrint(BiTree T, int level);    //print by tree
int getDepth(BiTree T);

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
    else if(!T->lc && !T->rc)
        return 1;
    else
        return leafNum(T->lc)+leafNum(T->rc);
}

int notLeafNum(BiTree T){
    if(!T)
        return 0;
    else if(!T->lc && !T->rc)
        return 0;
    else 
        return notLeafNum(T->lc)+notLeafNum(T->rc)+1;
}

void treePrint(BiTree T, int level){
    int i;
    if(T == NULL)
        return;
    treePrint(T->rc, level+1);
    for(i=0;i<level;i++)
        printf("  ");
    printf("%c\n", T->data);
    treePrint(T->lc, level+1);
}

int getDepth(BiTree T){
    if(!T)
        return 0;
    return getDepth(T->lc)>getDepth(T->rc)?getDepth(T->lc)+1:getDepth(T->rc)+1;
}
