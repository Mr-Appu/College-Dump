#include <stdio.h>
#include <stdlib.h>

//Dfs and Bfs using adjacency list

struct node {
    int vertex;
    struct node *next;
};

typedef struct node node;

void insert(int v, node *arr[v],int a, int b) 
{
    node *ptr = arr[a];

    node *new = malloc(sizeof(node));
    new->vertex = b;
    new->next = NULL;

    if(ptr == NULL) {arr[a] = new; return;}

    while(ptr->next != NULL) ptr = ptr->next;
    ptr->next = new;
    return;
}

void display(int v,node *arr[v])
{
    for(int i=0;i<v;i++)
    {
        printf("%d -->",i);
        node *ptr = arr[i];
        while(ptr != NULL)
        {
            printf(" %d ",ptr->vertex);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void bfs(int st,int v,node *arr[v])
{
    int queue[(v*v)/2];
    int idx = 0,i = 0; // Two pointer method

    queue[idx++] = st;

    int visited[v];
    for(int i=0;i<v;i++) visited[i] = 0;

    printf("BFS : ");
    while(i != idx)
    {
        if(!(visited[queue[i]])) printf("%d ",queue[i]);
        visited[queue[i]] = 1;

        node *ptr = arr[queue[i]];
        while(ptr != NULL)
        {
            if(!visited[ptr->vertex]) queue[idx++] = ptr->vertex;
            ptr = ptr->next;
        }
        i++;
    }
    printf("\n");
}

void dfs(int st,int v,node *arr[v],int visited[v])
{
    printf("%d ",st);
    visited[st] = 1;

    node *ptr = arr[st];
    while(ptr != NULL)
    {
        if(!(visited[ptr->vertex]))
        {
            dfs(ptr->vertex,v,arr,visited);
        }
        ptr = ptr->next;
    }

    return;
}

int main(void)
{
    int v;
    
    printf("Enter no of Vertices : ");
    scanf("%d",&v);

    node *arr[v]; // Array of pointers
    for(int i=0;i<v;i++) arr[i] = NULL;

    int e;
    printf("Enter no of Edges : ");
    scanf("%d",&e);
    
    for(int i=0;i<e;i++)
    {
        printf("_ to _  : ");
        int n,m; scanf("%d %d",&n,&m);
        insert(v,arr,n,m);
        insert(v,arr,m,n);       
    }

    printf("\n");
    display(v,arr);
    printf("\n");
    bfs(0,v,arr);

    int visited[v];
    for(int i=0;i<v;i++) visited[i] = 0;
    
    printf("\nDFS : ");    
    dfs(0,v,arr,visited);

    return 0;
}
