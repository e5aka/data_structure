#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100
typedef char ElemType;
#include"SqStack.h"

void ExpIsCorrect(char exp[], int n);

int main(int argc, char *argv[])
{
	char a[MaxSize];	
	int n;
	fgets(a,sizeof(a),stdin);
	n=strlen(a);
	ExpIsCorrect(a,n);

    return 1;
}

void ExpIsCorrect(char exp[], int n)
{	
	SqStack myStack;
	int i;
	char c;

	initStack(&myStack);
	for(i=0;i<n;i++) {
		if((exp[i]=='(') || (exp[i]=='[') || (exp[i]=='{'))
			stackPush(&myStack, exp[i]); 
		else if(exp[i]==')' && !stackIsEmpty(myStack) && getTop(myStack,&c) && c=='(')
			stackPop(&myStack, &c);
		else if(exp[i]==')' && !stackIsEmpty(myStack) && getTop(myStack,&c) && c!='('){
            printf("左右括号配对次序不正确！\n");
            return;
		} 
		else if(exp[i]==']' && !stackIsEmpty(myStack) && getTop(myStack,&c) && c=='[')
			stackPop(&myStack, &c);
		else if(exp[i]==']' && !stackIsEmpty(myStack) && getTop(myStack,&c) && c!='['){
            printf("左右括号配对次序不正确！\n");
            return;
		} 
		else if(exp[i]=='}' && !stackIsEmpty(myStack) && getTop(myStack,&c) && c=='{')
			stackPop(&myStack, &c);
		else if(exp[i]=='}' && !stackIsEmpty(myStack) && getTop(myStack,&c) && c!='{'){
            printf("左右括号配对次序不正确！\n");
            return;
		} 
		else if(((exp[i]==')') || (exp[i]==']') || (exp[i]=='}'))
			&&stackIsEmpty(myStack)){
			printf("右括号多于左括号！\n");
			return;
		}
	}

	if(!stackIsEmpty(myStack))
		printf("左括号多于右括号！\n");
	else 
		printf("左右括号匹配正确！\n");
}
