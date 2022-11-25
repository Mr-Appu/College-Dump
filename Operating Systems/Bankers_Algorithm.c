#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter n : ");
    int n; scanf("%d",&n);
    
    //Assuming available resources = 3

    int allocation[n][3];
    int max[n][3];
    int need[n][3];
    
    printf("Resources : ");
    int a,b,c; scanf("%d %d %d",&a,&b,&c);
    
    for(int i=0;i<n;i++)
    {
        printf("P_id : %d\n",i);
        printf("Allocation : ");
        scanf("%d %d %d",&allocation[i][0],&allocation[i][1],&allocation[i][2]);
        printf("Max : ");
        scanf("%d %d %d",&max[i][0],&max[i][1],&max[i][2]);
        
        need[i][0] = max[i][0] - allocation[i][0];
        need[i][1] = max[i][1] - allocation[i][1];
        need[i][2] = max[i][2] - allocation[i][2];
        
        a -= allocation[i][0];
        b -= allocation[i][1];
        c -= allocation[i][2];
    }
    
    int vis[n];
    for(int i=0;i<n;i++) vis[i] = 0;
    
    while(1)
    {
        int id = -1;
        
        for(int i=0;i<n;i++)
        {
            if(a >= need[i][0] && b >= need[i][1] && c >= need[i][2] && !vis[i])
            {
                id = i;
            }
        }
        
        if(id == -1) return 0;
        
        vis[id] = 1;
        
        printf("Id - %d\n",id);
        a += allocation[id][0];
        b += allocation[id][1];
        c += allocation[id][2];
    }

    return 0;
}










