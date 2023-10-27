#include <stdio.h>
#include <stdlib.h>

void queue_menu();
int enqueue(int *queue, int *front, int *rear, int size, int data);
int dequeue(int *queue, int *front, int *rear, int size);
int getFront(int *queue, int front);
int getRear(int *queue, int rear);
int isQueueEmpty(int back_or_top);
int isQueueFull(int rear, int front, int size);
void displayQueue(int *queue, int front, int rear, int size);

void queue_menu()
{
    int max_size;
    int *queue;
    int front = -1, rear = -1;

    printf("Enter the size of Queue:\n>> ");
    scanf("%d", &max_size);
    queue = (int *)calloc(max_size, sizeof(int));

    printf("CIRCULAR QUEUE of size %d is created!\n", max_size);

    while (1)
    {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Display\n6.Quit\n>> ");
        int choice;
        scanf("%d", &choice);

        int value;
        switch (choice)
        {
        case 1:
            printf("\n Enter value:\n>> ");
            scanf("%d", &value);
            if (!enqueue(queue, &front, &rear, max_size, value))
            {
                printf("\nQueue is full. Enqueue failed.\n");
            }
            break;
        case 2:
            if (!dequeue(queue, &front, &rear, max_size))
            {
                printf("\nQueue is empty. Dequeue failed.\n");
            }
            break;
        case 3:
            if (!isQueueEmpty(front))
            {
                value = getFront(queue, front);
                printf("\nValue at Front is: %d", value);
            }
            else
                printf("QUEUE IS EMPTY");
            break;
        case 4:
            if (!isQueueEmpty(rear))
            {
                value = getRear(queue, rear);
                printf("\nValue at Rear is: %d", value);
            }
            else
                printf("QUEUE IS EMPTY");
            break;
        case 5:
            displayQueue(queue, front, rear, max_size);
            break;
        default:
            return;
            break;
        }
    }
}

void displayQueue(int *queue, int front, int rear, int size)
{
    if (isQueueEmpty(front))
    {
        printf("QUEUE IS EMPTY");
    }
    else
    {
        printf("Queue: [");
        int index = front;
        do
        {
            printf("%d ", queue[index]);
            index = (index + 1) % size;
        } while (index != (rear + 1) % size);
        printf("]\n");
    }
}

int isQueueFull(int rear, int front, int size)
{
    return ((rear + 1) % size) == front;
}

int isQueueEmpty(int back_or_top)
{
    return back_or_top == -1 ? 1 : 0;
}

int getFront(int *queue, int front)
{
    return queue[front];
}

int getRear(int *queue, int rear)
{
    return queue[rear];
}

int enqueue(int *queue, int *front, int *rear, int size, int data)
{
    if (isQueueFull(*rear, *front, size))
    {
        return 0;
    }
    if (isQueueEmpty(*front))
    {
        *front = 0;
    }
    *rear = (*rear + 1) % size;
    queue[*rear] = data;
    return 1;
}

int dequeue(int *queue, int *front, int *rear, int size)
{
    if (isQueueEmpty(*front))
    {
        return 0;
    }
    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
        return 1;
    }
    *front = (*front + 1) % size;
    return 1;
}

int main()
{
    queue_menu();
    return 0;
}
