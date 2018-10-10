#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100
typedef char ElemType;
#include"SqStack.h"

void main(void)
{
	char a[MaxSize];	
	int n;
	fgets(a,sizeof(a),stdin);
	n=strlen(a);
	ExpIsCorrect(a,n);
}
