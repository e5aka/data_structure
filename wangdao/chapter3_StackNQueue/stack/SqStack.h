//#define MaxSize 10
//typedef int ElemType
#include <stdbool.h>

typedef struct {
    ElemType data[MaxSize];
	int top;
}SqStack;

void initStack(SqStack *S);
bool isEmpty(SqStack S);
bool stackPush(SqStack *S, ElemType x);
bool stackPop(SqStack *S, ElemType *x);
bool getTop(SqStack S, ElemType *d);

void initStack(SqStack *S) 
{
	S->top = -1;    //not a *S
}

bool isEmpty(SqStack S) 
{
	if(S.top == -1) 
        return true;
	else 
        return false;
}

bool stackPush(SqStack *S, ElemType x) 
{
	if(S->top == MaxSize-1) {
		printf("堆栈已满无法插入！\n");
		return false;
	} else {
        S->data[++S->top] = x;
		return true;
	}
} 

bool stackPop(SqStack *S, ElemType *x) 
{
	if(S->top == -1) {
		printf("堆栈已空，无数据元素出栈！\n");
		return false;
	} else {
        *x = S->data[S->top--];
		return true;
	}
}

bool getTop(SqStack S, ElemType *d) 
{
	if(S.top == -1) {
		printf("堆栈已空！\n");
		return false;
	}else{
		*d = S.data[S.top];
		return true;
	}
}
