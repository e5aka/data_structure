typedef struct Node 
{ 
	int dest; 
	int dis;  
	struct Node *next; 
}Edge; 
 
typedef struct 
{ 
	DataType data; 
	int sorce; 
	Edge *adj; 
}AdjLheight; 
 
typedef struct 
{ 
	AdjLheight a[MaxVertices]; 
	int numOfVerts; 
	int numOfEdges; 
}AdjLGraph; 
 
typedef struct 
{ 
	int row; 
	int col; 
	int weight; 
}RowColWeight; 
 
void AdjInitiate(AdjLGraph *G) 
{ 
	int i; 
	G->numOfVerts=0; 
	G->numOfEdges=0; 
	for(i=0;ia[i].sorce=i; 
		G->a[i].adj=NULL; 
	} 
} 
 
void AdjDestroy(AdjLGraph *G) 
{ 
	int i; 
	Edge *p, *q; 
	for(i=0;inumOfVerts;i++) 
	{ 
		p=G->a[i].adj; 
		while(p!=NULL) 
		{ 
			q=p->next; 
			free(p); 
			p=q; 
		} 
	} 
} 
 
void InsertVertex(AdjLGraph *G, int i, DataType vertex) 
{ 
	if(i>=0 && ia[i].data=vertex; 
		G->numOfVerts++; 
	} 
	else printf("节点越界\n"); 
}  
 
void InsertEdge(AdjLGraph *G, int v1, int v2, int d) 
{ 
	Edge *p; 
	if(v1<0 || v1>G->numOfVerts ||v2<0 ||v2>G->numOfVerts) 
	{ 
		printf("参数v1或v2越界出错\n"); 
		exit(0); 
	} 
	p=(Edge *)malloc(sizeof(Edge)); 
	p->dest=v2; 
	p->dis=d;  
	 
	p->next=G->a[v1].adj; 
	G->a[v1].adj=p; 
	G->numOfEdges++; 
} 
 
void Delete(AdjLGraph *G, int v1, int v2) 
{ 
	Edge *curr, *pre; 
	if(v1<0 || v1>=G->numOfVerts || v2<0 || v2>G->numOfVerts) 
	{ 
		printf("参数v1或v2越界出错\n"); 
		exit(0); 
	} 
	pre=NULL; 
	curr=G->a[v1].adj; 
	while(curr!=NULL && curr->dest!=v2) 
	{ 
		pre=curr; 
		curr=curr->next; 
	} 
	 
	if(curr!=NULL && curr->dest==v2 && pre==NULL) 
	{ 
		G->a[v1].adj=curr->next; 
		free(curr); 
		G->numOfEdges--; 
	} 
	else if(curr!=NULL && curr->dest==v2 && pre!=NULL) 
	{ 
		pre->next=curr->next; 
		free(curr); 
		G->numOfEdges--; 
	} 
	else printf("边不存在!\n"); 
} 
 
int GetFirstVex(AdjLGraph G, int v) 
{ 
	Edge *p; 
	if(v<0 || v>G.numOfVerts) 
	{ 
		printf("参数v1或v2越界出错\n"); 
		exit(0); 
	} 
	p=G.a[v].adj; 
	if(p!=NULL)return p->dest; 
	else return -1; 
} 
 
int GetNextVex(AdjLGraph G, int v1, int v2) 
{ 
	Edge *p; 
	if(v1<0 || v1 >= G.numOfVerts || v2<0 || v2 >= G.numOfVerts) 
	{ 
		printf("参数v1或v2越界出错\n"); 
		exit(0); 
	} 
	 
	p=G.a[v1].adj; 
	if(p==NULL)return -1; 
	while(p!=NULL) 
	{ 
		if(p->dest!=v2)p=p->next; 
		else break; 
	} 
	p=p->next; 
	if(p!=NULL)return p->dest; 
	else return -1; 
} 
 
int GetDistance(AdjLGraph G, int v1, int v2) 
{ 
	Edge *p; 
	if(v1==v2)return 0; 
	if(v1<0 || v1>=G.numOfVerts || v2<0 || v2>G.numOfVerts) 
	{ 
		printf("参数v1或v2越界出错\n"); 
		exit(0); 
	} 
	 
	p=G.a[v1].adj; 
	if(p==NULL)return -1; 
	while(p!=NULL) 
	{ 
		if(p->dest!=v2)p=p->next; 
		else break; 
	} 
	 
	if(p!=NULL)return p->dis; 
	else return -1; 
} 
 
void CreatGraph( AdjLGraph *G, DataType V[], int n, RowColWeight d[], int e) 
{ 
	int i, k; 
	AdjInitiate(G); 
	for(i=0;i
