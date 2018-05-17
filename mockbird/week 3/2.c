#include <stdio.h>                                   
#include <stdlib.h>                                           
#include <malloc.h>                                               
typedef int DataType;
#include "LinList.h"        
void main(void)
{
       SLNode *head;
       int i,k,x;
       ListInitiate(&head);                            
       printf("请输入十个数:");
       for(i = 0; i < 10; i++)
       {   scanf("%d", &x);
              if(ListInsert(head, i, x) == 0)      
              {
                    printf("错误! \n");
                     return;
              }
       }
       printf("请输入你要找的数:");
       scanf("%d",&x);
       k=ListFind(head,x);  
       if(k==-1)
              printf("数据没有找到。\n");
       else
              printf("找到数%d存在。 \n",k);
  
}
