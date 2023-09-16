#include "stack.h"
#include "queue.h"
int main()
{

	int choice = 0;
	while (1)
	{
		printf("STACK QUEUE!\n1. Use Stack\n2. Use Queue\n3. Quit\n>> ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			stack_menu();
			break;
		case 2:
			queue_menu();
			break;
		default:
			return 0;
		}
	}
	return stack_menu();
}