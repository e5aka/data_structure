#include<stdio.h>
#define MaxSize 100
typedef int DataType;
#include"SeqList.h"
void main(void)
{
	SeqList mylist;
	int i,d,j,k;
	DataType x;

	ListInitiate(&mylist);
	for(i=0;i<10;i++)
	{		printf("%d   ",i);
		if(ListInsert(&mylist,i,i)==0)
		{	
			printf("����!\n");
			return;
		}
	}
	
	printf("\n");
	printf("ѡ��ɾ��������λ�ã�");
	scanf("%d",&d);
	if(ListDelete(&mylist,d,&x)==0)
	{
		printf("����!\n");
			return;
	}		
	for(i=0;i<ListLength(mylist);i++)
	{
		if(ListGet(mylist,i,&x)==0)
		{
			printf("����!\n");
			return;
		}
		else printf("%d   ",x);
	}

	printf("\n");
	printf("���������λ�ú���ֵ��");
	scanf("%d%d",&j,&k);
	if(ListInsert(&mylist,j,k)==0)
		{	
			printf("����!\n");
			return;
		}
	for(i=0;i<ListLength(mylist);i++)
	{
		if(ListGet(mylist,i,&x)==0)
		{
			printf("����!\n");
			return;
		}
		else printf("%d   ",x);
	}
}