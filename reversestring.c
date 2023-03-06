#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define n 1000
char stack[n];
int count = 0;
char output[n];
int top = -1;

void push(char c)                               //here you need to take one parameter of char as you passed str[i] as a character
{
    if (top == (n - 1))       //check if top 
    {
        printf("overflow");
    }
    else
    {
        char ch = c;    //now u will insert this in stack
        top++;
        stack[top] = ch;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("underflow");
    }
    else
    {
        output[count++] = stack[top--];
    }
}

int main()
{
    char str[1000];
    int i;
    printf("enter string u wanna reverse: ");
    gets(str);
    for (i = 0; i < strlen(str); i++)
    {
        push(str[i]);                                //here us defined the funtion to pass one argument
    }
    for (i = 0; i < strlen(str); i++)
    {
        pop();
    }
    for (i = 0; i < strlen(str); i++)
    {
        printf("%c", output[i]);
    }

    return 0;
}