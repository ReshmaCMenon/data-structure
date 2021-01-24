#include <stdio.h>
#define MAX 10
void enqueue();
void dequeue();
void peek();
void display();

int queue[MAX],rear = - 1,front = - 1;
int main()
{
    
    int ch;
    do
    {
       printf("\n*******MENU******\n");
        printf("1.Enqueue  \n");
        printf("2.Dequeue \n");
        printf("3.Peek \n");
        printf("4.Display\n");
        printf("5.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            peek();  
            break;  
            case 4:
            display();
            break;
            case 5:
            printf("Exit\n");
            break;
            default:
            printf("Wrong choice \n");
        } 
    }
    while(ch!=5);
    return 0;

} 
 
void enqueue()
{
    int add_item;
    if ( (front==rear+1)||(front==0 && rear==MAX-1) )
        printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        rear = (rear + 1)%MAX;
        printf("Enter the element in queue : \n");
        scanf("%d", &add_item);
        queue[rear] = add_item;
        printf("\n Inserted element is %d",add_item);
    }
} 
 
void dequeue()
{
    int del_item;
    if (front == - 1)
    {
        printf("Queue Underflow \n");
    }
    else
    {
        del_item=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%MAX;    
        }
        printf("Element deleted from queue is : %d\n", del_item);
    }
} 

 void peek()
{
  if (front == -1)
        printf("Queue Underflow \n");
  else
        printf("\nFirst queue element is:%d\n",queue[front]);
}
 
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf(" Elements in the Circular Queue are : \n");
        for (i = front; i!=rear; i=(i+1)%MAX)
        {
            printf("%d ", queue[i]);
        }
        printf("%d",queue[i]);
    }
}

    