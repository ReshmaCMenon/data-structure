#include <stdio.h>
struct disjoset{
  int p[10];
  int rank[10];
  int n; 
}dis;

    
    
void makeset()
{
    int i;
  for( i=0;i<dis.n;i++)
  {
    dis.p[i]=i; 
    dis.rank[i]=0;
    
  }
 }

 void display()
{
  int i;
  printf(" Parent array:");
  for( i=0;i<dis.n;i++)
  {
    printf("%d",dis.p[i]);
  }
  printf("\nRank array:\n");
  for(i=0;i<dis.n;i++)
  {
    printf("%d",dis.rank[i]);
  }
  printf("\n");
}

int find(int x)
{
  if(dis.p[x]!=x)
  {
  dis.p[x]=find(dis.p[x]);
  }
  return dis.p[x];
  
}
 
 
int Union(int x, int y) 
{
  int xset=find(x);
  int yset=find(y);
  if(xset==yset)
  return; 
  if(dis.rank[xset]<dis.rank[yset])
  {
    dis.p[xset]=yset; 
    dis.rank[xset]=-1;
    
  }
  else if(dis.rank[xset]>dis.rank[yset])
  {
    dis.p[yset]=xset; 
    dis.rank[yset]=-1;
    
  }
  else
  {
      dis.p[yset]=xset;
      dis.rank[xset]=dis.rank[xset]+1;
      dis.rank[yset]=-1;
  }
}
 
 
 
 
 int main()
 {
   int x, y, n; 
   printf("Enter the size:");
   scanf("%d",&dis.n); 
   makeset();
     int ch;
     
     do
     {
         printf("\n ____MENU____\n");
         printf("\n1.Union \n2.Find \n3.Display\n4.Exit\n");
         printf("Enter the choice:\n"); 
         scanf("%d",&ch);
         
      switch(ch)
      {
          case 1: printf("Enter the elements to perform union:");
                  scanf("%d %d",&x,&y);
                  Union(x,y);
                 break;
          
         case 2: printf("Enter the elements to check if connected components:");
                  scanf("%d %d",&x,&y);
                  if(find(x)==find(y))
                  printf("Connected components\n");
                  else
                  printf("Not connected components \n");
                 break; 
          case 3: display();
                 break;
          default:
            printf("\n invalid choice");
       }             
     }while(ch!=4);
      return 0;   
  }
      
      
      
      
      
      