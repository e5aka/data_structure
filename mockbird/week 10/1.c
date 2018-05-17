#include <stdio.h>						
#include <stdlib.h>
#define MaxStackSize 100
					
typedef char ElemType;
#include "BiTree.h"

typedef  BiTreeNode *DataType ;
#include "SeqStack.h"

void PreOrderByStack(BiTreeNode *root)
{	
	SeqStack myStack;
	int x;
	StackInitiate(&myStack);
	StackPush(&myStack,root);
	while(StackNotEmpty(myStack))
	{
	StackPop(&myStack,&x);
	visit(x->root);
	if()
	}

}

void main(void)
{
	BiTreeNode *root, *p, *pp;
	int i,x;
	Initiate(&root);
	p = InsertLeftNode(root, 'A');
	p = InsertLeftNode(p, 'B');
	p = InsertLeftNode(p, 'D');
	p = InsertRightNode(p, 'G');
	p = InsertRightNode(root->leftChild, 'C');
	pp = p;
	InsertLeftNode(p, 'E');
	InsertRightNode(pp, 'F');
	PreOrderByStack(root->leftChild);
	Destroy(&root);
}
