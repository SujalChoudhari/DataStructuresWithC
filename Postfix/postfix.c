#include <stdio.h>
#include "stack.h"
#include <string.h>

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

// check if the given char is a ([{
int is_opening_bracket(char);
// check if the given char is a )]}
int is_closing_bracket(char);

// converter
int convert(char *input, char *postfixed);

// evaluate
int evaluate(char *input);

int main()
{

    char input[MAX_SIZE];

    char postfixed[MAX_SIZE];

    printf(">>> ");
    scanf("%s", input);
    convert(input, postfixed);

    printf("%s \n", postfixed);

    int res = evaluate(postfixed);
    printf("Result is %d\n",res);
}

int evaluate(char *input)
{
    printf("Postfix expression: %s\n", input);
    int valueStack[100];
    int top = -1;
    int len = strlen(input);
    int operand1, operand2;
    for (int i = 0; i < len; ++i)
    {
        if (!is_operator(input[i], "^*/+-"))
        {
            printf("Enter value for %c: ", input[i]);
            scanf("%d", &valueStack[++top]);
        }
        else
        {
            operand2 = valueStack[top--];
            operand1 = valueStack[top--];
            switch (input[i])
            {
            case '+':
                valueStack[++top] = operand1 + operand2;
                break;
            case '-':
                valueStack[++top] = operand1 - operand2;
                break;
            case '*':
                valueStack[++top] = operand1 * operand2;
                break;
            case '/':
                valueStack[++top] = operand1 / operand2;
                break;
            }
        }
    }

    return valueStack[top];
}

int convert(char *input, char *postfixed)
{
    char *stack = (char *)calloc(MAX_SIZE, sizeof(char));
    int top = -1;

    const char *PRECEDENCE = "^*/+-";
    int counter = 0;
    int postfixed_index = 0;
    while (input[counter] != '\0' && counter < MAX_SIZE)
    {
        char current_token = input[counter];
        if (is_operator(current_token, PRECEDENCE)) // operator
        {

            while (
                !is_empty(top) && !is_opening_bracket(peek(stack, top)) && is_first_of_higher_precedence(peek(stack, top), current_token, PRECEDENCE))
            {
                postfixed[postfixed_index] = peek(stack, top);
                postfixed_index++;
                pop(stack, &top);
            }

            push(stack, &top, MAX_SIZE, current_token);
        }
        else if (is_opening_bracket(current_token)) // start of a parenthesis
        {
            push(stack, &top, MAX_SIZE, current_token);
        }
        else if (is_closing_bracket(current_token)) // end of paren
        {
            while (!is_opening_bracket(peek(stack, top)))
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

    while (!is_empty(top))
    {
        postfixed[postfixed_index] = peek(stack, top);
        postfixed_index++;
        pop(stack, &top);
    }

    postfixed[postfixed_index] = '\0';

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

int is_opening_bracket(char cha)
{
    return cha == '(' || cha == '[' || cha == '{';
}

int is_closing_bracket(char cha)
{
    return cha == '(' || cha == '[' || cha == '{';
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