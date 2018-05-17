typedef struct Node 
{
	DataType data;						
	struct Node *leftChild;						
	struct Node *rightChild;				
}BiTreeNode;								

void Initiate(BiTreeNode **root)
{
	*root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}

void Destroy(BiTreeNode **root)
{
	if((*root) != NULL && (*root)->leftChild != NULL)
		Destroy(&(*root)->leftChild);

	if((*root) != NULL && (*root)->rightChild != NULL)
		Destroy(&(*root)->rightChild);

	free(*root);
}

BiTreeNode *InsertLeftNode(BiTreeNode *curr, DataType x)

{
	BiTreeNode *s, *t;

	if(curr == NULL) return NULL;
	
	t = curr->leftChild;		
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->leftChild = t;		
	s->rightChild = NULL;

	curr->leftChild = s;			
	return curr->leftChild;		
}

BiTreeNode *InsertRightNode(BiTreeNode *curr, DataType x)
{
	BiTreeNode *s, *t;

	if(curr == NULL) return NULL;
	
	t = curr->rightChild;		
	s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	s->data = x;
	s->rightChild = t;			
	s->leftChild = NULL;

	curr->rightChild = s;			
	return curr->rightChild;			
}

BiTreeNode *DeleteLeftTree(BiTreeNode *curr)
{
	if(curr == NULL || curr->leftChild == NULL) return NULL;

	Destroy(&curr->leftChild);
	curr->leftChild = NULL;
	return curr;
}

BiTreeNode *DeleteRightTree(BiTreeNode *curr)
{
	if(curr == NULL || curr->rightChild == NULL) return NULL;

	Destroy(&curr->rightChild);
	curr->rightChild = NULL;
	return curr;
}
void PreOrder(BiTreeNode *t, void visit(DataType item))
{
	if(t != NULL)
	{
		visit(t->data);
		PreOrder(t->leftChild, visit);
		PreOrder(t->rightChild, visit);
	}
}

void visit(DataType item)
{
	printf("%c ", item);
}

