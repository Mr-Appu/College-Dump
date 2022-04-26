#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int power;
    struct node *next;
};

typedef struct node node;

void insert(node **headaddress, int c,int p)
{
    node *new = malloc(sizeof(node));
    new->coeff = c;
    new->power = p;
    new->next = NULL;
 
    node *it = *headaddress;
    if(it == NULL){*headaddress = new;return;}
    while(it->next != NULL) it = it->next;
    it->next = new;
    return;
}

void display(node **headaddress)
{
    node *it = *headaddress;
    printf("Poly : ");
    while(it != NULL)
    {
        printf("%d(x)^%d ",it->coeff,it->power);
        it = it->next;
    }
    printf("\n");
    return;   
}

int main(void)
{
    //1st Poly
    node *head1 = NULL;
    printf("Enter 1st Poly in Descending Order :\n");
    while(1)
    {
        int c,p;
        printf("Enter Coeff and Power : ");
        scanf("%d %d",&c,&p);
        insert(&head1,c,p);
        int flag = 1;
        printf("Wanna Continue ? (0/1) : ");
        scanf("%d",&flag);
        if(!flag) break;
    }
    
    
    //2st Poly
    node *head2 = NULL;
    printf("Enter 2st Poly in Descending Order :\n");
    while(1)
    {
        int c,p;
        printf("Enter Coeff and Power : ");
        scanf("%d %d",&c,&p);
        insert(&head2,c,p);
        int flag = 1;
        printf("Wanna Continue ? (0/1) : ");
        scanf("%d",&flag);
        if(!flag) break;
    }

    node *head3 = NULL;
    node *it1 = head1;
    node *it2 = head2;
  
    //Poly3 = poly2 + poly1
    while(it1 != NULL || it2 != NULL)
    {
        if(it1 == NULL)
        {
            insert(&head3,it2->coeff,it2->power);
            it2 = it2->next;
        }
        else if(it2 == NULL)
        {
            insert(&head3,it1->coeff,it1->power);
            it1 = it1->next;
        }
        else
        {
            if(it1->power == it2->power)
            {
                insert(&head3,it1->coeff+it2->coeff,it1->power);
	            it1 = it1->next;
	            it2 = it2->next;
            }
            else if(it1->power > it2->power)
            {
	            insert(&head3,it1->coeff,it1->power);
	            it1 = it1->next;
            }
            else
            {
	            insert(&head3,it2->coeff,it2->power);
	            it2 = it2->next;
            }
        }
    }
    
    display(&head1);
    display(&head2);
    display(&head3);
    
    return 0;
}