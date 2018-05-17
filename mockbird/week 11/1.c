#include<stdio.h>
#include<stdlib.h>

typedef char DataType;
#define MaxSize 100
#define MaxVertices 10
#define MaxEdges 100
#define MaxWeight 0

#include"AdjMGraph.h"
#include"AdjMGraphCreate.h"

void main(void)
{
	AdjMGraph g1;
	DataType a[]={'1','2','3','4','5'};
	RowColWeight rcw[]={{0,1,1},{1,0,1},{1,3,1},{3,1,1},
						{0,3,1},{3,0,1},{0,2,1},{2,0,1},
						{2,4,1},{4,2,1},{0,4,1},{4,0,1}};
	int n=5,e=12;
	int i,j;

	CreatGraph(&g1,a,n,rcw,e);

	printf("结点集合为：\n");
	for(i=0;i<g1.Vertices.size;i++)
		printf("%c   ",g1.Vertices.list[i]);
	printf("\n");

	printf("邻接矩阵为：\n");
	for(i=0;i<g1.Vertices.size;i++)
	{
		for(j=0;j<g1.Vertices.size;j++)
			printf("%5d   ",g1.edge[i][j]);
		printf("\n");
	}
}