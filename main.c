/*  Disjoint Set Implementation Using Trees!  */
/*Assumption : Enter only distinct values of elements */
#include<stdio.h>
#include<stdlib.h>

#define MAX 20

struct node
{
  int data;
  int size;
  int rank;
  struct node *parent;
};
typedef struct node *NODE;

NODE Global[MAX]; //array to store all the parents of all the sets
int k = 0; 

NODE create_node(int x)
{
    NODE root;
    root = (NODE)malloc(sizeof(struct node));
    root->data = x;
    root->rank = 0;
    root->size = 0;
    root->parent = root;
    return root;
}

NODE find_parent(int x)
{
    NODE temp;

    for(int i=0;i<k;i++)
    {
      temp = Global[i];
      if(temp->data == x)
      {
         return temp->parent;
      }

    } 
    return NULL;  
}

int find_(int x)
{
    NODE parent_x = find_parent(x);
    if(parent_x->data == x)
      return x;
    else
      return (find_(parent_x->data));
}

void union_(int x,int y)
{
   NODE a,b;
   a = find_parent(x);
   b = find_parent(y);
   if(a != NULL && b != NULL)
   {
      if (a != b)
      {
        b->parent = a; //setting parent of b as a
        if(a->rank == 0 || b->rank == 0)
        {
          a->rank = a->rank + 1;
          a->size = a->size + 1;
        }
        else
        {
          a->rank = a->rank + 1;
          a->size = a->size + b->size;

        }
        printf("\n %d is now parent of element %d ",a->data,b->data);
      }
      else
        return;
      
   }
   else
   {
     if( a == NULL)
     {
       printf("\n Error: %d is not a part of any set ",x); return;
     }
     else
     { 
      printf("\n Error: %d is not a part of any set ",y); return;
     }
   }
  
}

void union_by_rank(int x,int y)
{
   NODE a,b;
   a = find_parent(x);
   b = find_parent(y);
   if(a != NULL && b != NULL)
   {
      if (a != b)
      {
        if(a->rank >= b->rank)
        { 
          b->parent = a; //setting parent of b as a
          if(a->rank == 0 || b->rank == 0)
          {
            a->rank = a->rank + 1;
            a->size = a->size + 1;
          }
          else
          {
            a->rank = a->rank + 1;
            a->size = a->size + b->size;

          }
          printf("\n %d is now parent of set %d ",a->data,b->data);
          printf("\n Rank of %d is = %d",a->data,a->rank);
        }
        else
        {
          a->parent = b; //setting parent of a as b
          if(a->rank == 0 || b->rank == 0)
          {
            b->rank = b->rank + 1;
            b->size = b->size + 1;
          }
          else
          { 
            b->rank = b->rank + 1;
            b->size = b->size + a->size;
          }
          printf("\n %d is now parent of set %d ",b->data,a->data);
          printf("\n Rank of %d is = %d",b->data,b->rank);
        }
      }
      else
        return;
      
   }
   else
   {
     if( a == NULL)
     {
       printf("\n Error: %d is not a part of any set ",x); return;
     }
     else
     { 
      printf("\n Error: %d is not a part of any set ",y); return;
     }
   }
}

void union_by_size(int x,int y)
{
  NODE a,b;
   a = find_parent(x);
   b = find_parent(y);
   if(a != NULL && b != NULL)
   {
      if (a != b)
      {
        if(a->size >= b->size)
        { 
          b->parent = a; //setting parent of b as a
          if(a->size == 0 || b->size == 0)
          {
            a->rank = a->rank + 1;
            a->size = a->size + 1;
          }
          else
          {
            a->rank = a->rank + 1;
            a->size = a->size + b->size;

          }
          printf("\n %d is now parent of set %d ",a->data,b->data);
          printf("\n Size of %d is = %d",a->data,a->size);
        }
        else
        {
          a->parent = b; //setting parent of a as b
          if(a->size == 0 || b->size == 0)
          {
            b->rank = b->rank + 1;
            b->size = b->size + 1;
          }
          else
          { 
            b->rank = b->rank + 1;
            b->size = b->size + a->size;
          }
          printf("\n %d is now parent of set %d ",b->data,a->data);
          printf("\n Rank of %d is = %d",b->data,b->size);
        }
      }
      else
        return;
      
   }
   else
   {
     if( a == NULL)
     {
       printf("\n Error: %d is not a part of any set ",x); return;
     }
     else
     { 
      printf("\n Error: %d is not a part of any set ",y); return;
     }
   }
}

void union_by_linking(int x,int y)
{
  NODE a,b;
   a = find_parent(x);
   b = find_parent(y);
   if(a != NULL && b != NULL)
   {
      if (a != b)
      {
        x = rand()%2;
        if(x>0)
        { 
          b->parent = a; //setting parent of b as a
          if(a->size == 0 || b->size == 0)
          {
            a->rank = a->rank + 1;
            a->size = a->size + 1;
          }
          else
          {
            a->rank = a->rank + 1;
            a->size = a->size + b->size;

          }
          printf("\n %d is now parent of set %d ",a->data,b->data);
        }
        else
        {
          a->parent = b; //setting parent of a as b
          if(a->size == 0 || b->size == 0)
          {
            b->rank = b->rank + 1;
            b->size = b->size + 1;
          }
          else
          { 
            b->rank = b->rank + 1;
            b->size = b->size + a->size;
          }
          printf("\n %d is now parent of set %d ",b->data,a->data);
        }
      }
      else
        return;
      
   }
   else
   {
     if( a == NULL)
     {
       printf("\n Error: %d is not a part of any set ",x); return;
     }
     else
     { 
      printf("\n Error: %d is not a part of any set ",y);
     }
   }
}

NODE find_node(int x)
{
   NODE temp;

    for(int i=0;i<k;i++)
    {
      temp = Global[i];
      if(temp->data == x)
      {
         return temp;
      }

    } 
    return NULL;
}

NODE path_compression(int x)
{
    NODE A;
    A = find_node(x);
    if(A->parent == A) 
    {
      return A;
    }
    else
    {
        NODE Result = path_compression((A->parent)->data);
        A->parent = Result;
        printf("\n Parent of %d element is = %d ",A->data,((A->parent)->data));
        return Result;
    }
}

int main()
{
  int n,index = -1,ch = -1;
  int globalSet[n];
  printf("\nEnter the number of elements in the Global Set : "); scanf("%d",&n);
  printf("\nEnter %d elements = ",n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&globalSet[i]);
    Global[++index] = create_node(globalSet[i]);
    k++;
  }

  printf("\nChoose operaton to perform : \n1. Union \n2. Find parent of set \n3. Union by Linking, Rank, Size \n4. Path Compression \n5. Exit");
  while(1)
  {
    printf("\nEnter choice = ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: int a1,b1;
              printf("\nElementary Union, Enter two elements to make union : ");
              scanf("%d%d",&a1,&b1);
              union_(a1,b1);
              break;
      case 2: int ele;
              int p;
              printf("\nEnter element to find Parent of it's set : "); scanf("%d",&ele);
              p = find_(ele);
              printf("\n The parent of the set to which %d element belongs = %d ",ele,p);
              break;
      case 3: int m,a2,b2;
              printf("\n Union operartions : \n1. Union by Rank \n2. Union by Size \n3. Union by Linking  \nEnter choice = "); scanf("%d",&m);
              printf("\nEnter the two elements to union : "); 
              scanf("%d%d",&a2,&b2);
              if(m == 1)
              {
                union_by_rank(a2,b2);
                /*Union by rank always attaches the shorter tree to the root of the taller tree, where rank refers to the number of subtrees of a set*/
              }
              else if(m == 2)
              {
                union_by_size(a2,b2);
                /*union by size always attatches the tree with lesser elements to the tree with more elements, where size refers to the number of elements in a set excluding the parent */
              }
              else if(m == 3)
              {
                union_by_linking(a2,b2);
                /*union by linking uses coin toss method(even/odd <=> true/false) to decide the parent of the sets being merged*/
              }
              break;
      case 4: int a3;
              NODE tp;
              printf("\nEnter the element : "); 
              scanf("%d",&a3);
              tp = path_compression(a3);
              /*path compression reduces the height of the tree set*/
              break;
      case 5: exit(0); 
      
    }
  }

  return 0;
   

}
