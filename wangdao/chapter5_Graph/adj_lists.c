#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef int InfoType;

#include <stdio.h>
#include <stdbool.h>

typedef struct ArcNode{     //Adjacency Lists Representation
    int adjvex;
    struct ArcNode *next;
    //InfoType info;
}ArcNode;
typedef struct VNode{
    VertexType data;
    ArcNode *first;
}VNode, AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;

int main(){

    puts("Devil may cry");
    return 0;
}
