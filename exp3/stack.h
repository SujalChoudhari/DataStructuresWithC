#include <stdio.h>
#include <stdlib.h>

/*
	Get the value at top.
	@return value at top
*/
char peek(char *stack, int top);

/*
	Delete the value at the top.
	@return 0 if failed and 1 if completed
*/
int pop(char *stack, int *top);

/*
	Add a value at the top of the stack
	@param value to add it to the stack
	@return 0 if failed and 1 if completed
*/
int push(char *stack, int *top, int max_size, char value);

/*
	Check if stack is empty or not.
	@return 1 if empty.
*/
int is_empty(int top);

/*
	Check if stack is full or not.
	@return 1 if stack is full
*/
int is_full(int top, int size);

/*
    Pretty print the stack
*/
void display(char *stack, int top);

int is_empty(int top)
{
	return top == -1;
}
int is_full(int top, int max_size)
{
	return top == max_size - 1;
}

char peek(char *stack, int top)
{
	return stack[top];
}

int pop(char *stack, int *top)
{
	if (is_empty(*top))
	{
		printf("STACK IS EMPTY");
		return 0;
	}
	else
	{
		(*top)--;
		return 1;
	}
}

int push(char *stack, int *top, int max_size, char value)
{
	if (is_full(*top, max_size))
	{
		printf("STACK IS FULL");
		return 0;
	}
	else
	{
		(*top)++;
		stack[*top] = value;
		return 1;
	}
}

void display(char *stack, int top)
{
	if (is_empty(top))
	{
		printf("STACK IS EMPTY");
	}
	else
	{
		printf("Stack: [");
		for (int i = top; i >= 0; i--)
		{
			printf("%c ", stack[i]);
		}
		printf("]\n");
	}
}