#include <stdio.h>
#include <stdlib.h>

// Node structure for the adjacency list
struct Node
{
    int data;
    struct Node *next;
};

// Function to add a new node to the adjacency list
struct Node *addNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to perform BFS using adjacency list
void bfs(struct Node **adjacencyList, int start, int no_of_nodes)
{
    int *queue = (int *)calloc(no_of_nodes, sizeof(int));
    int front = -1;
    int rear = -1;
    int *visited = (int *)calloc(no_of_nodes, sizeof(int));

    // Enqueue
    if (rear == -1)
    {
        rear = 0, front = 0;
        queue[front] = start;
    }
    else
    {
        rear++;
        queue[rear] = start;
    }

    visited[start] = 1;

    while (front <= rear)
    {
        int v = queue[front];
        front++;

        printf("%d ", v); // Process the node

        struct Node *current = adjacencyList[v];

        while (current != NULL)
        {
            int i = current->data;
            if (!visited[i])
            {
                // Enqueue
                rear++;
                queue[rear] = i;
                visited[i] = 1;
            }
            current = current->next;
        }
    }
}

void main()
{
    int number_of_nodes;

    printf("Enter Number of Nodes:\n>>> ");
    scanf("%d", &number_of_nodes);

    // Create an array of pointers to Node for the adjacency list
    struct Node **adjacencyList = (struct Node **)calloc(number_of_nodes, sizeof(struct Node *));

    for (int i = 0; i < number_of_nodes; i++)
    {
        adjacencyList[i] = NULL; // Initialize each list as empty
    }

    // Create the adjacency list
    for (int i = 0; i < number_of_nodes; i++)
    {
        for (int j = 0; j < number_of_nodes; j++)
        {
            if (i != j)
            {
                printf("Is there an edge between %d to %d? [1/0] \n>>> ", i, j);
                int edge = 0;
                scanf("%d", &edge);

                // If there is an edge, add j to the adjacency list of i
                if (edge)
                {
                    struct Node *newNode = addNode(j);
                    newNode->next = adjacencyList[i];
                    adjacencyList[i] = newNode;
                }
            }
        }
    }

    printf("\nProvide a starting node:\n>>> ");
    int start = 0;
    scanf("%d", &start);
    printf("\n\nBFS is:\n");
    bfs(adjacencyList, start, number_of_nodes);
    printf("\n");
}
