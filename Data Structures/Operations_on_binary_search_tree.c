#include <stdio.h>
#include <stdlib.h>

/*
Binary Search Tree using linked_list
Binary Search Tree Property : left_data < node_data & right_data > node_data & no_duplicate
*/

#define COUNT 4
#define max(x,y) (((x) > (y)) ? (x) : (y))

struct node {
    int data;
    struct node *left,*right;
};

typedef struct node node;
node *root;

node* insert(node *temp,int data)
{
    if(temp == NULL)
    {
        node *new = malloc(sizeof(node));
        new->data = data;
        new->left = new->right = NULL;
        return new;
    }
    
    if(temp->data > data) temp->left = insert(temp->left,data);
    else if(temp->data < data) temp->right = insert(temp->right,data);

    return temp;
}

void inorder(node *temp) // Inorder Display
{
    if(temp == NULL) return;
    
    inorder(temp->left);
    printf("%d ",temp->data);
    inorder(temp->right);
}

void preorder(node *temp)
{
    if(temp == NULL) return;

    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(node *temp)
{
    if(temp == NULL) return;

    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);
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

/*
Node can have 0,1,2 Child Elements 

    1
   / \
  2   3
       \
        4  

Delete 4 : 0 Child Element (Leaf Node)
3->left = NULL      

Delete 3 : 1 Child Element 
1->right = 4

Delete 1 : 2 Child Element 
{
    1.Inorder Predecessor
    {
        Replace with maximum of left subtree
        2
         \
          3
           \ 
            4
    }
    2.Inorder Successor
    {
        Replace with minimum of right subtree
        3
       / \
      2   4
    }
}
*/

node* delete(node *temp,int n)
{
    if(temp == NULL) return temp;

    if(n < temp->data) temp->left = delete(temp->left,n);
    else if(n > temp->data) temp->right = delete(temp->right,n);
    else // n == temp->data
    {
        if(temp->left == NULL) return temp->right;
        else if(temp->right == NULL) return temp->left;
        else // Both != NULL
        {
            //Inorder Successor
            int min = smallest(temp->right);
            printf("%d ",min);
            temp = delete(temp,min);
            temp->data = min;
        }
    }

    return temp;
}

void levelorder(node *temp)
{
    node *arr[1000];
    arr[0] = root;
    int i=1,j=0;
    while(i!=j) // is empty -> break
    {
        if(arr[j] != NULL)
        {
            printf("%d ",arr[j]->data);
            if(arr[j]->left != NULL) arr[i++] = arr[j]->left;
            if(arr[j]->right != NULL) arr[i++] = arr[j]->right;
        }
        j++;
    }
    return;
}

int height(node *temp)
{
    if(temp == NULL) return 0; 

    int left_height = height(temp->left);
    int right_height = height(temp->right);

    //max -> Macros 
    return max(left_height,right_height) + 1; 
}

/*
If isbalanced() return 1 -> then the tree is Balanced
If isbalanced() return 0 -> then the tree is Not_Balanced
*/

int isbalanced(node  *temp) 
{
    if(temp == NULL) return 1;

    int left_subtree = height(temp->left);
    int right_subtree = height(temp->right);

    int flag = 0;

    if(abs(left_subtree - right_subtree) <= 1) flag = 1;

    return flag && isbalanced(temp->left) && isbalanced(temp->right); 
}

int depth(node *temp,int n) // Assuming that no 'n' is already present in Binary Search Tree
{
    if(temp == NULL) return 0;

    if(temp->data > n) return depth(temp->left,n) + 1;
    else if(temp->data < n) return depth(temp->right,n) + 1;
    else return 0;
}

node* predecessor(node *temp,node *pred,int n)
{
    if(temp == NULL) return NULL;

    if(temp->data < n) pred = temp;

    if(temp->data  > n) predecessor(temp->left,pred,n);
    else if(temp->data < n) predecessor(temp->right,pred,n);
    else
    {
        if(temp->left == NULL) return pred;
        else
        {
            node *max = temp->left;
            while(max->right != NULL) max = max->right;
            return max;
        } 
    }
}

node *successor(node *temp,node *succ,int n)
{
    if(temp == NULL) return temp;

    if(temp->data > n) succ = temp;

    if(temp->data > n) successor(temp->left,succ,n);
    else if(temp->data < n) successor(temp->right,succ,n);
    else
    {
        if(temp->right == NULL) return succ;
        else
        {
            node *min = temp->right;
            while(min->left != NULL) min = min->left;
            return min;
        }
    }
}

int is_binary_full(node *temp)
{
    if(temp == NULL) return 1;

    int flag = 0;

    if(temp->left == NULL && temp->right == NULL) flag = 1; // 0 - Child
    else if(temp->left != NULL && temp->right != NULL) flag = 1; // 2 - Child 
    else flag = 0; // 1 - Child 

    return flag && is_binary_full(temp->left) && is_binary_full(temp->right);
}

int main(void)
{
    while(1)
    {
        printf("1.Insert 2.Display 3.Find 4.Largest & Smallest 5.Print Tree 6.Delete 7.Is_Balanced 8.Depth 9.Predecessor 10.Successor 11.Is_Tree_Full 12.Exit \nEnter : ");
        int ch; scanf("%d",&ch);
        
        if(ch == 1)
        {
            int data;
            printf("Enter data : ");
            scanf("%d",&data);
            root = insert(root,data);
        }
        else if(ch == 2)
        {
            printf("Inorder : ");
            inorder(root);
            printf("\n");
            printf("Preorder : ");
            preorder(root);
            printf("\n");
            printf("Postorder : ");
            postorder(root);
            printf("\n");
            printf("Level Order : ");
            levelorder(root);
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
        else if(ch == 6)
        {
            int data;
            printf("Enter data : ");
            scanf("%d",&data);
            root = delete(root,data);
        }
        else if(ch == 7)
        {
            if(isbalanced(root)) printf("Tree is Balanced\n");
            else printf("Tree is not Balanced\n");
        }
        else if(ch == 8)
        {
            int data;
            printf("Enter data : "); scanf("%d",&data);
            if(find(root,data)) printf("Depth : %d\n",depth(root,data));
            else printf("No %d not Found\n",data);
        }
        else if(ch == 9)
        {
            int data;
            printf("Enter data : "); scanf("%d",&data);

            if(smallest(root) == data) {printf("No predecessor for %d\n",data); continue;}

            node *pred  = NULL;
            if(find(root,data)) printf("Predecessor : %d\n",predecessor(root,pred,data)->data);
            else printf("No %d not Found\n",data);
        }
        else if(ch == 10)
        {
            int data;
            printf("Enter data : "); scanf("%d",&data);

            if(largest(root) == data) {printf("No Successor for %d\n",data); continue;}

            node *succ  = NULL;
            if(find(root,data)) printf("Successor : %d\n",successor(root,succ,data)->data);
            else printf("No %d not Found\n",data);
        }
        else if(ch == 11) printf("Is Binary Full Tree : %d\n",is_binary_full(root));
        else if(ch == 12) return 0;
    }
    
    return 0;
}
