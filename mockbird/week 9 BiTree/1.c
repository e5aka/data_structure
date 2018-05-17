#include <stdlib.h>
#include <stdio.h>
typedef char DataType;
#include "BiTree.h"
#include"BiTreeTraverse.h"
void main(void)
{
	BiTreeNode * root, *p ;

	Initiate(&root);
	p=InsertLeftNode(root,'A');
	InsertLeftNode(p,'B');
	p=InsertRightNode(root->leftChild,'C');
	InsertRightNode(p,'E');	
	p=InsertLeftNode(p,'D');
	InsertLeftNode(p,'F');
	InsertRightNode(p,'G');
	

	PrintBiTree(root,0);
	printf("Ç°Ðò±éÀú£º");
	PreOrder(root->leftChild, visit);	
	Destroy(&root);	
	printf("\n");
}

