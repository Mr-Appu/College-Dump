#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;
node *head;

void insert()
{
    node *new = malloc(sizeof(node));
    printf("Enter data : ");
    scanf("%d",&new->data);

    if(head == NULL){head = new; new->next = new; return;}

    node *it = head;
    while(it->next != head) it = it->next;
    it->next = new;
    new->next = head;
    return;
}

void display()
{
    node *it = head;
    printf("\nList : ");
    do
    {
        printf("%d ",it->data);
        it = it->next;
    } while (it != head);
    printf("\n");
    return;
}

void delete(int n)
{
    if(head == NULL) return;
    if(head->data == n && head->next == head) {head = NULL; return;}
    if(head->data == n && head->next != head)
    {
        node *temphead = head;
        head = head->next;
        node *it = head;
        while(it->next != temphead) it = it->next;
        it->next = head;
        return;
    }

    node *it = head;
    do
    {
        if(it->next->data == n)
        {
            it->next = it->next->next;
            break;
        }
        it = it->next;
    } while(it != head);
}

int main(void)
{
    while(1)
    {
        printf("1.Insert 2.Delete 3.Display 4.Break\nEnter n : ");
        int n;scanf("%d",&n);

        if(n == 1) insert();
        else if(n == 2)
        {
            int del;
            printf("Enter del : ");
            scanf("%d",&del);
            delete(del);
        }
        else if(n == 3) display();
        else if(n == 4) break;
        else continue;
    }
    return 0;  
}
