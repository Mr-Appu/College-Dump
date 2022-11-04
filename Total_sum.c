#include <stdio.h>
#include <unistd.h>

//Total Sum
int main(void) 
{
    printf("Enter Array Size : ");
    int n; scanf("%d",&n);
    
    printf("Enter Array : ");
    int arr[n];
    
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    
    int p[2];
    pipe(p);
    
    int id = fork();
    
    if(id == -1) {
        printf("Error !");
        return 0;
    }
    
    if(id) //Parent
    {
        int sum = 0;
        for(int i=0;i<(n/2);i++) sum += arr[i];
        
        printf("Parent Sum = %d\n",sum);
        write(p[1],&sum,sizeof(sum)); //Parent Sum to pipe
    }
    else //Child
    {
        int sum = 0;
        for(int i=(n/2);i<n;i++) sum += arr[i];
        
        printf("Child Sum = %d\n",sum);
        
        int copy = 0;
        read(p[0],&copy,sizeof(copy)); //Pipe to Child
        
        printf("Total Sum = %d\n",(copy+sum));
    }

    return 0;
}