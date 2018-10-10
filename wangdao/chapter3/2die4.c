#include<stdio.h>
#include<stdlib.h>
#include "SqStack.h"
#define MaxStackSize 100
typedef int ElemType;

void main(void) {
	SqStack mystack;
    printf("Mystack is %d\n", sizeof(mystack));
	int i, x;
	int N; 
    printf("N=");
	scanf("%d", &N);
                                        
	initStack(&mystack);
		if(N==0){
		stackPush(&mystack, i=0);	
		}
		while(N!=0){	
			i=N%2;
			N=N/2;
			stackPush(&mystack, i);
		}
	
	
	printf("Out of stace queue:\n");
	while(stackEmpty(mystack)) 
	{
		stackPop(&mystack, &x);
		printf("%d", x);
	}
	printf("\n");
}
