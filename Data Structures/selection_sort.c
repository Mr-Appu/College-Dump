#include <stdio.h>
#include <stdlib.h> 

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int small = i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<arr[small]) small = j;
        }  
        swap(&arr[i],&arr[small]);
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

    selection_sort(arr,n);

    printf("\nSorted Array : ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);

    return 0;
}
