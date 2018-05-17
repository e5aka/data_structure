typedef struct
{
    ElemType *stack;
	int top;
}
SeqStack;

void StackInitiate(SeqStack *s) 
{
	s->stack=(ElemType *)malloc(sizeof(ElemType)*MaxStackSize);
	s->top=0;
}

int StackNotEmpty(SeqStack s) 
{
	if(s.top<=0) return 0;
	else return 1;
}

int StackPush(SeqStack *s,ElemType x)  
{
	if(s->top>=MaxStackSize)
	{
		printf("��ջ�����޷����룡\n");
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
		printf("��ջ�ѿգ�������Ԫ�س�ջ��\n");
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
		printf("��ջ�ѿգ�\n");
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
		printf("����������Դ�����ȷ��\n");
		return;
		}

		else if(exp[i]==']'&&StackNotEmpty(myStack)&&StackTop(myStack,&c)&&c=='[')
			StackPop(&myStack,&c);
		else if(exp[i]==']'&&StackNotEmpty(myStack)&&StackTop(myStack,&c)&&c!='[')
		{
		printf("����������Դ�����ȷ��\n");
		return;
		}

		else if(exp[i]=='}'&&StackNotEmpty(myStack)&&StackTop(myStack,&c)&&c=='{')
			StackPop(&myStack,&c);
		else if(exp[i]=='}'&&StackNotEmpty(myStack)&&StackTop(myStack,&c)&&c!='{')
		{
		printf("����������Դ�����ȷ��\n");
		return;
		}

		else if (((exp[i]==')')||(exp[i]==']')||(exp[i]=='}'))
			&&!StackNotEmpty(myStack))
		{
			printf("�����Ŷ��������ţ�\n");
			return;
		}
	}

	if(StackNotEmpty(myStack))
		printf("�����Ŷ��������ţ�\n");
	else 
		printf("��������ƥ����ȷ��\n");
}