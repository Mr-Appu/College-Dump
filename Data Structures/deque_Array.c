#include <stdio.h>
#include <stdlib.h>

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

void push(int arr[],int num)
{
    if(isempty())
    {
        front++;
        rear++;
        arr[front] = num;
        return;
    }
    
    if(isfull()) return;
    
    if(front == 0)
    {
        front = n-1;
        arr[front] = num;
        return;
    }
    
    front--;
    arr[front] = num;
    return;
}

int pop(int arr[])
{
    if(isempty()) return -1;
    int num = arr[front];
    if (rear==front)
    {
        rear = -1;
        front = -1;
        return num;
    }
    
    front = (front+1)%n;
    return num;
}

void insert(int arr[],int num){
    if (isempty()){
        front=front+1;
        rear=rear+1;
        arr[rear]=num;
        return;
    }
    if (isfull()){
        return;
    }
    rear = (rear + 1)%n;
    arr[rear] = num;
    return;
}

int eject(int arr[])
{
    if(isempty()) return -1;
    
    int num = arr[rear];
    
    if(rear == front)
    {
        rear = -1;
        front = -1;
        return num;
    }
    
    if(rear == 0) rear = n-1;
    else rear--;
    
    return num;
}

void display(int arr[])
{
    printf("List : ");
    if(isempty()) return;
    int i = front;
    do
    {
        printf("%d ",arr[i]);
        i = (i+1)%n;
    } while(i != (rear+1)%n);
    return;
}

int main(void)
{
    printf("Enter size : ");
    scanf("%d",&n);
    
    int arr[n];

    while(1)
    {
        printf("\n1.Push 2.Pop 3.Inject 4.Eject 5.Display 6.Exit \nEnter : ");
        int flag = 0;
        scanf("%d",&flag);

        if(flag == 1)
        {
            int data;
            printf("Enter data : ");
            scanf("%d",&data);
            push(arr,data);
        }
        else if(flag == 2) printf("Front : %d\n",pop(arr));
        else if(flag == 3)
        {
            int data;
            printf("Enter data : ");
            scanf("%d",&data);
            insert(arr,data);
        }
        else if(flag == 4) printf("Rear : %d\n",eject(arr));
        else if(flag == 5) display(arr);
        else if(flag == 6) break;
        else continue;
    }
    
    return 0;
}

