#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int DataType;
#include"LinList.h"

int Myf(SLNode *heada, SLNode *headb, int i, int len, int j)
{	
	int x,k,n;
	for(k=0;k<len;k++)
		if(ListDelete(heada,i-1,&x)==0)
		{
		printf("É¾³ýÔªËØ·¢Éú´íÎó!");
		return 0;
		}
	k=0;
	for(n=j-1;n<j-1+ListLength(heada);n++)
	{	
		ListGet(heada,k,&x);
		if(ListInsert(headb,n,x)==0)
		{
			printf("²åÈëÔªËØ·¢Éú´íÎó!");
			return 0;
		}
		k++;
	}
	return 1;	
}


void main(void)
{	
	int i,len,j,x;
	SLNode *heada,*headb;
	ListInitiate(&heada);
	ListInitiate(&headb);

	printf("ÇëÊäÈë×Ö·û´®A£º");
	for(i=0;i<10;i++)
	{	
		scanf("%d",&x);
		if(ListInsert(heada,i,x)==0)
		{
			printf("´íÎó!");
		}
	}
	
	printf("ÇëÊäÈë×Ö·û´®B£º");
	for(i=0;i<10;i++)
	{	
		scanf("%d",&x);
		if(ListInsert(headb,i,x)==0)
		{
			printf("´íÎó!");
		}
	}
	
	printf("ÇëÊäÈëi,len,jµÄÖµ:");
	scanf("%d%d%d",&i,&len,&j);

	if(Myf(heada,headb,i,len,j)==0)
	{
		printf("´íÎó!");
	}
	
	printf("×Ö·û´®AÎª£º");
	for(i=0;i<ListLength(heada);i++)
	{
		if(ListGet(heada,i,&x)==0)
		{
			printf("´íÎó!\n");

		}
		else 
			printf("%d ",x);
	}

	printf("\n");

	printf("×Ö·û´®BÎª£º");
	for(i=0;i<ListLength(headb);i++)
	{
		if(ListGet(headb,i,&x)==0)
		{
			printf("´íÎó!\n");

		}
		else 
			printf("%d ",x);
	}

	printf("\n");
 	Destroy(&heada);
 	Destroy(&headb);
}
