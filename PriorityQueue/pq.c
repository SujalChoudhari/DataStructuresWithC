#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int priority;
} Element;

typedef struct {
    Element* array;
    int capacity;
    int size;
} PriorityQueue;

void enqueue(PriorityQueue* pq, int val, int priority);
void dequeue(PriorityQueue* pq);
void display(PriorityQueue* pq);
void heapifyUp(PriorityQueue* pq, int index);
void heapifyDown(PriorityQueue* pq, int index);
int parentIndex(int index);
void swap(Element* a, Element* b);

int main() {
    PriorityQueue pq;
    int choice, value, priority;

    printf("Enter the initial capacity of the Priority Queue: ");
    scanf("%d", &pq.capacity);

    pq.array = (Element*)malloc(pq.capacity * sizeof(Element));
    pq.size = 0;

    do {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and priority to enqueue: ");
                scanf("%d %d", &value, &priority);
                enqueue(&pq, value, priority);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                printf("Exiting the program. Bye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(pq.array);

    return 0;
}

void enqueue(PriorityQueue* pq, int val, int priority) {
    if (pq->size == pq->capacity) {
        printf("Priority Queue is full. Cannot enqueue.\n");
        return;
    }

    Element newElement = {val, priority};
    pq->array[pq->size] = newElement;
    heapifyUp(pq, pq->size);
    pq->size++;
}

void dequeue(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }

    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
}

void display(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue elements:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("(%d, %d) ", pq->array[i].value, pq->array[i].priority);
    }
    printf("\n");
}

void heapifyUp(PriorityQueue* pq, int index) {
    int currentIndex = index;
    while (currentIndex > 0) {
        int parentIdx = parentIndex(currentIndex);
        if (pq->array[currentIndex].priority > pq->array[parentIdx].priority) {
            swap(&pq->array[currentIndex], &pq->array[parentIdx]);
            currentIndex = parentIdx;
        } else {
            break;
        }
    }
}


void heapifyDown(PriorityQueue* pq, int index) {
    int currentIndex = index;
    while (1) {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;
        int maxIndex = currentIndex;

        if (leftChildIndex < pq->size && pq->array[leftChildIndex].priority > pq->array[maxIndex].priority) {
            maxIndex = leftChildIndex;
        }

        if (rightChildIndex < pq->size && pq->array[rightChildIndex].priority > pq->array[maxIndex].priority) {
            maxIndex = rightChildIndex;
        }

        if (maxIndex != currentIndex) {
            swap(&pq->array[currentIndex], &pq->array[maxIndex]);
            currentIndex = maxIndex;
        } else {
            break;
        }
    }
}


int parentIndex(int index) {
    return (index - 1) / 2;
}

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}