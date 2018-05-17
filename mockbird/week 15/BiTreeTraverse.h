
void PrintBiTree(BiTreeNode *bt, int n)
{  
	int i;
	if(bt==NULL) return;
	PrintBiTree(bt->rightChild,n+1);
	for(i=0;i<n;i++)
	{
		printf("   ");
	}
	if(n>=0)
	{
		printf("---");
		printf("%c\n",bt->data);
	}
	PrintBiTree(bt->leftChild,n+1);
}