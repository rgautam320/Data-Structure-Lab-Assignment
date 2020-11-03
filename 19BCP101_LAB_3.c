/* ------------------------- 19BCP101 -----------------------*/
/* ----------------------- Rajan Gautam ---------------------*/

//Checking whether the string is Palindrome or not
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 50
//Declaring the variables
char stack[CAPACITY];
int i, len; count = 0;
int top = -1;
//Defining Push and Pop Function
void push(char arg)
{
    top++;
    stack[top] = arg;
}
char pop()
{
    char c;
    c = stack[top];
    top--;
    return c;
}
//Writing on Main Function
int main()
{
    printf("Enter a String to Check\n");
    scanf("%s", stack);
    len = strlen(stack);
    //Pushing a string
    for(i = 0; i<len; i++)
    {
        push(stack[i]);
    }
    for(i = 0; i<len; i++)
    {
        if(stack[i]==pop())
        {
            count++;
        }
    }
    if(count == len)
    {
        printf("Given string is Palindrome\n");
    }
    else
    {
        printf("Given string is not Palindrome\n");
    }
    return 0;
}
