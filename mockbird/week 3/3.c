#include <stdio.h>
#include <stdlib.h>							
typedef int DataType;
#include "LinList.h"					

void main(void)
{
	SLNode *head;
	int i,d,x;

	ListInitiate(&head);
	printf("       λ�ã� 0   1   2   3   4   5   6   7   8   9\n");				
	printf("���ڵ�ʮ������");
	for(i = 0; i < 10; i++)
	{   printf("%d   ",i+1);
		if(ListInsert(head,i,i+1) == 0) 	
		{
			printf("����! \n");
			return;
		}
	}
    
	printf("\n��������Ҫɾ��������λ��:");
	scanf("%d",&d);
	printf("ɾ���������Ϊ��");
	if(ListDelete(head,d,&x)==0)  
	{
	    printf("����\n");
	}  
	for(i=0;i<ListLength(head);i++)   
	{   
		if(ListGet(head,i,&x)==0)
		{
		    printf("����!\n");
			return;	
		}			
		else printf("%d   ",x);
	}
	printf("\n");
}