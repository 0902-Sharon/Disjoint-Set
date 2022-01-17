#include <stdio.h>
#include <stdlib.h>
struct disjoint
{
  int parent;
  int size;
  int rank;

};
struct disjoint DS[20];

void initialise(int n)
{
  for(int i=0;i<n;i++)
  {
    DS[i].parent=i;
    DS[i].size=1;
    DS[i].rank=1;
  }
}
int find_with_path_compression(int i)
{
  if (DS[i].parent != i) {
  DS[i].parent=find_with_path_compression( DS[i].parent);

}
return  DS[i].parent;
}
int find(int i)
{
  if(i== DS[i].parent)
  return i;
  else
  return (find( DS[i].parent));
}
void union_of_sets(int a,int b)
{
  int x=find(a);
  int y=find(b);
  if(x==y)
  return;
  else
  DS[x].parent=y;
  DS[y].rank+=1;
  DS[y].size+=1;
}
void union_by_rank(int a,int b)
{
  int x=find(a);
  int y=find(b);
  if(x==y)
  return;
  if(DS[x].rank<DS[y].rank)
  {DS[x].parent=y;
  DS[y].size=DS[y].size+1;
  }
  else if (DS[x].rank >DS[y]. rank) {
  DS[y].parent = x;
  DS[x].size=DS[x].size+1;
 }
  else {
   DS[y].parent = x;
  DS[x].rank = DS[x].rank + 1;
  DS[x].size=DS[x].size+1;
  }
}
void union_by_size(int a,int b)
{
  int x=find(a);
  int y=find(b);
  if(DS[x].size<DS[y].size)
  {
    DS[x].parent=DS[y].parent;
    DS[x].size+=DS[y].size;
  }
  else
  {
    DS[y].parent=DS[x].parent;
    DS[y].size+=DS[x].size;
  }
}
void display(int n)
{int i=0;
 printf("The parent array:");
 for(i=0;i<n;i++)
 {
   printf("%d ",DS[i].parent);
 }
 printf("\n");
  printf("The size array:");
 for(i=0;i<n;i++)
 {
   printf("%d ",DS[i].size);
 }
 printf("\n");
  printf("The rank array:");
 for(i=0;i<n;i++)
 {
   printf("%d ",DS[i].rank);
 }
 printf("\n");
}
int main()
{
  printf("Disjoint Sets-With Arrays!!\n");
  int choice;
  int n,m,l;
  int a,b;
  printf("Enter the number of elements:");
  scanf("%d",&n);
  printf("\n");
  initialise(n);
  start:
  printf("Enter 1 for union of sets\nEnter 2 to find representative of set\nEnter 3 to find union by size\nEnter 4 to find union by rank\nEnter 5 to find representative by path compression\nEnter 6 to display\n");
  printf("Enter your choice:\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:printf("Enter the 2 elements:");
    scanf("%d%d",&a,&b);
    printf("\n");
    union_of_sets(a,b);
    break;
    case 2:
    printf("Enter the element to find representative:");
    scanf("%d",&a);
    m=find(a);
    printf("\nThe representative is %d",m);
    printf("\n");
    break;
    case 3:
    printf("Enter the 2 elements:");
    scanf("%d%d",&a,&b);
    union_by_size(a,b);
    printf("\n");
    break;
    case 4:printf("Enter the 2 elements:");
    scanf("%d%d",&a,&b);
    union_by_rank(a,b);
    printf("\n"); 
    break;
    case 5: printf("Enter the element to find representative:");
    scanf("%d",&a);
    m=find_with_path_compression(a);
    printf("\nThe representative is %d",m);
    printf("\n");
    break;
    case 6:printf("Displaying:\n");
    display(n);
    printf("\n");
    break;
    deafult:break;
  }
  printf("Do you want to continue?Enter 1 for yes and 0 for no.\n");
  scanf("%d",&l);
  if(l==1)
  goto start;
  return 0;
}