#include<stdio.h>
#define MaxSize 100
typedef int DataType;
#include"SeqList.h"
void main()
{
	SeqList myList;
	int i,x,a[10];
	ListInitiate(&myList);
	for(i=0;i<10;i++)
	{	scanf("%d",&a[i]);
		if(ListInsert(&myList,i,i+1)==0)
		{
			printf("´íÎó£¡\n");
			return;
		}
	}
	for(i=0;i<ListLength(myList);i++)
	{
		if(ListGet(myList,i,&x)==0)
		{
			printf("´íÎó£¡\n");
			return;
		}
		else 
			for(i=0;i<10;i++)
			printf("%d    ",a[i]);
	}
}