#include <stdbool.h>

typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void initQueue(LinkQueue *q);
bool isEmpty(LinkQueue Q);
bool enQueue(LinkQueue *q, ElemType e);
bool deQueue(LinkQueue *q, ElemType *e);
bool getHead(LinkQueue Q, ElemType *x);
bool clearQueue(LinkQueue *Q);

//1>.初始化队列
void initQueue(LinkQueue *q){
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));   //建立头节点
    if(!q->front)   exit(0);
    q->front->next = NULL;
}

//2>.判断队空否
bool isEmpty(LinkQueue Q){
    if(Q.front == Q.rear)
    //if(Q.rear->next == NULL)
        return true;
    else 
        return false;
}

//3>.入队操作
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

//3>.出队操作
bool deQueue(LinkQueue *q, ElemType *e){
    QueuePtr p;
    if(isEmpty(*q)) return false;
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p)        //若原队仅一个节点，删除后变空
        q->rear = q->front;
    free(p);
    return true;
}

bool getHead(LinkQueue Q, ElemType *x){
    if(isEmpty(Q))
        return false;
    *x = Q.front->next->data; 
    return true;
}

bool clearQueue(LinkQueue *Q){
    while(Q->front != NULL){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}
