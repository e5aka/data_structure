#include<stdio.h>
void Display1 (int n)
{
	int i;
	if(n>0) Display1(n-1);
	for(i=1;i<=n;i++)
	{
		printf("%-4d",n);	
	}
	printf("\n");

}

void Display2 (int n)
{
	int i,k;
	for(i=1;i<=n;i++)
	{	
		for(k=1;k<=i;k++)
		{
		printf("%-4d",i);
		}
	printf("\n");
	}
}


void main(void)
{
	int n;
	printf("ÇëÊäÈëNµÄÖµ£º");
	scanf("%d",&n);
	Display1(n);
	printf("\n");
	Display2(n);
}
