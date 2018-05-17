#include<stdio.h>
void max(int *p,int *q)
{
	if(*p>=*q) 
	printf("%d\t%d\n",*p,*q);
	else
	printf("%d\t%d\n",*q,*p);
}

void main()
{
	int a,b;
	printf("输入两个数：");
	scanf("%d%d",&a,&b);
	max(&a,&b);
}
