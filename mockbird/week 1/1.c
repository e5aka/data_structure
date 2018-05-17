#include<stdio.h>
void max (int a,int b)

{
	if(a>=b) 
	printf("%d > %d\n",a,b);
	else
	printf("%d > %d\n",b,a);
}

void main()
{
	int a,b;
    printf("请输入两个数字:");

	scanf("%d%d",&a,&b);
	max(a,b);
}
