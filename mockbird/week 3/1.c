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
	printf("������ʮ������");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		if(ListInsert(head,i,i+1)==0)
		{
		printf("����\n");
		return;
		}
	}
	for(i=0;i<ListLength(head);i++)
	{	
		if(ListGet(head,i,&x)==0)
		{
			printf("����!\n");
			return;
		}
	printf("%d    ",a[i]);
	}
	printf("\n");
	Destroy(&head);
}