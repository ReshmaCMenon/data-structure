#include <stdio.h>
int st[20],top=-1,n;

void push();
void pop();
void display();
void peek();
int main()
 {
  int ch;

printf("Enter size of stack:");
scanf("%d",&n);
  do
   {
printf("\n********MENU*********\n");
printf("1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");
printf("Enter the choice:");
scanf("%d",&ch);

  switch(ch)
   {
     case 1:push();
      break;
     case 2:pop();
      break;
     case 3:display();
      break;
     case 4:peek();
      break;
      case 5:printf("Exit\n");
        break;
      default:
          printf("Wrong choice\n");
  
   }
}while(ch!=5);
 return 0;
 }

void push()
   {
    int elem;
    if(top>n-1)
     {
printf("\nstack overflow");
     }
    else
     {
      printf("Enter  the element:");
      scanf("%d",&elem);
      top=top+1;
      st[top]=elem;
      }
    }
void pop()
   {
    int del_item;
    if(top<=-1)
     {
printf("\nstack underflow");
     }
    else
     {
       del_item=st[top]; 
printf("\nDeleted element is %d",del_item);
      top=top-1;
     }
    }
void display()
   {
    int i;
   if (top<=-1) 
   {
       printf("\nStack underflow");
   
   }
    else
   {
     printf("Elements present in stack are:");
      for(i=top;i>-1;i--)
    {
  printf("%d ",st[i]);   
    }
   }
   }
void peek()
{
    if (top<=-1) 
   {
       printf("\nStack underflow");
   
   }
    else
    {
     printf("\nElement in the top of stack is :%d",st[top]);   
    }
}

    