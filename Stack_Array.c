#include <stdio.h>
#include <stdlib.h>

int t,n;

int isFull(int arr[])
{
    if(t == n-1) return 1;
    else return 0;
}

int isEmpty(int arr[])
{
    if(t == -1) return 1;
    else return 0;
}

void push(int arr[],int data)
{
    if(isFull(arr)) {printf("Array is Full\n");return;}
    arr[++t] = data;
}

void pop(int arr[])
{
    if(isEmpty(arr)) {printf("Array is Empty\n");return;}
    t--;
}

void top(int arr[])
{
    if(isEmpty(arr)) {printf("Array is Empty\n");return;}
    printf("Top : %d\n",arr[t]);
}

void display(int arr[])
{
    if(isEmpty(arr)) {printf("Array is Empty\n");return;}
    printf("Stack : ");

    for(int i=0;i<=t;i++) printf("%d ",arr[i]);
    printf("\n");
}

int main(void)
{
    printf("Enter Size : ");
    scanf("%d",&n);
    t = -1;

    int arr[n];

    while(1)
    {
        printf("\n1.Push 2.Pop 3.Top 4.Display 5.Exit \nEnter : ");
        int flag = 0;
        scanf("%d",&flag);

        if(flag == 1)
        {
            int data;
            printf("Enter data : ");
            scanf("%d",&data);
            push(arr,data);
        }
        else if(flag == 2) pop(arr);
        else if(flag == 3) top(arr);
        else if(flag == 4) display(arr);
        else if(flag == 5) break;
        else continue;
    }

    return 0;
}