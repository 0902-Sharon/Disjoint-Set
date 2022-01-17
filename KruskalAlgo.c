/* Aim: to find out all the edges of a given graph which belong to a minimum spanning tree...using Kruskal's Algorithm*/
/*
Algorithm :-
1. Sort edges by ascending order of edge weights
2. Traverse the sorted edges and look at the two nodes the edge belongs to , if the nodes are already unified we don't include this edge, otherwise we include it and unify the nodes
3. The algorithm terminates when every edge has been processed or all the vertices have been unified
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 40

struct Edge{
  int u,v,w;
};
typedef struct Edge edge;

struct edge_list
{
  edge data[MAX];
  int n;
};
typedef struct edge_list E;
E elist,slist;

int Graph[MAX][MAX];
int num;


int find(int b[],int n)
{
  if(b[n]==-1)
  return n;
  else
  return(b[n]);
}

void union_sets(int b[],int c1,int c2)
{
  int i;
  for(i=0;i<num;i++)
  {
    if(b[i]==c2)
      b[i]=c1;
  }
}

void sort()
{
  int i,j;
  edge temp;
  for(i=1;i<elist.n;i++)
  {
    for(j=0;j<elist.n-1;j++)
    {
      if(elist.data[j].w>elist.data[j+1].w)
      {
        temp=elist.data[j];
        elist.data[j]=elist.data[j+1];
        elist.data[j+1]=temp;
      }
    }
  }
}
void KruskalAlgo()
{
  int b[MAX],i,j,c1,c2;
  elist.n=0;
  for(i=1;i<num;i++)
  {
    for(j=0;j<i;j++)
    {
      if(Graph[i][j]!=0)
      {
        elist.data[elist.n].u=i;
        elist.data[elist.n].v=j;
        elist.data[elist.n].w=Graph[i][j];
        elist.n++;

      }
    }
  }
   sort();
  for(i=0;i<num;i++)
  b[i]=i;
  slist.n=0;
  for(i=0;i<elist.n;i++)
  {
    c1=find(b,elist.data[i].u);
    c2=find(b,elist.data[i].v);
    if(c1!=c2)
    {
      slist.data[slist.n]=elist.data[i];
      slist.n=slist.n+1;
      union_sets(b,c1,c2);
    }
  }
}
void print()
{
  int i,cost=0;
  for(i=0;i<slist.n;i++)
  {
    printf("\n%d-%d:%d",slist.data[i].u,slist.data[i].v,slist.data[i].w);
    cost=cost+slist.data[i].w;
  }
  printf("\nThe cost for the spanning tree is = %d\n",cost);
}
int main()
{
  int i,j;
  printf("\nWelcome to Kruskals's Minimum spanning tree\n");
  printf("Enter the value of n : ");
  scanf("%d",&num);
  printf("\n");
  printf("Enter the elements of the Graph:\n\n");
  for(i=0;i<num;i++)
  {
    for(j=0;j<num;j++)
    {
      printf("Enter the element graph[%d][%d]: ",i,j);
      scanf("%d",&Graph[i][j]);
      printf("\n");
    }
  }
  
 
KruskalAlgo();
print();
}