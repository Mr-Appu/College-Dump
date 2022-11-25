#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;
node *top;

// Functions 
int isempty()
{
    if(top == NULL) return 1;
    else return 0;
}

void push(int n)
{
    node *new = malloc(sizeof(node));
    new->data = n;
    if(isempty())
    {
        top = new;
        new->next = NULL;
    }
    else
    {
        new->next = top;
        top = new;
    }
}

void pop()
{
    if(isempty()) {printf("Stack is Empty\n");return;}
    else top = top->next;
}

int peek()
{
    if(isempty()) return '\0';
    else return top->data;
}

/*
Postfix
Example 1 : 23+ -> 5(2+3)
Example 2 : 32- -> 1(3-2) 
*/

int main(void)
{
    char str[1000] = {'\0'}; 
    printf("Enter Expression : ");
    scanf("%[^\n]s",str);

    for(int i=0;i<strlen(str);i++)
    {
        int digit = str[i] - '0';
        if(digit >= 0 && digit <= 9) push(digit);
        else
        {
            int b = peek(); pop();
            int a = peek(); pop();

            if(str[i] == '+') push(a+b);
            else if(str[i] == '-') push(a-b);
            else if(str[i] == '*') push(a*b);
            else if(str[i] == '/') push(a/b);
        }
    }

    printf("Answer : %d\n",peek());

    return 0;
}
