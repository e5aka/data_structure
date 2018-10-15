#define MaxSize 8
typedef char ElemType;
typedef struct DQueue{
    ElemType data[MaxSize];
    int end1, end2;
}DQueue;

#include <stdio.h>
#include <stdbool.h>

bool enQueue(DQueue *Q, ElemType e, int tag){
    switch(tag){
        case 1://表示在队列左端入队
            if(Q->end1 != Q->end2){
                Q->data[Q->end1] = e;
                Q->end1 = (Q->end1-1)%MaxSize;
                return true;
            }else
                return false;
        case 2://右端入队
            if(Q->end1 != Q->end2){
                Q->data[Q->end2] = e;
                Q->end2 = (Q->end2+1)%MaxSize;
                return true;
            }else
                return false;
    }
    return false;
}

bool deQueue(DQueue *Q, ElemType *e, int tag){
    switch(tag){
        case 1://表示在队列左端出队
            if(((Q->end1+1)%MaxSize) != Q->end2){
                Q->end1 = (Q->end1+1)%MaxSize;
                *e = Q->data[Q->end1];
                return true;
            }else
                return false;
        case 2://右端
            if(((Q->end2-1)%MaxSize) != Q->end1){
                Q->end2 = (Q->end2-1)%MaxSize;
                *e = Q->data[Q->end2];
                return true;
            }else
                return false;
    }
    return false;
}

int main(int argc, char *argv[]){
    DQueue Q;
    char ch;
    Q.end1 = 3;
    Q.end2 = 4;

    //a,b,c从左端入队
    if(!enQueue(&Q, 'a', 1))
        printf("Queue is full : a\n");
    else
        printf("a左端入队\n");

    if(!enQueue(&Q, 'b', 1))
        printf("Queue is full : b\n");
    else
        printf("b左端入队\n");

    if(!enQueue(&Q, 'c', 1))
        printf("Queue is full : c\n");
    else
        printf("c左端入队\n");

    //d,e从右端入队
    if(!enQueue(&Q, 'd', 2))
        printf("Queue is full : d\n");
    else
        printf("d右端入队\n");

    if(!enQueue(&Q, 'e', 2))
        printf("Queue is full : e\n");
    else
        printf("e右端入队\n");

    //c,b,d,e依次出队
    printf("队列左端出队一次:");
    deQueue(&Q, &ch, 1);
    printf("%c\n", ch);

    printf("队列左端出队一次:");
    deQueue(&Q, &ch, 1);
    printf("%c\n", ch);
    
    printf("队列右端出队一次:");
    deQueue(&Q, &ch, 2);
    printf("%c\n", ch);

    printf("队列右端出队一次:");
    deQueue(&Q, &ch, 2);
    printf("%c\n", ch);
}
