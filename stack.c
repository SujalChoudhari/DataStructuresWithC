#include <stdio.h>
#include <stdlib.h>s
int MAX_SIZE;
int* stack;
int top = -1;


int menu();

int peek();
int pop();
int push(int value);
int is_empty();
int is_full();

int main() {
	return menu();
}

int menu() {
	printf("Enter the size of Stack:\n>> ");

	scanf_s("%d", &MAX_SIZE);

	stack = (int*)calloc(MAX_SIZE, sizeof(int));

	printf("\nSTACK of size %d is created!\n", MAX_SIZE);
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
	return top == MAX_SIZE - 1;
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