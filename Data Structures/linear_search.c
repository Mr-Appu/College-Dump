#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
    int n;

    printf("Enter Array Size : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter Array : ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    while(1)
    {
        int data; 

        printf("Enter the No you wanna Search : ");
        scanf("%d",&data);

        int flag = 1;

        /*Algorithm*/
        for(int i=0;i<n;i++)
        {
            if(arr[i] == data)
            {
                printf("No Found at index %d\n",i);
                flag = 0;
                break;
            }
        }

        if(flag) printf("No Not Found\n");
    }

    return 0;
}
