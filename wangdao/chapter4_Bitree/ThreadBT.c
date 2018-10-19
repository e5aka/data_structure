typedef char ElemType;
#define MaxSize 30

#include <stdio.h>

typedef enum {Link, Thread}PointerTag; //Link=0: point child//Thread=1: point priorP
typedef struct Node{
    ElemType data;
    struct Node *lc, *rc;
    PointerTag lt, rt;
}BThrNode, *BThrTree;


void main(){
    printf("Devil may cry\n");
}
