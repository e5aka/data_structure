#include<stdio.h>
#define MaxSize 100
typedef int DataType;
#include"SeqList.h"
void main(void)
{
	SeqList mylist;
	int i,x,a;
	ListInitiate(&mylist);
	printf("存在的数：");
	for(i=0;i<10;i++)
	{	
		printf("%d   ",i);
		if(ListInsert(&mylist,i,i+1)==0)
		{	
			printf("错误!\n");
			return;
		}
	}
	printf("\n请输入一个数：");
	scanf("%d",&a);
	if(a<0||a>9)
		printf("输入错误！\n");
	else	
	{
		for(i=0;i<ListLength(mylist);i++)
		{
			if(ListGet(mylist,i,&x)==0)
			{
				printf("错误!\n");
				return;
			}
			if(a==i)printf("找到%d存在于数组\n",a);			
		}
		if(a>i||a<0)
			printf("找不到%d存在于数组\n",a);
	}
}