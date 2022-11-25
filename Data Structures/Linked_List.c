#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} ;

typedef struct node node;
node *head;

void insert()
{
    node *new = malloc(sizeof(node));
    printf("Enter Data : ");
    scanf("%d",&new->data);
    new->next = NULL;

    if(head == NULL)
    {
        head = new;
        return;
    }

    int c = 0;
    printf("\n1.Beginning 2.End 3.Middle \nEnter : ");
    scanf("%d",&c);

    if(c == 1)
    {
        new->next = head;
        head = new;
        return;
    }
    else if(c == 2)
    {
        node *it = head;
        while(it->next != NULL) it = it->next;
        it->next = new;
        return;
    }
    else if(c == 3)
    {
        int pos = 0;
        printf("Enter pos : ");
        scanf("%d",&pos);

        int count = 0;
        node *it = head;
        pos--;
        while(it->next != NULL)
        {
            if(count++ == pos)
            {
                if(it->next == NULL)
                {
                    it->next = new;
                    return;
                }
                else
                {
                    new->next = it->next;
                    it->next = new;
                    return;
                }
            }
            it = it->next;
        }
    }
}

void display()
{
    node *it = head;
    printf("\nList : ");
    while(it != NULL)
    {
        printf("%d ",it->data);
        it = it->next;
    }
    printf("\n");
}

void delete(int n)
{
    if(head == NULL) return;
    if(head->data == n) {head = head->next;return;}

    node *it = head;   
    while(it->next != NULL)
    {
        if(it->next->data == n)
        {
            if(it->next->next == NULL) {it->next = NULL;return;}
            it->next = it->next->next;
            return;
        }
        it = it->next;
    }
}

int main(void)
{
    while(1)
    {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\nEnter : ");
        int c=0;scanf("%d",&c);

        if(c == 1) insert();
        else if(c == 2)
        {
            int del = 0;
            printf("Enter no : ");
            scanf("%d",&del);
            delete(del);
        }
        else if(c == 3) display();
        else if(c == 4) break;
        else continue;
    }
    return 0;
}
