#define MaxSize 10
typedef int ElemType;

#include<stdio.h>
#include<stdlib.h>
#include "SqStack.h"

int main(int argc, char *argv[]) {
	SqStack mystack;
    printf("The max stacksize is %d\n", sizeof(mystack));
	int x, i = 0, N;
    
    printf("N = ");
	scanf("%d", &N);
                                        
	initStack(&mystack);
    if(N == 0)
		stackPush(&mystack, i);	
    while(N != 0){	
        i = N%2;
        N = N/2;
        stackPush(&mystack, i);
    }
	printf("Out of stack queue:\n");
	while(!stackIsEmpty(mystack)) 
	{
		stackPop(&mystack, &x);
		printf("%d", x);
	}
	printf("\n");

    return 1;
}
