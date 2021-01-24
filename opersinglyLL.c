#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *link;
};
typedef struct node node1;
void in_b();
void in_e();
void in_bw();
void del_b();
void del_e();
void del_bw();
void display();
node1 *nptr;
node1 *start=NULL;
node1 *create();
void main()
{
    int ch;

    do
    {
       printf("\n\n\tLinked list implementation\n\t*****************************\n\n\t1.Insert at beginning\n\t2.Insert at end\n\t3.Insert in between\n\t4.Delete from beginning\n\t5.Delete from end\n\t6.Delete in between\n\t7.Display\n\t8.exit\n\n");
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
          case 7:display();
             break;
          case 8:exit(0);
             break;
          default:
            printf("\n invalid choice");
       }
 
   
   }while(ch!=8);
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
     printf("Enter the element:");
     scanf("%d",&val);
     nptr->value=val;
     if(start==NULL)
       {
    start=nptr;
    nptr->link=NULL;
       }
     else
       {
    nptr->link=start;
    start=nptr;
       }
    
   }

void in_e()
   {
     node1 *temp,*nptr=create();
     int val;
     printf("Enter the element:");
     scanf("%d",&val);
     nptr->value=val;
     nptr->link=NULL;
     temp=start;
     while(temp->link!=NULL)
       {
     temp=temp->link;
       }
    temp->link=nptr;
    
}

void in_bw()
    {
     node1 *temp,*nptr=create();
     int val,pos,i;
     printf("Enter the element and position to be inserted: ");
     scanf("%d %d",&val,&pos);
     nptr->value=val;
     nptr->link=NULL;
     temp=start;
     if(pos==1)
       {
    nptr->link=start;
    start=nptr;
       }
     else
       {
    for(i=1;i<pos-1;i++)
       {
         temp=temp->link;
       }
     nptr->link=temp->link;
     temp->link=nptr;
       }
     
    }



void del_b()
   {
     node1 *temp;
     if(start==NULL)
       printf("LIST EMPTY\n");
     else
       {
     temp=start;
     start=start->link;
     free(temp);
       }
    }

void del_e()
    {
      node1 *temp,*prev;
      temp=start;
     while(temp->link!=NULL)
    {
     prev=temp;
     temp=temp->link;
    }
     prev->link=NULL;
     free(temp);
   }

void del_bw()
   {
    node1 *temp,*prev;
    int i,pos;
    printf("Enter the position of the node to be deleted:");
    scanf("%d",&pos);
    temp=start;
    if(pos==1)
       start=start->link;
    for(i=1;i<pos;i++)
      {
        prev=temp;
        temp=temp->link;
      }
     prev->link=temp->link;
     free(temp);
    }
    
void display()
    {
      node1 *temp;
      if(start==NULL)
    printf("LIST EMPTY!!\n");
      temp=start;
      while(temp!=NULL)
       {
     printf("%d ",temp->value);
     temp=temp->link;
       }
    }