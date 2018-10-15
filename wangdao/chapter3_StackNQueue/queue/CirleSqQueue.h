//#define MaxSize 10
//typedef int ElemType
#define MaxSize 50
#include <stdbool.h>
#include <assert.h>

typedef struct QNode{
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;
typedef struct QNode *SCQueue; 

void initQueue(SqQueue *Q);
bool isEmpty(SqQueue Q);
bool enQueue(SqQueue *Q, ElemType x);
bool deQueue(SqQueue *Q, ElemType *x);
bool getHead(SqQueue Q, ElemType *x);

void initQueue(SqQueue *Q){
    Q->rear = Q->front = 0;
}

bool isEmpty(SqQueue Q){
    if(Q.rear == Q.front)
        return true;
    return false;
}

bool enQueue(SqQueue *Q, ElemType x){
    if((Q->rear+1)%MaxSize == Q->front)
        return false;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear+1)%MaxSize;
    return true;
}

bool deQueue(SqQueue *Q, ElemType *x){
    if(isEmpty(*Q))
        return false;
    *x = Q->data[Q->front];
    Q->front = (Q->front+1)%MaxSize;
    return true;
}

bool getHead(SqQueue Q, ElemType *x){
    if(isEmpty(Q))
        return false;
    *x = Q.data[Q.front];
    return true;
}
