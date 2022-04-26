#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

char peek()
{
    if(isempty()) return '\0';
    else return top->data;
}

/*
Infix to Postfix

*/

int precedence(char c) // Function : Returns precedence of the operator  
{
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
    else return 0;
}


int main(void)
{
    char str[1000] = {'\0'}; 
    printf("Enter : ");
    scanf("%[^\n]s",str);

    printf("Postfix Expression : ");
    for(int i=0;i<strlen(str);i++)
    {
        if(isalnum(str[i])) printf("%c",str[i]); //if char equals to letter or no, print it
        else if(str[i] == '(') push('('); 
        else if(str[i] == ')')
        {
            while(peek() != '(') //pop all operator until ( is found 
            {
                printf("%c",peek());
                pop();
            }
            pop(); //remove ( from the stack
        }
        else
        {
            if(isempty()) push(str[i]); // if stack is empty push the operator 
            else if(precedence(str[i]) > precedence(peek())) push(str[i]); //Push if precedence is higher  
            else
            {
                while(!isempty() && precedence(str[i]) <= precedence(peek())) //
                {
                    printf("%c",peek()); //print and pop the operator until higher precedence is found
                    pop();
                }
                push(str[i]); 
            }
        }        
    }

    while(!isempty()) //Print and pop the operator until the stack is empty 
    {
        printf("%c",peek());
        pop();
    }

    return 0;
}
