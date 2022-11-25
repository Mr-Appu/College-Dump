#include <stdio.h>
#include <stdlib.h>
//dfs using adjacency matrix assuming no 

void insert(int v, int arr[v][v],int a,int b) {arr[a][b] = 1; arr[b][a] = 1;return;}

void display(int v,int arr[v][v])
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++) printf("%d ",arr[i][j]);
        printf("\n");
    }
}

void dfs(int start,int v,int arr[v][v],int visited[])
{
    printf("%d ",start);
    visited[start] = 1;

    for(int i=0;i<v;i++)
    {
        if(arr[start][i] && !(visited[i]))
        {
            dfs(i,v,arr,visited);
        }
    }

    return;
}

void bfs(int v,int arr[v][v],int start)
{
    int visited[v];
    for(int i=0;i<v;i++) visited[i] = 0;

    // two iterators enough , one for queue(i) and another for adding elements to queue(idx)
    int queue[(v*v)/2];
    int idx=0, i=0;
    
    queue[idx++] = start;
    
    printf("BFS : ");
    while(i != idx)
    {
        if(!(visited[queue[i]])) printf("%d ",queue[i]);
        visited[queue[i]] = 1;
        
        //append its unvisited children
        for(int k = 0; k < v; k++)
        {
            if(arr[queue[i]][k] && !(visited[k]))
            {
                queue[idx++] = k;
            }
        }
        i++;
    }
}

int main(void)
{
    int v;
    
    printf("Enter no of Vertices : ");
    scanf("%d",&v);

    int arr[v][v];
    for(int i=0;i<v;i++) for(int j=0;j<v;j++) arr[i][j] = 0;

    int e;
    printf("Enter no of Edges : ");
    scanf("%d",&e);
    
    for(int i=0;i<e;i++)
    {
        printf("_ to _  : ");
        int n,m; scanf("%d %d",&n,&m);
        insert(v,arr,n,m);
    }

    int visited[v];
    for(int i=0;i<v;i++) visited[i] = 0; 

    printf("\nDFS : ");
    dfs(0,v,arr,visited);

    printf("\n");

    bfs(v,arr,0);

    return 0;
}
