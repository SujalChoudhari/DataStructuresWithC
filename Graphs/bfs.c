#include <stdio.h>
#include <stdlib.h>

void bfs(int **matrix, int node, int no_of_nodes)
{
    int *queue = (int *)calloc(no_of_nodes, sizeof(int));
    int front = -1;
    int rear = -1;
    int *visited = (int *)calloc(no_of_nodes, sizeof(int));

    // Enqueue
    if (rear == -1)
    {
        rear = 0, front = 0;
        queue[front] = node;
    }
    else
    {
        rear++;
        queue[rear] = node;
    }

    visited[node] = 1;

    while (front <= rear)
    {
        int v = queue[front];
        front++;

        printf("%d ", v); // Process the node

        for (int i = 0; i < no_of_nodes; i++)
        {
            if (matrix[v][i] && !visited[i])
            {
                // Enqueue
                rear++;
                queue[rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void main()
{
    int number_of_nodes;

    printf("Enter Number of Nodes:\n>>> ");
    scanf("%d", &number_of_nodes);

    int **arr = (int **)calloc(number_of_nodes, sizeof(0));

    for (int i = 0; i < number_of_nodes; i++)
    {
        arr[i] = (int *)calloc(number_of_nodes, sizeof(0));
    }

    for (int i = 0; i < number_of_nodes; i++)
    {
        for (int j = 0; j < number_of_nodes; j++)
        {
            if (i != j)
            {
                printf("Is there a edge between %d to %d? [1/0] \n>>> ", i, j);
                int edge = 0;
                scanf("%d", &edge);
                arr[i][j] = edge;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }

    printf("\nProvide a starting node:\n>>> ");
    int start = 0;
    scanf("%d", &start);
    printf("\n\nBFS is:\n");
    bfs(arr, start, number_of_nodes);
    printf("\n");

}