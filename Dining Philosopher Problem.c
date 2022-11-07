// https://onlinegdb.com/0uYXBpIZ2

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t x[100];
pthread_cond_t c[100];

int Fork[100];

int n;

/*
    Logic
    
    All philosophers except last one picks left fork first and then right fork

*/

void philosopher(int *ptr)
{
    int id = *ptr;
    
    int i = *ptr; //left
    int j = (i+1)%n; //right
    
    if(i == n-1) // Last philosopher
    {
        int temp = i;
        i = j;
        j = temp;
    }
    
    //printf("%d -> %d %d\n",id,i,j);
    
    pthread_mutex_lock(&x[i]);
    if(Fork[i] == 1) pthread_cond_wait(&c[i],&x[i]);
    Fork[i] = 1;
    pthread_mutex_unlock(&x[i]);
    
    pthread_mutex_lock(&x[j]);
    if(Fork[j] == 1) pthread_cond_wait(&c[j],&x[j]);
    Fork[j] = 1;
    pthread_mutex_unlock(&x[j]);
    
    printf("Philosopher - %d Eating\n",id);
    sleep(rand()%5);
    
    pthread_mutex_lock(&x[i]);
    Fork[i] = 0;
    pthread_cond_signal(&c[i]);
    pthread_mutex_unlock(&x[i]);
    
    pthread_mutex_lock(&x[j]);
    Fork[j] = 0;
    pthread_cond_signal(&c[j]);
    pthread_mutex_unlock(&x[j]);
    
    printf("Philosopher - %d Finished Eating\n",id);
}

int main(void)
{
    printf("Enter no of philosophers : ");
    scanf("%d",&n);
    
    int arr[n];
    pthread_t t[n];
    
    for(int i=0;i<n;i++)
    {
        arr[i] = i;
        pthread_create(&t[i],NULL,(void*)philosopher,(int*)&arr[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        pthread_join(t[i],NULL);
    }

    return 0;
}
