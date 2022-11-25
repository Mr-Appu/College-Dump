#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


// r -> last<idx>+1 

int partition(int arr[],int l,int r)
{
    int pivot = arr[l];
    int i = l;
    int j = r;

    while(i<j)
    {
        do i++; while(arr[i] <= pivot);
        do j--; while(arr[j] > pivot);
        if(i < j) swap(&arr[i],&arr[j]);
    }
    swap(&arr[l],&arr[j]);
    // for(int i=0;i<7;i++) printf("%d ",arr[i]);
    // printf("\n");
    return j;
}

void quick_sort(int arr[],int l, int r)
{
    if(l>=r) return;

    int p = partition(arr,l,r);
    quick_sort(arr,l,p);
    quick_sort(arr,p+1,r);
}

int main(void)
{
    int n; 

    printf("Enter Array Size : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter Array : ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    
    quick_sort(arr,0,n);

    printf("\nAfter Sorting, Array : ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);

    return 0;
}
