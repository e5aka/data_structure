#include"SeqList.h"                                    
 
typedef struct 
{ 
	SeqList Vertices;                                  
	int edge[MaxVertices][MaxVertices];                 
	int numOfEdges;                                      
}AdjMGraph;                                           
  
void Initiate(AdjMGraph *G,int n) 
{ 
	int i,j; 
 
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(i==j) G->edge[i][j]=0;
			else G->edge[i][j]=MaxWeight;
		}
 
		G->numOfEdges=0;                              
		ListInitiate(&G->Vertices);                     
} 
 

void InsertVertex(AdjMGraph * G,DataType vertex) 
{ 
	ListInsert(&G->Vertices,G->Vertices.size,vertex);  
} 


void InsertEdge(AdjMGraph * G,int v1,int v2,int weight) 
{ 
	if(v1<0||v1>G->Vertices.size||v2<0||v2>G->Vertices.size) 
	{ 
		printf("参数v1或v2越界出错 !\n"); 
		exit(1); 
	} 
 
	G->edge[v1][v2]=weight;                           
	G->numOfEdges++;                                   
} 


void DeleteEdge(AdjMGraph *G, int v1, int v2) 
{ 
	if(v1<0 || v1>G->Vertices.size || v2<0 || v2>G->Vertices.size || v1==v2) 
	{ 
		printf("参数v1和v2越界出错！\n"); 
		exit(1); 
	} 
	if(G->edge[v1][v2]==MaxWeight || v1==v2) 
	{ 
		printf("该边不存在！\n"); 
		exit(0); 
	} 
	G->edge[v1][v2]=MaxWeight; 
	G->numOfEdges--; 
} 
 
void DeleteVerten(AdjMGraph *G, int v) 
{ 
	int n=ListLength(G->Vertices), i, j; 
	DataType x; 
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		if((i==v||j==v) && G->edge[i][j]>0 && G->edge[i][j]<MaxWeight)
			G->numOfEdges--;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			G->edge[i][j]=G->edge[i+1][j];

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			G->edge[i][j]=G->edge[i][j+1];
	 
	ListDelete(&G->Vertices,v,&x); 
} 
 
int GetFirstVex(AdjMGraph G, int v) 
{ 
	int col; 
	if(v<0 || v>G.Vertices.size) 
	{ 
		printf("参数v1越界出错！\n"); 
		exit(1); 
	} 
	 
	for(col=0;col<G.Vertices.size;col++)
	if(G.edge[v][col]>0&&G.edge[v][col]<MaxWeight) return col;
	return -1;
}

int GetNextVex(AdjMGraph G, int v1, int v2)
{
	int col;
	if(v1<0||v1>G.Vertices.size||v2<0||v2>G.Vertices.size)
	{
	printf("参数v1或v2越界出错！\n");
	exit(1);
	}

	for(col=v2+1;col<G.Vertices.size;col++)
	if(G.edge[v1][col]>0&&G.edge[v1][col]<MaxWeight) return col;
	return -1;
}