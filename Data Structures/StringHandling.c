/*
Write a C program to read a sentence from the user and output the following:
i) The length of each word.
ii) If a word contains any special characters or digits other than lower and
upper case letters, then it should also be reported as YES, otherwise NO.
iii) The program should first print the sentence accepted from the user, and
then print the word, its length and character check status line by line for
each word. See the example output below.
Example
Input:
The quick brown fox! jumps ov3r the lazy Dog!
Output:
Sentence is : The quick brown fox! jumps ov3r the lazy Dog!
The - 3 - NO
quick - 5 - NO
brown - 5 - NO
fox! - 4 - YES
jumps - 5 - NO
ov3r - 4 - YES
the - 3 - NO
lazy - 4 - NO
Dog! - 4 - YES
*/

#include <stdio.h>
#include <string.h>

int isalpha(int c);

int main(void)
{
    char string[500] = "";
    printf("Enter String : ");
    scanf("%[^\n]s", string);
    strcat(string," ");//This one concatenates blank space to last element so that according to else if condition last element gets printed
    printf("\n");

    printf("Sentence is : %s\n\n",string);

    int n=0; //Variable used to Calculate No of words
    int si=0; //Variable used to store starting index of each word
    int arr[strlen(string)];

    for(int i=0;i<strlen(string);i++)
    {
        if(string[i] != ' ')
        {
            printf("%c",string[i]);
            n += 1;
            arr[i] = isalpha(string[i]);
        }
        else if(string[i] == ' ' && string[i+1] != ' ')
        {
            printf(" - %d - ",n);
            int f=0;
            n=0; //It gets reseted , so that it stores no of words in next word
            for(int j=si;j<i;j++)
            {
                if(arr[j] == 0)
                {
                    f = 1;
                    break;
                }
            }
            if(f == 1)
                printf("YES\n");
            else
                printf("NO\n");
            si = i+1; //Stores starting index of next word
        }
    }

    return 0;
}

int isaplha(int c)
{
    if((c >= 65 && c <= 90 ) || (c >= 97 && c <= 122))
       {
           return 1;
       }
    else
        {
            return 0;
        }
}
