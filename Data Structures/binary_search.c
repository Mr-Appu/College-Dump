#include <stdio.h>
#include <stdlib.h> 

int arr[1000];

int binary_search(int data,int l, int r)
{
    if(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid] < data) binary_search(data,mid+1,r);
        else if(arr[mid] > data) binary_search(data,l,mid-1);
        else return 1;
    }
    else return 0;
}

int main(void)
{
    int n;

    printf("Enter Array Size : ");
    scanf("%d",&n);

    printf("Enter Array : ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    while(1)
    {
        int data; 

        printf("Enter the No you wanna Search : ");
        scanf("%d",&data);

        if(binary_search(data,0,n-1)) printf("Number Found\n");
        else printf("Number Not Found\n");
        
    }

    return 0;
}
