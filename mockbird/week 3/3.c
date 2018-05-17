#include <stdio.h>
#include <stdlib.h>							
typedef int DataType;
#include "LinList.h"					

void main(void)
{
	SLNode *head;
	int i,d,x;

	ListInitiate(&head);
	printf("       位置： 0   1   2   3   4   5   6   7   8   9\n");				
	printf("存在的十个数：");
	for(i = 0; i < 10; i++)
	{   printf("%d   ",i+1);
		if(ListInsert(head,i,i+1) == 0) 	
		{
			printf("错误! \n");
			return;
		}
	}
    
	printf("\n请输入你要删除的数的位置:");
	scanf("%d",&d);
	printf("删除后的数表为：");
	if(ListDelete(head,d,&x)==0)  
	{
	    printf("错误！\n");
	}  
	for(i=0;i<ListLength(head);i++)   
	{   
		if(ListGet(head,i,&x)==0)
		{
		    printf("错误!\n");
			return;	
		}			
		else printf("%d   ",x);
	}
	printf("\n");
}