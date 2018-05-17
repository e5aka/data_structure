#include<stdio.h>
#include<stdlib.h>
#define MaxStackSize 100
typedef int ElemType;
#include "SeqStack.h"

void main(void)
{
	SeqStack mystack;
	int i,x;
	int N; 
    printf("请输入十进制数N:");
	scanf("%d",&N);

	StackInitiate(&mystack);
		if(N==0)
		{
		StackPush(&mystack, i=0);	
		}
		while(N!=0)
		{	
			i=N%2;
			N=N/2;
			StackPush(&mystack, i);
		}
	
	
	printf("二进制数是:");
	while(StackNotEmpty(mystack)) 
	{
		StackPop(&mystack,&x);
		printf("%d",x);
	}
	printf("\n");
}
