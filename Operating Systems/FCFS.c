#include <stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    printf("Enter no of process : ");
    int n; scanf("%d",&n);
    
    int arr[n][3]; // id , burst_time , arrival_time
    
    for(int i=0;i<n;i++)
    {
        printf("Enter Burst and Arrival time for %d Process : ",i+1);
        scanf("%d %d",&arr[i][1],&arr[i][2]);
        arr[i][0] = i+1;
    }
    
    
    // FCFS
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j][2] > arr[j+1][2]) 
            {
                swap(&arr[j][0],&arr[j+1][0]);
                swap(&arr[j][1],&arr[j+1][1]);
                swap(&arr[j][2],&arr[j+1][2]);
            }
        } 
    }
    
    int tt = 0;
    for(int i=0;i<n;i++)
    {
        printf("P%d -> %d to %d\n",arr[i][0],tt,tt+arr[i][1]);
        tt += arr[i][1]; 
    }
    
    return 0;
}
