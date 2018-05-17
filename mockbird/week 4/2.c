#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define MaxStackSize 100
typedef char ElemType;
#include"SeqStack.h"

void main(void)
{
	char a[MaxStackSize];	
	int n;
	gets(a);
	n=strlen(a);
	ExpIsCorrect(a,n);
}