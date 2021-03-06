#include<stdio.h>
#include<stdlib.h>

struct stack
{
  int data;
  struct stack *next; 
};
typedef struct stack node;
void push();
void pop();
void peek();
void display();
node *newnode; 
node *ptr; 
node *top;

int main()
{
  int ch;


do 
{
printf("\n********MENU*********\n");
printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
printf("Enter the choice:");
scanf("%d",&ch);

  switch(ch)
   {
     case 1:push();
      break;
     case 2:pop();
      break;
     case 3:peek();
      break;
     case 4:display();
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
   int value; 
   newnode=(node*)malloc(sizeof(node));
   if(newnode==NULL) 
   {
     printf("Element cannot be inserted.");
   }
   printf("\n Enter the value:");
   scanf("%d",&value);
   newnode->data=value;
   newnode->next=NULL;
   if(top==NULL)
   top=newnode;
   else 
   {
     newnode->next=top;
     top=newnode;
   }
   printf("Element successfully inserted.");
 }
 
 
 void pop()
 {
   int del_elem; 
   if(top==NULL)
   {
   printf("\n Stack Underflow");
   }
   else
   {
     del_elem=top->data; 
     ptr=top;
     top=top->next; 
     free(ptr);
   }
   printf("\nDeleted element is :%d",del_elem); 
 }
 
 void peek()
 {
   if(top==NULL)
   printf("\n Stack is empty");
   else
   printf("\n Element in the top of the stack is:%d",top->data);
 }
 
 void display()
 {
   
   ptr=top;
   if(ptr==NULL)
   printf("\n Stack is empty");
   else
   {
     printf("\n Stack elements are:");
     while(ptr!=NULL)
     {
       printf("%d \t",ptr->data);
       ptr=ptr->next; 
     }
   }
 }