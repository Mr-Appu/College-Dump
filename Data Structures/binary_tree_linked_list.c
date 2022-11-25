#include <stdio.h>
#include <stdlib.h>

/*
Binary Search Tree using linked_list
Binary Search Tree Property : left_data < node_data & right_data > node_data & no_duplicate
*/

#define COUNT 4

struct node {
    int data;
    struct node *left,*right;
};

typedef struct node node;
node *root;

void insert(node *temp,int data)
{
    if(root == NULL)
    {
        node *new = malloc(sizeof(node));
        new->data = data;
        new->left = new->right = NULL;
        root = new;
        return;
    }
    
    if(temp->data > data)
    {
        if(temp->left == NULL)
        {
            node *new = malloc(sizeof(node));
            new->data = data;
            new->left = new->right = NULL;
            temp->left = new;
            return;
        }
        else insert(temp->left,data);
    }
    else if(temp->data < data)
    {
        if(temp->right == NULL)
        {
            node *new = malloc(sizeof(node));
            new->data = data;
            new->left = new->right = NULL;
            temp->right = new;
            return;
        }
        else insert(temp->right,data);
    }
}

void display(node *temp) // Inorder Display
{
    if(temp == NULL) return;
    
    display(temp->left);
    printf("%d ",temp->data);
    display(temp->right);
}

int find(node *temp,int data)
{
    if(temp == NULL) return 0;
    
    if(temp->data > data) find(temp->left,data);
    else if(temp->data < data) find(temp->right,data);
    else return 1;
}

int smallest(node *temp)
{
    if(root == NULL) return -1;
    
    if(temp->left == NULL) return temp->data;
    else smallest(temp->left);
}

int largest(node *temp)
{
    if(root == NULL) return -1;
    
    if(temp->right == NULL) return temp->data;
    else largest(temp->right);
}

void printTree(struct node *root, int space)
{
    if (root == NULL) return;
    space += COUNT;
    printTree(root->right, space);
    for (int i = COUNT; i < space; i++) printf(" ");
    printf("%d\n",root->data);
    printTree(root->left, space);
}

int main(void)
{
    while(1)
    {
        printf("1.Insert 2.Display 3.Find 4.Largest & Smallest 5.Print Tree 6.Exit\nEnter : ");
        int ch; scanf("%d",&ch);
        
        if(ch == 1)
        {
            int data;
            printf("Enter data : ");
            scanf("%d",&data);
            insert(root,data);
        }
        else if(ch == 2)
        {
            printf("Tree : ");
            display(root);
            printf("\n");
        }
        else if(ch == 3)
        {
            int data;
            printf("Enter data : ");
            scanf("%d",&data);
            if(find(root,data)) printf("Number %d found\n",data);
            else printf("Number %d not found\n",data);
        }
        else if(ch == 4) printf("Largest : %d\nSmallest : %d\n",largest(root),smallest(root));
        else if(ch == 5) printTree(root,1);
        else if(ch == 6) return 0;
    }
    
    return 0;
}
