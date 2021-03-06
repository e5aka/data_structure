//#define MaxSize 10
//typedef int ElemType
#include <stdbool.h>

typedef struct QNode{
    ElemType data;
    struct QNode *next;
}*QueuePtr,QNode;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void initQueue(LinkQueue *q);
bool isEmptyQ(LinkQueue Q);
bool enQueue(LinkQueue *q, ElemType e);
bool deQueue(LinkQueue *q, ElemType *e);
bool getHead(LinkQueue Q, ElemType *x);
bool destroyQ(LinkQueue *Q);

//1>.初始化队列
void initQueue(LinkQueue *q){
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));   //建立头节点
    if(!q->front)   exit(0);
    q->front->next = NULL;
}

//2>.判断队空否
bool isEmptyQ(LinkQueue Q){
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
    if(isEmptyQ(*q)) return false;
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p)        //若原队仅一个节点，删除后变空
        q->rear = q->front;
    free(p);
    return true;
}

bool getHead(LinkQueue Q, ElemType *x){
    if(isEmptyQ(Q))
        return false;
    *x = Q.front->next->data; 
    return true;
}

bool destroyQ(LinkQueue *Q){
    while(Q->front != NULL){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}
