#include <stdio.h>
#include <stdlib.h> 

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j] > arr[j+1]) swap(&arr[j],&arr[j+1]);
        }
    }
}

int main(void)
{
    int n;

    printf("Enter Array Size : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter Array : ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("\nArray : ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);

    bubble_sort(arr,n);

    printf("\nSorted Array : ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);

    return 0;
}
