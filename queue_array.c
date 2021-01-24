#include <stdio.h>
 
void enqueue();
void dequeue();
void peek();
void display();

int queue[20],rear = - 1,front = - 1,n;
int main()
{
    printf("\n Enter the size:");
    scanf("%d",&n);
    int ch;
    do
    {
       printf("*******MENU******\n");
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
    if (rear == n - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("Enter the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue[rear] = add_item;
    }
} 
 
void dequeue()
{
    int del_item;
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
    }
    else
    {
        del_item=queue[front];
        printf("Element deleted from queue is : %d\n", queue[front]);
        front = front + 1;
    }
} 

 void peek()
{
  if (front == - 1 || front > rear)
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
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

    