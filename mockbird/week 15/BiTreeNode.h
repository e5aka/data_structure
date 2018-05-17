typedef int KeyType;

typedef struct
{
	KeyType key;
}DataType;

typedef struct node
{
	DataType data;
	struct node * leftChild;
	struct node * rightChild;
}BiTreeNode;

int Search(BiTreeNode * root, DataType item)
{
	BiTreeNode * p;
	
	if(root!=NULL)
	{
		p=root;
		while(p!=NULL)
		{
			if(p->data.key==item.key) return 1;
			if(item.key>p->data.key) p=p->rightChild;
			else p=p->leftChild;
		}
	}
	return 0;
}

int Insert(BiTreeNode **root,DataType item)
{
	BiTreeNode *current,*parent=NULL,*p;
	current=*root;
	while(current!=NULL)
	{
		if(current->data.key==item.key) return 0;
		parent=current;
		if(current->data.key<item.key) current=current->rightChild;
		else current=current->leftChild;
	}
	p=(BiTreeNode *)malloc(sizeof(BiTreeNode));
	if(p==NULL)
	{
		printf("¿Õ¼ä²»¹»");
		exit(1);
	}

	p->data=item;
	p->leftChild=NULL;
	p->rightChild=NULL;
	if(parent==NULL) *root=p;
	else if(item.key<parent->data.key)
		parent->leftChild=p;
	else
		parent->rightChild=p;
	return 1;
}

int InTraverse(BiTreeNode * root)
{
	if(root==NULL) return;

	if(root->leftChild!=NULL)
		InTraverse(root->leftChild);

	printf("%d   ",root->data.key);

	if(root->rightChild!=NULL)
		InTraverse(root->rightChild);
}