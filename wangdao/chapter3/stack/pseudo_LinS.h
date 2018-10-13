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

void ExpIsCorrect(char exp[], int n)
{	
	SeqStack myStack;
	int i;
	char c;

	StackInitiate(&myStack);
	for(i=0;i<n;i++)
	{
		if((exp[i]=='(')||(exp[i]=='[')||(exp[i]=='{'))
			StackPush(&myStack,exp[i]);

		else if(exp[i]==')'&& StackNotEmpty(myStack)&& StackTop(myStack,&c)&&c=='(')
			StackPop(&myStack,&c);
		else if(exp[i]==')'&& StackNotEmpty(myStack)&& StackTop(myStack,&c)&&c!='(')
		{
		printf("左右括号配对次序不正确！\n");
		return;
		}

		else if(exp[i]==']'&&StackNotEmpty(myStack)&&StackTop(myStack,&c)&&c=='[')
			StackPop(&myStack,&c);
		else if(exp[i]==']'&&StackNotEmpty(myStack)&&StackTop(myStack,&c)&&c!='[')
		{
		printf("左右括号配对次序不正确！\n");
		return;
		}

		else if(exp[i]=='}'&&StackNotEmpty(myStack)&&StackTop(myStack,&c)&&c=='{')
			StackPop(&myStack,&c);
		else if(exp[i]=='}'&&StackNotEmpty(myStack)&&StackTop(myStack,&c)&&c!='{')
		{
		printf("左右括号配对次序不正确！\n");
		return;
		}

		else if (((exp[i]==')')||(exp[i]==']')||(exp[i]=='}'))
			&&!StackNotEmpty(myStack))
		{
			printf("右括号多于左括号！\n");
			return;
		}
	}

	if(StackNotEmpty(myStack))
		printf("左括号多于右括号！\n");
	else 
		printf("左右括号匹配正确！\n");
}
