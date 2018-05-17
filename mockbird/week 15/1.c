#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"BiTreeNode.h"
#include"BITree.h"
#include"BiTreeTraverse.h"

void main(void)
{
	DataType test[]={'Dec','Feb','Nov','Oct','June','Sept','Aug','Apr','May','July','Jan','Mar'},
			 x={'Sept'};
	int n=12,i,s;
	BiTreeNode *root=NULL;
	
	for(i=0;i<n;i++)
	{
		Insert(&root,test[i]);
	}
	InTraverse(root);
	
	PrintBiTree(root,0);
	printf("中序遍历：");
	InOrder(root->leftChild, visit);	

	s=Search(root,x);

	if(s==1)
		printf("\n数据元素%s存在！",x.key);
	else
		printf("\n数据元素不存在！");
	
	printf("\n");
}