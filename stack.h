#include <stdio.h>
#include <stdlib.h>

/*
	Menu Driven program to use
	stack as a datatype to store values.
*/
int stack_menu();

/*
	Get the value at top.
	@return value at top
*/
int peek(int *stack, int top);

/*
	Delete the value at the top.
	@return 0 if failed and 1 if completed
*/
int pop(int *stack, int *top);

/*
	Add a value at the top of the stack
	@param value to add it to the stack
	@return 0 if failed and 1 if completed
*/
int push(int *stack, int *top, int max_size, int value);

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

void display(int *stack, int top);

int stack_menu()
{

	// maximaum size for the stack
	int max_size;

	// pointer to a dynamic allocated memory of stack
	int *stack;

	// index to the top most value
	int top = -1;

	printf("Enter the size of Stack:\n>> ");

	scanf("%d", &max_size);

	stack = (int *)calloc(max_size, sizeof(int));

	printf("\nSTACK of size %d is created!\n", max_size);
	while (1)
	{
		printf("\n\n1. Push\n2. Pop\n3. Top\n4. Display\n5.Quit\n>> ");
		int choice;
		scanf("%d", &choice);

		int value;
		switch (choice)
		{
		case 1:
			printf("\n Enter value:\n>> ");
			scanf("%d", &value);
			push(stack, &top, max_size, value);
			break;
		case 2:
			pop(stack, &top);
			break;
		case 3:
			if (!is_empty(top))
			{
				value = peek(stack, top);
				printf("\nValue at top is: %d", value);
			}
			else
				printf("STACK IS EMPTY");
			break;
		case 4:
			display(stack, top);
			break;
		default:
			return 0;
			break;
		}
	}
}

int is_empty(int top)
{
	return top == -1;
}
int is_full(int top, int max_size)
{
	return top == max_size - 1;
}

int peek(int *stack, int top)
{
	return stack[top];
}

int pop(int *stack, int *top)
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

int push(int *stack, int *top, int max_size, int value)
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

void display(int *stack, int top)
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
			printf("%d ", stack[i]);
		}
		printf("]\n");
	}
}