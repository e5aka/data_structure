#include<stdio.h>
#define MaxSize 100
typedef int DataType;
#include"SeqList.h"
void main(void)
{
	SeqList mylist;
	int i,x,a;
	ListInitiate(&mylist);
	printf("���ڵ�����");
	for(i=0;i<10;i++)
	{	
		printf("%d   ",i);
		if(ListInsert(&mylist,i,i+1)==0)
		{	
			printf("����!\n");
			return;
		}
	}
	printf("\n������һ������");
	scanf("%d",&a);
	if(a<0||a>9)
		printf("�������\n");
	else	
	{
		for(i=0;i<ListLength(mylist);i++)
		{
			if(ListGet(mylist,i,&x)==0)
			{
				printf("����!\n");
				return;
			}
			if(a==i)printf("�ҵ�%d����������\n",a);			
		}
		if(a>i||a<0)
			printf("�Ҳ���%d����������\n",a);
	}
}