typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

#include <stdbool.h>

void initQueue(LinkQueue *q){
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));   //Head Node
    if(!q->front)   exit(0);
    q->front->next = NULL;
}

bool isEmpty(LinkQueue Q){
    if(Q.front == Q.rear)
        return true;
    else 
        return false;
}

bool enQueue(LinkQueue *q, ElemType e){
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!q->front)   exit(0);
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return true;
}

bool deQueue(LinkQueue *q, ElemType *e){
    QueuePtr p;
    if(isEmpty(*q)) return false;
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p)    
        q->rear = q->front;
    free(p);
    return true;
}

//bool getHead(LinkQueue Q, ElemType *x){
//    if(isEmpty(Q))
//        return false;
//    *x = 
//    return true;
//}
