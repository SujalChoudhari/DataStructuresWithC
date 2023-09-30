#include <stdio.h>
#include "stack.h"

#define MAX_SIZE 20

/*
    Check if the character is an operator
*/
int is_operator(char ch, char *precedence);

/*
    Compares operators
    @param first - the first operator
    @param second - the second operator to compare
    @returns 1 if the first is having high precedence.
*/
int is_first_of_higher_precedence(char first, char second, char *precedence);

int main()
{
    const char *PRECEDENCE = "^*/+-";

    char *stack = (char *)calloc(MAX_SIZE, sizeof(char));
    int top = -1;

    char input[MAX_SIZE];

    char postfixed[MAX_SIZE];
    int postfixed_index = 0;
    printf(">>> ");
    scanf("%s", input);

    int counter = 0;
    while (input[counter] != '\0' && counter < MAX_SIZE)
    {
        char current_token = input[counter];
        if (is_operator(current_token, PRECEDENCE)) // operator
        {

            while (!is_empty(top) && peek(stack,top) != '(' && is_first_of_higher_precedence(peek(stack, top), current_token, PRECEDENCE))
            {
                postfixed[postfixed_index] = peek(stack, top);
                postfixed_index++;
                pop(stack, &top);
            }

            push(stack, &top, MAX_SIZE, current_token);
        }
        else if (current_token == '(') // start of a parenthesis
        {
            push(stack, &top, MAX_SIZE, current_token);
        }
        else if (current_token == ')') // end of paren
        {
            while (peek(stack, top) != '(')
            {
                postfixed[postfixed_index] = peek(stack, top);
                postfixed_index++;

                pop(stack, &top);
            }
            pop(stack, &top); // remove the open_paren
        }
        else //  character
        {
            postfixed[postfixed_index] = current_token;
            postfixed_index++;
        }
        counter++;
    }

    while(!is_empty(top)){
        postfixed[postfixed_index] = peek(stack,top);
        postfixed_index++;
        pop(stack,&top);
    }

    postfixed[postfixed_index] = '\0';
    printf("%s \n", postfixed);
    display(stack, top);
    return 0;
}

int is_operator(char ch, char *precedence)
{
    for (int i = 0; i < sizeof(precedence); i++)
    {
        if (ch == precedence[i])
            return 1;
    }
    return 0;
}

int is_first_of_higher_precedence(char first, char second, char *precedence)
{
    int index, index2;
    for (int i = 0; i < sizeof(precedence) / sizeof(char); i++)
    {
        if (first == precedence[i])
            index = i;
        if (second == precedence[i])
            index2 = i;
    }

    return index < index2;
}