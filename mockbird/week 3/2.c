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
       printf("������ʮ����:");
       for(i = 0; i < 10; i++)
       {   scanf("%d", &x);
              if(ListInsert(head, i, x) == 0)      
              {
                    printf("����! \n");
                     return;
              }
       }
       printf("��������Ҫ�ҵ���:");
       scanf("%d",&x);
       k=ListFind(head,x);  
       if(k==-1)
              printf("����û���ҵ���\n");
       else
              printf("�ҵ���%d���ڡ� \n",k);
  
}
