#include <stdio.h>
#include <stdlib.h>

// maximaum size for the stack
int max_size;

// pointer to a dynamic allocated memory of stack
int* stack;

// index to the top most value
int top = -1;

/*
	Menu Driven program to use 
	stack as a datatype to store values.
*/
int menu();

/*
	Get the value at top.
	@return value at top
*/
int peek();

/*
	Delete the value at the top.
	@return 0 if failed and 1 if completed
*/
int pop();

/*
	Add a value at the top of the stack
	@param value to add it to the stack
	@return 0 if failed and 1 if completed
*/
int push(int value);

/*
	Check if stack is empty or not.
	@return 1 if empty.
*/
int is_empty();

/*
	Check if stack is full or not.
	@return 1 if stack is full
*/
int is_full();


int main() {
	return menu();
}

int menu() {
	printf("Enter the size of Stack:\n>> ");

	scanf_s("%d", &max_size);

	stack = (int*)calloc(max_size, sizeof(int));

	printf("\nSTACK of size %d is created!\n", max_size);
	while (1) {
		printf("\n\n1. Push\n2. Pop\n3. Top\n4. Quit\n>> ");
		int choice;
		scanf_s("%d", &choice);

		int value;
		switch (choice)
		{
		case 1:
			printf("\n Enter value:\n>> ");
			scanf_s("%d", &value);
			push(value);
			break;
		case 2:
			pop();
			break;
		case 3:
			if (!is_empty()) {
				value = peek();
				printf("\nValue at top is: %d", value);
			}
			else
				printf("STACK IS EMPTY");
			break;
		default:
			return 0;
			break;
		}

	}
}


int is_empty() {
	return top == -1;
}
int is_full() {
	return top == max_size - 1;
}

int peek() {
	return stack[top];
}

int pop() {
	if (is_empty()) {
		printf("STACK IS EMPTY");
		return 0;
	}
	else {
		top--;
		return 1;
	}
}

int push(int value) {
	if (is_full()) {
		printf("STACK IS FULL");
		return 0;
	}
	else {
		top++;
		stack[top] = value;
		return 1;
	}
}