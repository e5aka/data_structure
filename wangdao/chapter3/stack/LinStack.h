//#define MaxSize 20
typedef struct {
    ElemType *stack;
	int top;
}SeqStack;

void StackInitiate(SeqStack *s) {
	s->stack=(ElemType *)malloc(sizeof(ElemType)*MaxSize);
	s->top=0;
}

int StackNotEmpty(SeqStack s) 
{
	if(s.top<=0) return 0;
	else return 1;
}

int StackPush(SeqStack *s,ElemType x)  
{
	if(s->top>=MaxSize)
	{
		printf("堆栈已满无法插入！\n");
		return 0;
	}
	else 
	{
		s->stack[s->top]=x;
		s->top++;
		return 1;
	}

} 

int StackPop(SeqStack *s,ElemType *x) 
{
	if(s->top <=0)
	{
		printf("堆栈已空，无数据元素出栈！\n");
		return 0;
	}
	else
	{
		s->top--;
		*x=s->stack[s->top];
		return 1;
	}
}

int StackTop(SeqStack s,ElemType *d) 
{
	if(s.top<=0)
	{
		printf("堆栈已空！\n");
		return 0;
	}
	else
	{
		*d=s.stack[s.top-1];
		return 1;
	}
}
