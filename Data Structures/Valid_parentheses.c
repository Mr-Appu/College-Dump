#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
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

void push(char n)
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

char seek()
{
    if(isempty()) return '\0';
    else return top->data;
}

/*
Valid Parentheses
Example 1 : ([]) () -> Balanced 
Example 2 : ((])] -> Not Balanced 
*/

int main(void)
{
    char str[1000] = {'\0'}; 
    printf("Enter : ");
    scanf("%[^\n]s",str);

    for(int i=0;i<strlen(str);i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') push(str[i]);
        else if(str[i] == '}' && seek() == '{') pop();
        else if(str[i] == ']' && seek() == '[') pop();
        else if(str[i] == ')' && seek() == '(') pop();
    }

    if(isempty()) printf("Balanced \n");
    else printf("Not Balanced\n");

    return 0;
}
