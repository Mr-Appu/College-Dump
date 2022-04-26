#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node *front = NULL;
node *rear = NULL;

int isempty()
{
    if(front == NULL && rear == NULL) return 1;
    else return 0;
}

void enqueue(int num)
{
    node *new = malloc(sizeof(node));
    new->data = num;
    new->next = NULL;
    

    if(isempty())
    {
        front = new;
        rear = new;
        return;
    }

    rear->next = new;
    rear = new;
    return; 
}

void dequeue()
{
    if(isempty()) return;

    if(front == rear)
    {
        front = NULL;
        rear = NULL;
        return;
    }

    front = front->next;
    return;
}

int peek()
{
    if(isempty()) return -1;
    else return front->data;
}

void display()
{
    node *it = front;
    printf("List : ");
    while(it != NULL)
    {
        printf("%d ",it->data);
        it = it->next;
    }
    printf("\n");
}

int main(void)
{
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
            enqueue(data);
        }
        else if(flag == 2) dequeue();
        else if(flag == 3) printf("Front : %d\n",peek());
        else if(flag == 4) display();
        else if(flag == 5) break;
        else continue;
    }

    return 0;
}