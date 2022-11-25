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
    
    printf("Enter Node Data : ");
    scanf("%d",&(new->data));
    new->next = NULL;
    
    if(head == NULL)
    {
        head = new;
        return;
    }
    
    node *it = head;
    while(it->next != NULL)
    {
        it = it->next;
    }
    
    it->next = new;
}

void delete(int del)
{
    node *it = head;
    
    if(head->next == NULL && it->data == del)
    {
        free(head);
        head = NULL;
        return;
    }
    
    if(head->next != NULL && it->data == del)
    {
        head = head->next;
        return;
    }
    
    while(it->next != NULL)
    {
        if(it->next->data == del)
        {
            if(it->next->next == NULL){it->next = NULL;return;}
            else
            {
                it->next = it->next->next;
            }
            break;
        }
        it = it->next;
    }
}

void display()
{
    node *it = head;
    printf("\nList : ");
    while(it!=NULL)
    {
        printf("%d ",it->data);
        it = it->next;
    }
}

void delete_min()
{
    node *it = head;
    node *min = head;
    while(it != NULL)
    {
        if(it->data < min->data) min = it;
        it = it->next;
    }
    printf("Smallest Element :  %d\n",min->data);
    delete(min->data);
}

void head_to_tail()
{
    
    if(head == NULL) return;
    else if(head->next == NULL) return;
    
    node *it = head;
    node *nexthead = head->next;
    while(it->next != NULL)
    {
        it = it->next;
    }
    
    it->next = head;
    it->next->next = NULL;
    head = nexthead;  
    return;
}

void reverse_list()
{
    if(head == NULL) return;
    if(head->next == NULL) return;
    
    node *prev = head;
    node *it = head->next;
    node *temp = head->next;
    node *cur = NULL;
    
    while(it != NULL)
    {
        cur = it;
        temp = it;
        it = it->next;
        temp->next = prev;
        prev = cur;
    }
    
    head->next = NULL;
    head = cur;
}

int main(void)
{
    int n;
    printf("Enter Size of List : ");
    scanf("%d",&n);
    
    printf("\n");
    for(int i=0;i<n;i++) insert();
    
    int c = 1;
    while(c != 0)
    {
        printf("\n1.Delete_min 2.Head_to_Tail 3.Reverse_List 4.Exit \n");
        printf("Enter n : ");
        scanf("%d",&c);
        
        switch(c)
        {
            case 1:
                delete_min();
                display();
                break;
            case 2:
                head_to_tail();
                display();
                break;
            case 3:
                reverse_list();
                display();
                break;
            case 4:
                c = 0;
                break;
            default:
                printf("Enter Valid Option\n");
                break;
        }
    }
    
    return 0;
}
