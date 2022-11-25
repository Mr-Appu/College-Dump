#include <stdio.h>
#include <stdlib.h>

#define infi 100000

void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int v, int arr[v][v],int a,int b,int cost) {arr[a][b] = cost; arr[b][a] = cost;return;}

void display(int v,int arr[v][v])
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++) printf("%d ",arr[i][j]);
        printf("\n");
    }
}

int* prims(int v,int arr[v][v])
{
    int visited[v];
    int cost[v];
    int *parent = malloc(v*sizeof(int));

    for(int i=0;i<v;i++)
    {
        visited[i] = 0;
        cost[i] = infi;
        parent[i] = -1;
    }

    cost[0] = 0; // Starting Index
    int start = 0;

    while(start != -1)
    {
        visited[start] = 1;
        for(int i=0;i<v;i++)
        {
            if(arr[start][i] && !visited[i])
            {
                int c = arr[start][i];
                if(c < cost[i])
                {
                    cost[i] = c;
                    parent[i] = start;
                }
            }
        }
        //selecting next node 
        int node = -1;
        int c = infi;
        
        for(int i=0;i<v;i++)
        {
            if(cost[i] < c && !visited[i])
            {
                c = cost[i];
                node = i;
            }
        }

        start = node;
    }

    return parent;
}

int is_cycle(int start,int v,int arr[v][v])
{
    //using bfs
    int visited[v];
    for(int i=0;i<v;i++) visited[i] = 0;

    int queue[(v*v)/2];
    int idx=0, i=0;
    
    queue[idx++] = start;
    
    while(i != idx)
    {
        if(visited[queue[i]]) return 1;
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

    return 0;
}


int cyclic_detection(int v,int arr[v][v])
{
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            if(arr[i][j])
            {
                int k = is_cycle(i,v,arr);
                if(k) return 1;
            }
        }
    }
    return 0;
}

void kruskal(int v,int arr[v][v])
{
    int cost[1000],a[1000],b[1000]; // a->starting vertex b->ending vertex
    int index = 0;

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(arr[i][j])
            {
                cost[index] = arr[i][j];
                a[index] = i;
                b[index] = j;
                index++;
            }
        }
    }

    //sorting cost , a , b
    for(int i=0;i<index;i++)
    {
        for(int j=0;j<(index-1-i);j++)
        {
            if(cost[j] > cost[j+1])
            {
                swap(&cost[j],&cost[j+1]);
                swap(&a[j],&a[j+1]);
                swap(&b[j],&b[j+1]);
            }
        }
    }

    int tree[v][v];

    for(int i=0;i<v;i++) for(int j=0;j<v;j++) tree[i][j] = 0;
    

    for(int i=0;i<index;i++)
    {
        tree[a[i]][b[i]] = cost[i];
        if(cyclic_detection(v,tree)) tree[a[i]][b[i]] = 0;
    }

    printf("\nTree : \n");
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++) printf("%d ",tree[i][j]);
        printf("\n");
    }
    printf("\n");
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
        printf("_ to _ : ");
        int x,y; scanf("%d %d",&x,&y);
        printf("cost : ");
        int c; scanf("%d",&c); 
        insert(v,arr,x,y,c);
    }

    printf("\nGraph : \n");
    display(v,arr);

    int *tree = prims(v,arr); 

    printf("\nParent : \n");
    for(int i=0;i<v;i++) printf("%d - > %d\n",i,tree[i]);

    kruskal(v,arr);    

    return 0;
}
