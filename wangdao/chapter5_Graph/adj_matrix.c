#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;

#include <stdio.h>
#include <stdbool.h>

typedef struct{     //Adjacency Matrix Representation
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
}MGraph, *Graph;

bool adjacent(Graph G, VertexType x, VertexType y);
void neighbors(Graph G, VertexType x);
bool insVertex(Graph G, VertexType x);
bool delVertex(Graph G, VertexType x);
bool addEdge(Graph G, VertexType x, VertexType y);
bool removeEdge(Graph G, VertexType x, VertexType y);
int firstNeighbor(Graph G, VertexType x);
int nextNeighbor(Graph G, VertexType x, VertexType y);
int get_edge_value(Graph G, VertexType x, VertexType y);
int set_edge_value(Graph G, VertexType x, VertexType y, int v);
void convert(ALGraph &G, int arcs[M][N]){
    for(i=0;i<n;i++){
        p = (G->v[i]).firstarc;
        while(p){
            arcs[i][p->data] = 1;
            p = p->nextarc;
        }
    }
}


int main(int argc ,char *argv[]){

    puts("Devil may cry");
    return 0;
}
