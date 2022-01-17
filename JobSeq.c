/*Assumption : Deadline for a job cannot be zero or a negetive number */
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct job
{
  int id,deadline,profit;
};
struct job array[MAX];

int parent[MAX];

void swap(int *x,int *y)
{
    int t;
    t   = *x;
    *x   = *y;
    *y   =  t;
}

void initialise(int n)
{
  int i;
  for(i=0;i<=n;i++)
  {
    parent[i]=i;
  }
}

int find(int s)
{
  if(s == parent[s])
    return s;
  else
    return parent[s]=find(parent[s]);
}

void merge(int u,int v)
{
  parent[v]=u;
}

int findmaxDeadline(int n)
{
  int ans = 0;
  int i;
  for(i=0;i<n;i++)
  {
    if(array[i].deadline > ans)
      ans = array[i].deadline;
  }
  return ans;
}

void printJobScheduling(int n)
{ 
  
  int i=0,j=0;
 
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(array[j].profit < array[j+1].profit)
      {
        swap(&array[j].profit,&array[j+1].profit);
        swap(&array[j].deadline,&array[j+1].deadline);
        swap(&array[j].id,&array[j+1].id);
      }
    }
  }

  for(int k=0;k<n;k++)
  {
    printf("\n Job_id = %d, Job Profit = %d, Job deadline = %d ",array[k].id,array[k].profit,array[k].deadline);
  }

  int maxDeadline=findmaxDeadline(n);
  initialise(maxDeadline);
  printf("\n\nThe Following is the most profitable job sequence : ");
  int sum=0;
  for(i=0;i<n;i++)
  {
    int availableslot = find(array[i].deadline); /*printf("\navailable slot for job %d = %d",i+1,availableslot);*/
    if(availableslot > 0)
    {
      merge((find(availableslot-1)),(availableslot));
      sum = sum + array[i].profit;
      printf("%d ",array[i].id);
    }
  }
  printf("\n\nThe profit obtained is = %d \n",sum);
}


int main()
{
  printf("\nJob Scheduling!\n");
  int i,n;
  
  printf("\nEnter the value of n : ");
  scanf("%d",&n);
  printf("\n");
  for(i=0;i<n;i++)
  { getchar();
    printf("Enter the unique character for the Job %d : ",i+1);
    scanf("%d",&array[i].id);
    printf("\n");
    printf("Enter the deadline for the Job %d : ",i+1);
    scanf("%d",&array[i].deadline);
    printf("\n");
    printf("Enter the profit for the Job %d : ",i+1);
    scanf("%d",&array[i].profit);
    printf("\n");
  }
  
  printf("\nThe given sorted Job List is \n");
  printJobScheduling(n);
  return 0;

}