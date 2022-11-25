#include <stdio.h>
#include <stdlib.h>

//First Fit

int main(void)
{
    printf("Enter no of Block : ");
    int b; scanf("%d",&b);

    printf("Enter : ");
    int block[b];
    for(int i=0;i<b;i++) scanf("%d",&block[i]);

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
                printf("P_ID %d ==> Block_No : %d , Size : %d\n",i+1,j+1,block[j]);
                vis[j] = 1;
                flag = 0;
                break;
            }
        }
        if(flag) printf("P_ID %d : Not Allocated\n",i+1);
    }

    return 0;
}
