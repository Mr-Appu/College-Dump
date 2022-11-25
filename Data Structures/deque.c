#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

node *front;
node *rear;

void push(int num)
{
    node *new = malloc(sizeof(node));
    new->data = num;
    new->next = NULL;
    new->prev = NULL;
    
    if(front == NULL && rear == NULL)
    {
        front = new;
        rear = new;
        return;
    }
    
    new->next = front;
    front->prev = new;
    front = new;
    front->prev= NULL;
    return;
}

int pop()
{
    int data = front->data;
    if(front == rear)
    {
        front = NULL;
        rear = NULL;
        return data;
    }
    
    front = front->next;
    front->prev = NULL;
    return data;
}

void inject(int num)
{
    node *new = malloc(sizeof(node));
    new->data = num;
    new->next = NULL;
    new->prev = NULL;
    
    if(front == NULL && rear == NULL)
    {
        front = new;
        rear = new;
        return;
    }
    
    rear->next = new;
    new->prev = rear;
    rear = new;
    return;
}

int eject()
{
    int data = rear->data;
    if(front == rear)
    {
        front = NULL;
        rear = NULL;
        return data;
    }
    
    rear = rear->prev;
    rear->next = NULL;
    return data;
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
    return;
}

int main(void)
{
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
            push(data);
        }
        else if(flag == 2) printf("Front : %d\n",pop());
        else if(flag == 3)
        {
            int data;
            printf("Enter data : ");
            scanf("%d",&data);
            inject(data);
        }
        else if(flag == 4) printf("Rear : %d\n",eject());
        else if(flag == 5) display();
        else if(flag == 6) break;
        else continue;
    }

    return 0;
}
