#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void input();
void output();
void setunion();
void intersection();
void difference(); 
int n1,n2,s1[]={0,0,0,0,0,0,0,0,0},s2[]={0,0,0,0,0,0,0,0,0};
void main()
{
    int choice;
    do
    {
     printf("\nSet Operations");
     printf("\n1.Input  \n2.Output  \n3.Union  \n4.Inersection  \n5.Difference \n6.Exit \n");
     printf("Enter your choice: ");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:input();
               break;
        case 2:output();
               break;
        case 3:setunion();
               break;
        case 4:intersection();
                break;
        case 5:difference();
                break;   
        case 6:exit (0);
               break;
        default:printf("Invalid choice!!!");       
     }
    } while(choice!=6);
} 

void input()
{
    int i,val;
    printf("Enter the size of first set (s1): ");
    scanf("%d",&n1);
    printf("Enter the values: \n");
    for(i=0;i<n1;i++)
    {
    scanf("%d",&val);
    s1[val-1]=1;
    }
    
    printf("\nEnter the size of second set (s2): ");
    scanf("%d",&n2);
    printf("Enter the values:\n");
    for(i=0;i<n2;i++)
    {
    scanf("%d",&val);
    s2[val-1]=1;
    }
}

void output()
{ 
    int i,j;
     printf("\nValues of 1st set: ");
    for(i=0;i<9;i++)
    printf("%d ",s1[i]);
    
    printf("\nValues of 2nd set: ");
    for(i=0;i<9;i++)
    printf("%d ",s2[i]);
    
}

void setunion()
{
    int i,s3[10];
     printf("\nUnion is: ");
    for(i=0;i<9;i++)
    {
    if(s1[i]==0 && s2[i]==0)
        s3[i]=0;
    else
        s3[i]=1;
    }
    for(i=0;i<9;i++)
    printf("%d",s3[i]);
}

void intersection()
{
    int i,s3[10];
     printf("\nIntersection is: ");
    for(i=0;i<9;i++)
   {
    if(s1[i]==1 && s2[i]==1 )
        s3[i]=1;
    else
       s3[i]=0;
    }
    for(i=0;i<9;i++)
    printf("%d",s3[i]);
}

void difference()
{
    int i,s3[10],s4[10];
     printf("\nDifference is: ");
    for(i=0;i<9;i++)
    {
        if(s2[i]==0)
           s4[i]=1;
        else
           s4[i]=0;
    }
    for(i=0;i<9;i++)
   {
    if(s1[i]==1 && s4[i]==1 )
        s3[i]=1;
    else
       s3[i]=0;
    }
    for(i=0;i<9;i++)
    printf("%d",s3[i]);
}