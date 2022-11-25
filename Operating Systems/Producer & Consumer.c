#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

const int MAX = 1;
int arr[10];
int size = -1;

pthread_mutex_t x;
pthread_cond_t c1; // Max 
pthread_cond_t c2; // Min

void random_sleep()
{
    int n = rand()%5;
    sleep(n);
}

void producer()
{
    random_sleep();
    pthread_mutex_lock(&x);
    
    if(size == MAX-1) {
        pthread_cond_wait(&c1,&x);
    }
    
    int data = rand()%10;
    printf("Enter data : %d\n",data); 
    
    arr[++size] = data;
    printf("Array size : %d\n",size);
    
    pthread_cond_signal(&c2);
    pthread_mutex_unlock(&x);
}

void consumer()
{
    random_sleep();
    pthread_mutex_lock(&x);
    
    if(size == -1) {
        pthread_cond_wait(&c2,&x);
    }
    
    printf("Data : %d\n",arr[size--]); 
    
    pthread_cond_signal(&c1);
    pthread_mutex_unlock(&x);
}

int main()
{
    pthread_t t1,t2,t3,t4;
    
    pthread_create(&t1,NULL,(void*)consumer,NULL);
    pthread_create(&t2,NULL,(void*)producer,NULL);
    pthread_create(&t3,NULL,(void*)producer,NULL);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    
    // pthread_create(&t4,NULL,(void*)consumer,NULL);
    // pthread_join(t4,NULL);
    
    return 0;
}
