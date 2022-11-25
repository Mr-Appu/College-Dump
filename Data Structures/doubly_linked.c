#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;
node *head;
node *tail;

void insert()
{
    node *new = malloc(sizeof(node));
    printf("Enter data : ");
    scanf("%d",&new->data);

    if(head == NULL)
    {
        head = new;
        head->prev = NULL;
        head->next = NULL;
        tail = new;
        return;
    }

    node *it = head;
    while(it->next != NULL) it = it->next;
    it->next = new;
    new->prev =  it;
    new->next = NULL;
    tail = new;
    return;    
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
    printf("\n\n");
}

void delete(int m)
{
    if(head->data == m && head->next == NULL)
    {
        head = NULL;
        return;
    }

    if(head->data == m && head->next != NULL)
    {
        head = head->next;
        head->prev = NULL;
        return;
    }

    node *it = head;
    while(it->next != NULL)
    {
        if(it->next->data == m && it->next->next != NULL)
        {
            it->next->next->prev = it;
            it->next = it->next->next;
            return;
        }
        it = it->next;
    }

    if(tail->data == m)
    {
        tail->prev->next = NULL;
        tail = tail->prev;
        return;
    }

}

void display_reverse()
{
    node *it = tail;
    printf("\nList : ");
    while(it != NULL)
    {
        printf("%d ",it->data);
        it = it->prev;
    }
    printf("\n\n");
}

int main(void)
{
    while(1)
    {
        printf("1.Insert 2.Delete 3.Display 4.Display(reverse) 5.Exit \nEnter : ");
        int c; scanf("%d",&c);

        if(c == 1) insert();
        else if(c == 2)
        {
            int del;
            printf("Enter del : ");
            scanf("%d",&del);
            delete(del);
        }
        else if(c == 3) display();
        else if(c == 4) display_reverse();
        else if(c == 5) break;
        else continue;
    }
    return 0;
}
