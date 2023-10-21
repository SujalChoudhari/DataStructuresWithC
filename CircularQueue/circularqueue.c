#include <stdio.h>
#include <stdlib.h>

/*
    Menu driven program to use queue
*/
void queue_menu();

/*
    Add an element to the given queue
*/
int enqueue(int *queue, int *top, int *rear, int size, int data);

/*
    Remove an element from the given queue
*/
int dequeue(int *queue, int *top, int *rear, int size);

/*
    See the element at the front
*/
int front(int *queue, int top);

/*
    See the rear element of the queue
*/
int rear(int *queue, int back);

/*
    Check if queue is empty
*/
int queue_is_empty(int back_or_top);

/*
    Check if queue is full
*/
int queue_is_full(int back, int top, int size);

void queue_display(int *queue, int top, int rear, int size);

void queue_menu()
{

    // maximaum size for the stack
    int max_size;

    // pointer to a dynamic allocated memory of stack
    int *queue;

    // index to the top most value
    int top = -1, back = -1;

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
            enqueue(queue, &top, &back, max_size, value);
            break;
        case 2:
            dequeue(queue, &top, &back, max_size);
            break;
        case 3:
            if (!queue_is_empty(top))
            {
                value = front(queue, top);
                printf("\nValue at Front is: %d", value);
            }
            else
                printf("QUEUE IS EMPTY");
            break;
        case 4:
            if (!queue_is_empty(top))
            {
                value = rear(queue, back);
                printf("\nValue at Rear is: %d", value);
            }
            else
                printf("QUEUE IS EMPTY");
            break;
        case 5:
            queue_display(queue, top, back,max_size);
            break;
        default:
            return;
            break;
        }
    }
}

void queue_display(int *queue, int top, int rear, int size)
{
    if (queue_is_empty(top))
    {
        printf("QUEUE IS EMPTY");
    }
    else
    {
        printf("Queue: [");
        int index = top;
        while(index != rear){
            printf("%d",queue[index]);
            index = (index + 1) % size;
        }
        printf("]\n");
    }
}

int queue_is_full(int rear, int top, int size)
{
    return rear == (top -1) % size;
}

int queue_is_empty(int back_or_top)
{
    return back_or_top == -1 ? 1 : 0;
}

int front(int *queue, int top)
{
    if (queue_is_empty(top))
    {
        printf("STACK IS EMPTY");
        return -1;
    }
    else
    {
        return queue[top];
    }
}

int rear(int *queue, int back)
{
    if (queue_is_empty(back))
    {
        printf("STACK IS EMPTY");
        return -1;
    }
    else
    {
        return queue[back];
    }
}

int enqueue(int *queue, int *top, int *rear, int size, int data)
{
    if (queue_is_empty(*top))
    {
        *top = 0;
        *rear = 0;
        queue[*rear] = data;
        return 1;
    }
    else if (queue_is_full(*rear, *top, size))
    {
        printf("QUEUE IS FULL");
        return 0;
    }
    else
    {
        (*rear) = ((*rear) + 1) % size;
        queue[*rear] = data;
        return 1;
    }
}

int dequeue(int *queue, int *top, int *rear, int size)
{
    if (queue_is_empty(*top))
    {
        printf("QUEUE IS EMPTY");
        return 0;
    }
    else if (*top == *rear)
    {
        *top = -1;
        *rear = -1;
        return 1;
    }
    else
    {
        (*top) = ((*top) + 1) % size;
        return 1;
    }
}

void main()
{
    queue_menu();
}