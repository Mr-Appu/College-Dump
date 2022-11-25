#include <stdio.h>
#include <stdlib.h>

const int MAX = 10000007;

void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void)
{
    printf("Enter no of process : ");
    int n; scanf("%d",&n);
    
    int arr[n][3]; // id , burst_time , arrival_time
    int vis[n];
    
    for(int i=0;i<n;i++)
    {
        printf("Enter Burst and Arrival time for %d Process : ",i+1);
        scanf("%d %d",&arr[i][1],&arr[i][2]);
        arr[i][0] = i+1;
        vis[i] = 0;
    }
    
    
    // SJF
    
    int tt = 0,c = 0;

    while(c<n)
    {
        int j = -1;
        int j_max = MAX;
        for(int i=0;i<n;i++)
        {
            if(arr[i][2] <= tt && !vis[i])
            {
                if(j_max > arr[i][1])
                {
                    j = i;
                    j_max = arr[i][1];
                }
            }
        }
        
        printf("%dP -> %d to %d\n",arr[j][0],tt,tt+arr[j][1]);
        vis[j] = 1; c++; tt += arr[j][1];
    }
    
    return 0;
}
