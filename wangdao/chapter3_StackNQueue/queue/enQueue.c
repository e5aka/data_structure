typedef char ElemType;

#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"
//#include "CirleSqQueue.h"

int main(int argc, char *argv[])
{
    ElemType e;
    LinkQueue q;

    initQueue(&q);
    printf("Please input a string into a queue\n");
    scanf("%c",&e);
    while(e!='@'){
        enQueue(&q, e);
        scanf("%c",&e);
    }
    printf("The string into the queue is \n");
    while(q.front != q.rear){
        deQueue(&q,&e);
        printf("%c",e);
    }
    printf("\n");
    
    return 0;
}
