#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int DataType;
#define MaxSize 100
#define MaxVertices 10
#define MaxEdges 100
#define MaxWeight 10000
#define MaxQueueSize 100

#include"AdjMGraph.h"
#include"AdjMGraphCreate.h"
#include"AdjMGraphTraverse.h"

void Visit(DataType item)
{
	printf("%c  ",item);
}

void main(void)
{
	AdjMGraph g1;
	DataType a[]={'A','B','C','D','E','F'};
	RowColWeight rcw[]={{0,1,1},{2,1,1},{3,2,1},{1,3,1},{3,4,1},
						{4,0,1},{1,5,1},{3,5,1},{5,0,1},{5,4,1},{2,5,1}};
	int n=6,e=11;
	int i,j;

	CreatGraph(&g1,a,n,rcw,e);

		printf("邻接矩阵为：\n");
	for(i=0;i<g1.Vertices.size;i++)
	{
		for(j=0;j<g1.Vertices.size;j++)
			printf("%5d   ",g1.edge[i][j]);
		printf("\n");
	}

	printf("深度优先搜索序列为：");
	DepthFirstSearch(g1,Visit);

	printf("\n");

	printf("广度优先搜索序列为：");
	BroadFirstSearch(g1,Visit);
	
	printf("\n");
}

