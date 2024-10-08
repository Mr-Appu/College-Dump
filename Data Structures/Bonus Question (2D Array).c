/* 
A list of numbers must be organized into a table which reads by columns, left to right. The number of columns is fixed. The list of numbers fills out the table column by column.
All rows must be filled except for the last row. The empty spaces in the last row should be at the right end of the row.

Example:
LIST	 : 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17
COLUMNS: 5
TABLE  :  1 5  9 12 15
	        2 6 10 13 16
	        3 7 11 14 17
	        4 8  0  0  0

Input/Output:
First read a list of numbers. Then read the number of columns ‘n’ infinitely until zero is entered. 
For each value of ‘n’ display the sum of numbers in each row.(You need not print the table)

Sample I/O:
Enter the list of numbers: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
Enter the number of columns: 5
Row Sums: 42 47 52 12
************************************************
Enter the number of columns: 17
Row Sums: 153
************************************************
Enter the number of columns: 2
Row Sums: 11 13 15 17 19 21 23 25 9
*************************************************
Enter the number of columns: 0

*/

#include <math.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    printf("Enter List Size : ");
    scanf("%d",&n);

    int list[n];
    printf("Enter the List of numbers : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    printf("\n");

    while( 1 == 1)
    {
        int c=0;
        printf("Enter the number of Column : ");
        scanf("%d",&c);

        if(c == 0)
        {
            break;
        }

        float nf = n;
        int r = ceil(nf/c);
        int no_of_zeros = (r*c) - n;
        int matrix[r][c];

        int k = 0;
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<r;j++)
            {
                if( j == r-1 && i > (c-1-no_of_zeros))
                {
                    matrix[j][i] = 0;
                }
                else
                {
                    matrix[j][i] = list[k];
                    k += 1;
                }
            }
        }


        printf("\n Matrix\n");
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                printf("%2d ",matrix[i][j]);
            }
            printf("\n");
        }

        printf("\nRow Sum : ");
        for(int i=0;i<r;i++)
        {
            int sum = 0;
            for(int j=0;j<c;j++)
            {
                sum += matrix[i][j];
            }

            printf("%d ",sum);
        }
        printf("\n\n");
    }

    return 0;
}
