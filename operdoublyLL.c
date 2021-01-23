#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next,*prev;
};
typedef struct node node1;
void in_b();
void in_e();
void in_bw();
void del_b();
void del_e();
void del_bw();
void dispf();
void dispb();
void search();
node1 *nptr;
node1 *start=NULL;
node1 *create();
void main()
{
    int ch;

    do
    {
       printf("\n\n\tLinked list implementation\n\t*****************************\n\n\t1.Insert at beginning\n\t2.Insert at end\n\t3.Insert in between\n\t4.Delete from beginning\n\t5.Delete from end\n\t6.Delete in between\n\t7.Display forward\n\t8.Display backward\n\t9.Search \n\t10.exit\n\n");
       printf("Enter your choice : ");
       scanf("%d",&ch);
       switch(ch)
        {
          case 1:in_b();
             break;
          case 2:in_e();
             break;
          case 3:in_bw();
             break;
          case 4:del_b();
             break;
          case 5:del_e();
             break;
          case 6: del_bw();
              break;
          case 7:dispf();
             break;
          case 8:dispb();
             break; 
          case 9:search();
             break; 
          case 10:exit(0);
             break;
          default:
            printf("\n invalid choice");
       }
 
   
   }while(ch!=10);
      return 0;

    

}
node1 *create()
{
    node1 *nptr=(node1*)malloc(sizeof(node1));
    if(nptr==NULL)
    {
       printf("memory overflow");
       return 0;
    }
    else
       return nptr;
}
void in_b()
  {
     int val;
     node1 *nptr=create();
    if(nptr==NULL)
       printf("Memory Overflow");
       else
       {
         printf("Enter the element:");
         scanf("%d",&val);
         nptr->value=val;
         if(start==NULL)
         {
          start=nptr;
          nptr->next=NULL;
          nptr->prev=NULL;
         }
         else
         {
         nptr->next=start;
         nptr->prev=NULL;
         start->prev=nptr;
         start=nptr;
         }
       }
    printf("\n Element inserted\n");
   }
    
   

void in_e()
   {
     node1 *nptr=create();
     node1 *temp=start;
     node1 *ptr;
     int val;
     if(nptr==NULL)
         printf("Memory Overflow");
     else
     {    
     printf("Enter the element:");
     scanf("%d",&val);
     nptr->value=val;
     if(temp==NULL) 
     {
     start=nptr;    
     nptr->next=NULL;
     nptr->prev=NULL;
     }
     else
     {
     while(temp!=NULL)
       {
         ptr=temp;
         temp=temp->next;
       }
         ptr->next=nptr;
         nptr->next=NULL;
         nptr->prev=ptr;
      } 
     }    
    printf("\n Element inserted.\n");       
}

void in_bw()
    {
     node1 *nptr=create();
     node1 *temp=start;
     node1 *ptr;
      int val,pos,c=1;
     printf("Enter the element: ");
     scanf("%d",&val);
     nptr->value=val;
     ptr=temp;
     nptr->next=NULL;
     printf("\n Enter position:");
     scanf("%d",&pos); 
     if(temp==NULL)
     {
         start=nptr;
         nptr->next=NULL;
         nptr->prev=NULL;
     }  
     else
     {       
     if(pos==1)
       {
       nptr->next=start;
       nptr->prev=NULL;
       start->prev=nptr;
        start=nptr;
       }
     else
       {
        while(temp!=NULL)
        {
         if(c==pos)
         {
             nptr->next=ptr->next;
             ptr->next->prev=nptr;
             nptr->prev=ptr;
             ptr->next=nptr;
             break;
         }
            ptr=temp;
           temp=temp->next;
            c++;
         }
       }
     }
     printf("\n Element Inserted.");
     
  }



void del_b()
   {
     node1 *nptr;
     if(start==NULL)
     {    
       printf("LIST EMPTY\n");
     }    
     else
       {
       nptr=start;
       printf("\n Element deleted is:%d",nptr->value);    
       start=nptr->next;
       nptr->next->prev=NULL;    
       free(nptr);
       }
    }

void del_e()
    {
      node1  *nptr ,*temp;
      int c=1;
      if(start==NULL)
      {
          printf("\n LIST EMPTY\n");
      } 
      else
       {
       nptr=start;
       while(nptr->next!=NULL)
       {
        temp=nptr;
        nptr=nptr->next;
        c++;
       }
        printf("\n Element deleted is:%d",nptr->value);
         temp->next=NULL;
         free(nptr);
          if(c==1)
          start=NULL;
      }
   }

void del_bw()
   {
    node1  *nptr,*temp;
    int c=1,pos,f;
    if(start==NULL)
        printf("\n LIST EMPTY\n");
    else
    {    
    printf("Enter the position of the node to be deleted:");
    scanf("%d",&pos);
    temp=start;
    nptr=start;
    if(pos==1)
    {    
       start=temp->next;
        printf("\n Element deleted is:%d",temp->value);
        f=1;
        
        temp->next->prev=NULL;
        free(temp);
    } 
    else
    {
        while(temp!=NULL)
        {
         if(c==pos)
         {
             nptr->next=temp->next;
             printf("\nElement deleted is:%d",temp->value);
             temp->next->prev=nptr;
             free(temp);
             f=1;
         }
            nptr=temp;
            temp=temp->next;
            c++;
        }
    }
    if(f==0)
    printf("\n Invalid Position\n");
    }
    } 
    
void dispf()
    {
      node1 *temp;
      temp=start;
      if(temp==NULL)
        printf("LIST EMPTY \n");
      else
      {
        printf("\n Linked list is:\n");
        while(temp!=NULL)
       {
       printf("%d ",temp->value);
       temp=temp->next;
       }
      }
    }


void dispb()
  {
    node1 *temp; 
    temp=start;
    if(temp==NULL) 
      printf("\n LIST EMPTY\n");
    else
    {
      printf("\n Linked list is:\n");
      while (temp->next!=NULL)
      {
        temp=temp->next; 
      }
      while(temp!=NULL) 
      {
        printf("\t %d",temp->value); 
        temp=temp->prev;
      }
    }
  }
  
  void search()
  {
    node1 *temp;
    int val,f=0,c=1;
    temp=start;
    if(temp==NULL) 
      printf("\n LIST EMPTY");
    else
    {
      printf("\n Enter the element to be searched:");
      scanf("%d",&val) ;
      while(temp!=NULL)
      {
        if(temp->value==val) 
        {
          printf("\n Element  found at position %d",c); 
          f=1;
        }
        temp=temp->next; 
        c++;
      }
      if(f==0)
       printf("\n Element not found");
    } 
  }