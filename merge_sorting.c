#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l,int mid, int r)
{
    int s_arr[r-l+1]; //creating an Array 
    
    int i = l,j = mid+1;
    int index = 0;
    while(i<=mid || j<=r)
    {
        if(i == mid+1) s_arr[index++] = arr[j++];
        else if(j == r+1) s_arr[index++] = arr[i++];
        else if(arr[i] <= arr[j]) s_arr[index++] = arr[i++];
        else if(arr[j] < arr[i]) s_arr[index++] = arr[j++];
    }
    index = 0;
    
    for(i=l;i<=r;i++) arr[i] = s_arr[index++]; //Copying newly created Array to Old Array
}

void merge_sort(int arr[],int l,int r)
{
    if(l == r) return;
    
    int m = (l+r)/2;
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);
    
    merge(arr,l,m,r);
}


int main()
{
    int n;
    
    printf("Enter Size : ");
    scanf("%d",&n);
    
    int arr[n];
    
    printf("Enter Arrary : ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    
    merge_sort(arr,0,n-1);
    
    printf("\nAfter Sorting, Array : ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);

    return 0;
}