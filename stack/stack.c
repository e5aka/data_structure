#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACK_INIT_SIZE 20
#define STACK_INCREMENT 10

typedef char ElemType;
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;

void initStack(sqStack *s){
    s->base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(!s->base)    exit(0);
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
}

void push(sqStack *s, ElemType e){
    if(s->top - s->base >= s->stacksize){
        s->base = (ElemType *)realloc(s->base, (s->stacksize + STACK_INCREMENT)*sizeof(ElemType));
        if(!s->base)    exit(0);
        s->top = s->base + s->stacksize;
        s->stacksize = s->stacksize + STACK_INCREMENT;
    }
    *(s->top)=e;
    s->top++;
}

void pop(sqStack *s, ElemType *e){
    if(s->top == s->base)   return;
    *e = *--(s->top);
}

int stackLen(sqStack s){
    return (s.top-s.base);
}

void main(){
    ElemType c;
    sqStack s;
    int len, i, sum=0;
    printf("Please input a binary digit\n");
    initStack(&s);
    scanf("%c",&c);
    while(c!='#'){
        push(&s, c);
        scanf("%c", &c);
    }
    getchar();
    len = stackLen(s);
    for(i=0;i<len;i++){
        pop(&s,&c);
        sum = sum+(c-48);
    }
    printf("Decimal is %d\n", sum);
    getchar();
}
