#include <stdio.h>
#include <stdlib.h>

int n; // Dynamic Size

void insert(int *arr,int size)
{
  if(n == size) {printf("\nArray is FULL\n");return;}
  else
  {
    int pos = 0;
    printf("Enter pos : ");
    scanf("%d",&pos);

    if(pos > n){printf("\nOut of bounds\n");return;}
    else
    {
      n++;
      int data = 0;
      printf("Enter No : ");
      scanf("%d",&data);
      for(int i=n;i>pos;i--) // Shifting 
      {
        arr[i] = arr[i-1];
      }

      arr[pos] = data;
    }
  }
  return;
}

void delete(int *arr)
{
  if(n == 0) {printf("\nArray is EMPTY\n");return;}
  else
  {
    int data = 0;
    printf("Enter No : ");
    scanf("%d",&data);

    for(int i=0;i<n;i++)
    {
      if(data == arr[i])
      {
        for(int j=i;j<n-1;j++) arr[j] = arr[j+1];
        n--;
        break;
      }
    }

    return;
  }
}

void search(int *arr)
{
  int flag = 1;
  int data = 0;
  printf("Enter No : ");
  scanf("%d",&data);

  for(int i=0;i<n;i++)
  {
    if(data == arr[i])
    {
      flag = 0;
      printf("Index : %d\n",i);
      return;
    }
  }

  if(flag) printf("No %d Not found\n",data);
  return;
} 

void display(int *arr)
{
  printf("\nArray : ");
  for(int i=0;i<n;i++) printf("%d ",arr[i]);
  printf("\n");
}

int main(void)
{
  int size;
  printf("Enter Array Size : ");
  scanf("%d",&size);

  int arr[size]; 
  int c = 1;

  while(c != 0)
  {
    printf("\n1.Insertion 2.Deletion 3.Search 4.Display 5.Exit\n");
    printf("Enter : ");
    
    scanf("%d",&c);

    switch(c)
    {
      case 1:
        insert(arr,size);
        break;
      case 2:
        delete(arr);
        break;
      case 3:
        search(arr);
        break;
      case 4:
        display(arr);
        break;
      case 5:
        c = 0;
        break;
      default:
        printf("\nEnter Valid Option\n");
        break;
    }
  }
  return 0;
}