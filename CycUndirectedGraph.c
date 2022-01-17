// A union-find algorithm to detect cycle in a graph with one-way directions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

// a structure to represent an edge in graph
struct Edge
{
    int src, dest;
};

// a structure to represent a graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges
    struct Edge edge[MAX];
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;

    graph->edge[E];

    return graph;
}

int find(int parent[], int i)
{
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
    parent[x] = y;
}

int isCycle( struct Graph* graph )
{
    int parent[(graph->V)+1];
    for(int i=0;i<=graph->V;i++)
    {
       parent[i] = i;
    }
    for(int i = 0; i < graph->E; ++i)
    {
        int x = find(parent, graph->edge[i].src); printf("\nParent of %d is = %d",graph->edge[i].src,x);
        int y = find(parent, graph->edge[i].dest); printf("\nParent of %d is = %d",graph->edge[i].dest,y);

        if (x == y)
            return 1;

        Union(parent, x, y);
    }
    return 0;
}


int main()
{
    int V,E,s,d;
    printf("\nDetecting Cycle in an Undirected Graph! \n");
    printf("\nEnter the number of vertices of graph : "); scanf("%d",&V);
    printf("\nEnter the number of edges of graph : "); scanf("%d",&E);
    struct Graph* graph = createGraph(V,E);
      
      for(int j=0;j<E;j++)
      {
          printf("\nEnter the source vertice for the edge[%d] = ",j+1); scanf("%d",&s);
          printf("\nEnter the destination vertice for the edge[%d] = ",j+1); scanf("%d",&d);
          graph->edge[j].src = s;
          graph->edge[j].dest = d;
          /*printf("\n %d edge :  graph src = %d , graph dest = %d",j,graph->edge[j].src,graph->edge[j].dest);*/
      }
    if (isCycle(graph))
        printf( "\n\ngraph contains cycle" );
    else
        printf( "\n\ngraph doesn't contain cycle" );

    return 0;
}