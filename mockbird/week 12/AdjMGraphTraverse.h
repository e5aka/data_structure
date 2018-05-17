void DepthFSearch(AdjMGraph G,int v,int visited[],void Visit(DataType item))
{
	int w;
	Visit(G.Vertices.list[v]);
	visited[v]=1;
	w=GetFirstVex(G,v);
	while (w!=-1)
	{
		if(!visited[w])
		 DepthFSearch(G,w,visited,Visit);
		 w=GetNextVex(G,v,w);
	}
}

void DepthFirstSearch(AdjMGraph G,void Visit(DataType item))
{
	int i;
	int *visited=(int *)malloc(sizeof(int)*G.Vertices.size);

	for(i=0;i<G.Vertices.size;i++)
		visited[i]=0;

	for(i=0;i<G.Vertices.size;i++)
		if(!visited[i])
		DepthFSearch(G,i,visited,Visit);
		free(visited);
}

#include "SeqCQueue.h"

void BroadFSearch(AdjMGraph G,int v,int visited[],void Visit(DataType item))
{
	DataType u,w;
	SeqCQueue queue;

	Visit(G.Vertices.list[v]);
	visited[v]=1;

	QueueInitiate(&queue);
	QueueAppend(&queue,v);
	while(QueueNotEmpty(queue))
	{
		QueueDelete(&queue,&u);
		w=GetFirstVex(G,u);
		while(w!=-1)
		{
			if(!visited[w])
			{
				Visit(G.Vertices.list[w]);
				visited[w]=1;
				QueueAppend(&queue,w);
			}
			w=GetNextVex(G,u,w);
		}
	}
}

void BroadFirstSearch(AdjMGraph G,void Visit(DataType item))
{
	int i;
	int *visited=(int *)malloc(sizeof(int)*G.Vertices.size);

	for(i=0;i<G.Vertices.size;i++)
		visited[i]=0;

	for(i=0;i<G.Vertices.size;i++)
		if(!visited[i])BroadFSearch(G,i,visited,Visit);
		free(visited);
}

