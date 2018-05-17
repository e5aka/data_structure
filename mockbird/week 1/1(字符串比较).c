#include<stdio.h>
#include<string.h>
 max(char a[8],char b[8])
{
	if(strcmp(a,b)>0) 
	printf("%s\t%s\n",a,b);
	else
	printf("%s\t%s\n",a,b);
}

void main()
{
	char a[8]="",b[8]="";
	printf("输入两个数：");
	gets(a);	gets(b);
	max(a,b);
}