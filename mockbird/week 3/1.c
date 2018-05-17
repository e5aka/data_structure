#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int DataType;
#include"LinList.h"

void main(void)
{
	SLNode * head;
	int a[10],i,x;

	ListInitiate(&head);
	printf("请输入十个数：");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		if(ListInsert(head,i,i+1)==0)
		{
		printf("错误！\n");
		return;
		}
	}
	for(i=0;i<ListLength(head);i++)
	{	
		if(ListGet(head,i,&x)==0)
		{
			printf("错误!\n");
			return;
		}
	printf("%d    ",a[i]);
	}
	printf("\n");
	Destroy(&head);
}