#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *arr;
    int front;
    int rear;
} Queue;

void radix(int *array, int n, int digits) {
    Queue *Q[10];

    // Init Queues
    for (int p = 0; p <= 9; p++) {
        int *temp_arr_for_queue = (int *)malloc(n * sizeof(int));
        Queue *new_queue = (Queue *)malloc(sizeof(Queue));
        new_queue->arr = temp_arr_for_queue;
        new_queue->front = -1;
        new_queue->rear = -1;
        Q[p] = new_queue;
    }

    int D = 1;

    for (int k = 1; k <= digits; k++) {
        D = 10 * D;
        for (int i = 0; i < n; i++) {
            int t = (array[i] % D) / (D / 10);

            // enqueue
            if (Q[t]->rear == -1) {
                Q[t]->rear = 0;
                Q[t]->front = 0;
                Q[t]->arr[0] = array[i];
            } else {
                Q[t]->rear++;
                Q[t]->arr[Q[t]->rear] = array[i];
            }
        }

        int j = 0;
        for (int p = 0; p <= 9; p++) {
            Queue *temp_queue = Q[p];
            while (temp_queue->front != -1 && temp_queue->front <= temp_queue->rear) {
                int curr_value = temp_queue->arr[temp_queue->front];

                temp_queue->front++;
                if (temp_queue->front > temp_queue->rear) {
                    temp_queue->front = -1;
                    temp_queue->rear = -1;
                }

                array[j] = curr_value;
                j++;
            }
        }
    }

    // Free memory for queue arrays
    for (int p = 0; p <= 9; p++) {
        free(Q[p]->arr);
        free(Q[p]);
    }

    // Print sorted array
    printf("Sorted Array: ");
    for (int s = 0; s < n; s++) {
        printf("%d ", array[s]);
    }
}

void main()
{
    int n = 0;
    int d = 0;

    printf("Enter no of elements:\n>>> ");
    scanf("%d", &n);

    printf("\nEnter no of digits:\n>>> ");
    scanf("%d", &d);

    int *array = (int *)calloc(n, sizeof(0));

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter elements: \n>>> ");
        scanf("%d", &array[i]);
    }

    radix(array, n, d);

    printf("\n");
}