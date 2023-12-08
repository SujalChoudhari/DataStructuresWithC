#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to add a new node to the linked list
struct Node *addNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to perform DFS using linked list
void dfs(struct Node **adjacencyList, int s, int *visited)
{
    if (visited[s] == 0)
    {
        printf("%d ", s);
        visited[s] = 1;

        struct Node *current = adjacencyList[s];

        while (current != NULL)
        {
            int i = current->data;
            if (!visited[i])
            {
                dfs(adjacencyList, i, visited);
            }
            current = current->next;
        }
    }
}

int main()
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
                printf("Is there an edge between %d and %d? [1/0] \n>>> ", i, j);
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
    printf("\nDFS is:\n");

    int *visited = (int *)calloc(number_of_nodes, sizeof(int));

    dfs(adjacencyList, start, visited);
    printf("\n");

    return 0;
}
