#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;
node *top;

int isempty()
{
    if(top == NULL) return 1;
    else return 0;
}

void push(int n)
{
    node *new = malloc(sizeof(node));
    new->data = n;
    if(isempty())
    {
        top = new;
        new->next = NULL;
    }
    else
    {
        new->next = top;
        top = new;
    }
}

void pop()
{
    if(isempty()) {printf("Stack is Empty\n");return;}
    else top = top->next;
}

int seek()
{
    if(isempty()) return -1;
    else return top->data;
}

void display()
{
    node *it = top;
    printf("\nList : ");
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
        printf("\n1.Push 2.Pop 3.Seek 4.Display 5.Exit\nEnter : ");
        int c = 0; scanf("%d",&c);
        if(c == 1)
        {
            printf("Enter data : ");
            int data; scanf("%d",&data);
            push(data);
        }
        else if(c == 2) pop();
        else if(c == 3) printf("Top : %d\n\n",seek());
        else if(c == 4) display();
        else if(c == 5) break;
        else continue;
    }

    return 0;
}
