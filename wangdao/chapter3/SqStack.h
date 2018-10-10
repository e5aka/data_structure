#include <stdbool.h>
typedef struct {
    ElemType data[MaxSize];
	int top;
}SqStack;

void initStack(SqStack *S) 
{
	S->top = -1;
}

bool stackEmpty(SqStack S) 
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

void ExpIsCorrect(char exp[], int n)
{	
	SqStack myStack;
	int i;
	char c;

	initStack(&myStack);
	for(i=0;i<n;i++)
	{
		if((exp[i]=='(')||(exp[i]=='[')||(exp[i]=='{'))
			stackPush(&myStack,exp[i]);

		else if(exp[i]==')'&& stackEmpty(myStack)&& getTop(myStack,&c)&&c=='(')
			stackPop(&myStack,&c);
		else if(exp[i]==')'&& stackEmpty(myStack)&& getTop(myStack,&c)&&c!='(')
		{
		printf("左右括号配对次序不正确！\n");
		return;
		}

		else if(exp[i]==']'&&stackEmpty(myStack)&&getTop(myStack,&c)&&c=='[')
			stackPop(&myStack,&c);
		else if(exp[i]==']'&&stackEmpty(myStack)&&getTop(myStack,&c)&&c!='[')
		{
		printf("左右括号配对次序不正确！\n");
		return;
		}

		else if(exp[i]=='}'&&stackEmpty(myStack)&&getTop(myStack,&c)&&c=='{')
			stackPop(&myStack,&c);
		else if(exp[i]=='}'&&stackEmpty(myStack)&&getTop(myStack,&c)&&c!='{')
		{
		printf("左右括号配对次序不正确！\n");
		return;
		}

		else if (((exp[i]==')')||(exp[i]==']')||(exp[i]=='}'))
			&&!stackEmpty(myStack))
		{
			printf("右括号多于左括号！\n");
			return;
		}
	}

	if(stackEmpty(myStack))
		printf("左括号多于右括号！\n");
	else 
		printf("左右括号匹配正确！\n");
}
