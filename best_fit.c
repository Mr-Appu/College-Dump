#include <stdio.h>
#include <stdlib.h>

//Best Fit

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int n, int arr[n],int id[n])
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j],&arr[j+1]);
                swap(&id[j],&id[j+1]);
            }
        }
    }
}

int main(void)
{
    printf("Enter no of Block : ");
    int b; scanf("%d",&b);

    printf("Enter : ");
    int block[b];
    int block_id[b];

    for(int i=0;i<b;i++) {
        scanf("%d",&block[i]);
        block_id[i] = i+1;
    }

    sort(b,block,block_id);

    printf("Enter no of Process : ");
    int p; scanf("%d",&p);

    printf("Enter : ");
    int process[p];
    for(int i=0;i<p;i++) scanf("%d",&process[i]);

    int vis[b];
    for(int i=0;i<b;i++) vis[i] = 0;

    for(int i=0;i<p;i++)
    {
        int flag = 1;
        for(int j=0;j<b;j++)
        {
            if(!vis[j] && process[i] <= block[j]) {
                printf("P_ID %d ==> Block_No : %d , Size : %d\n",i+1,block_id[j],block[j]);
                vis[j] = 1;
                flag = 0;
                break;
            }
        }
        if(flag) printf("P_ID %d : Not Allocated\n",i+1);
    }

    return 0;
}