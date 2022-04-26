#include <stdio.h>
#include <stdlib.h> 

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insertion_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(arr[j]<arr[j-1]) swap(&arr[j],&arr[j-1]);
            else break;
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

    insertion_sort(arr,n);

    printf("\nSorted Array : ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);

    return 0;
}