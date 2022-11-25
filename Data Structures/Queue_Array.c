#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int front = -1,rear = -1;

int isempty()
{
    if(front == -1 && rear == -1) return 1;
    else return 0;
}

int isfull()
{
    if((rear+1)%n == front) return 1;
    else return 0;
}

void enqueue(int arr[],int num)
{
    if(isempty())
    {
        arr[0] = num;
        front++; rear++;
        return;
    }
    else if(isfull())
    {
        printf("Array is Full\n");
        return;
    }
    else
    {
        rear = ++rear % n;
        arr[rear] = num;
        return; 
    } 
}

void dequeue(int arr[])
{
    if(isempty())
    {
        printf("Array is Empty\n");
        return;
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
        return;
    }
    else
    {
        front = ++front % n;
        return;
    }
}

int peek(int arr[])
{
    if(isempty())
    {
        printf("Array is Empty\n");
        return -1;
    }
    else
    {
        return arr[front];
    }
}

void display(int arr[])
{
    if(isempty())
    {
        printf("Array is Empty\n");
        return;
    }
    printf("List : ");
    //For loop
    if(isfull())
    {
        printf("%d ",arr[front]);
        for(int i=(front+1)%n;i!=(rear+1)%n;i=(i+1)%n)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    else
    {
        for(int i=front;i!=(rear+1)%n;i=(i+1)%n)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    // While Loop
    printf("List : ");
    int i = front;
    do 
    {
        printf("%d ",arr[i]);
        i = (i+1)%n;
    } while(i != (rear+1)%n);
    printf("\n");
}

int main(void)
{
    printf("\nEnter Array Size : ");
    scanf("%d",&n);

    int arr[n];
    
    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit \nEnter : ");
        int flag = 0;
        scanf("%d",&flag);

        if(flag == 1)
        {
            int data;
            printf("Enter data : ");
            scanf("%d",&data);
            enqueue(arr,data);
        }
        else if(flag == 2) dequeue(arr);
        else if(flag == 3) printf("Front : %d\n",peek(arr));
        else if(flag == 4) display(arr);
        else if(flag == 5) break;
        else continue;
    }

    return 0;
}
