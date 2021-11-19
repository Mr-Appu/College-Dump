/*
There are n ducks floating on a pond in a circle. The pond is also home for an alligator with a fondness for ducks. 
Beginning at a particular position (duck number 1) the alligator counts around the circle and eats every mth duck (the circle closing as ducks are eaten). 

For example, when n=8, and m=4.
The first duck is fifth on the menu, the second is fourth, etc. The sequence 5, 4, 6, 1, 3, 8, 7, 2 of order of consumption completely describes the alligator’s menu. 

Write a program which prints out the order of consumption of the ducks given n and m. Use functions for sub operations to make the program modular.

Sample Input/Output:
n = 8
m = 4
Order of Consumption: 5 4 6 1 3 8 7 2
*/

#include <stdio.h>

void order(int[],int[],int,int,int,int,int);

int main(void)
{
    printf("Enter n m : ");
    int n=0,m=0;
    scanf("%d %d",&n,&m);
    int duck[1+n];
    int arr[1+n];
    for(int i=1;i<n+1;i++)
    {
        duck[i] = i;
    }
    order(arr,duck,1,n,m,1,n);

    //Printing Menu
    printf("Menu : ");
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(arr[j] == i)
            {
                printf("%d ",j);
                break;
            }
        }
    }

    return 0;
}

void order(int arr[],int duck[],int i,int n,int m,int index, int fixedn)
{
    if ( i == fixedn+1)
    {
        return;
    }
    index = (index +m-1)%n;
    if (index == 0)
        index = n;
    arr[i] = duck[index];

    for(int k=index;k<n;k++)
    {
        int temp = duck[k+1];
        duck[k+1] = duck[k];
        duck[k] = temp;
    }

    order(arr,duck,i+1,n-1,m,index,fixedn);
}

