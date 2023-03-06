#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define max 100
float stack[max];
int top = -1;

void push(float stack[], float val);    //this is only funtion declaration you haven't def
float pop(float stack[]);                     //this function also need to define and have the return type of float as its returning the popped value which is of float type
float prefixexp(char exp[]);

//you have to define the push operation of stack
void push(float stack[], float val)
{
    if(top == max-1)
    {
        printf("Overflow conditon occured");
        return;
    }
    stack[++top]= val;
}
//define the pop operation oas well
float pop(float stack[])
{
    if(top == -1)
    {
        printf("Underflow condition occured");
        return -1;
    }
    return stack[top--]; 
}
int main()
{
    float val;
    char exp[100];
    printf("enter any prefix expression: ");
    gets(exp);
    val = prefixexp(exp);                      
    printf("the prefix expression solution is %f", val);
    return 0;
}
float prefixexp(char exp[])
{
    int i, len = strlen(exp);               ///strlen() is used to get the length of the character array
    float op1, op2, value;
    for (i = (len - 1); i >= 0; i--)
    {
        if (isdigit(exp[i]))
        push(stack, (float)(exp[i] - '0'));         //here push in stack
    else
    {
        op1 = pop(stack);           
        op2 = pop(stack);
        switch (exp[i])
        {
        case '+':
            value = op1 + op2;
            break;
        case '-':
            value = op1 - op2;
            break;
        case '*':
            value = op1 * op2;
            break;
        case '/':
            value = op1 / op2;
            break;
        }
        push(stack, value);
    }
    }
    return pop(stack);
}