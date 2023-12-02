#include <stdio.h>
#include <stdlib.h>

void dfs(int **array, int s, int number_of_nodes, int *stack, int *top, int *visited) {
    if (visited[s] == 0) {
        (*top)++;
        stack[*top] = s;
        visited[s] = 1;
    }

    while (*top != -1) {
        int v = stack[*top];
        (*top)--;

        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;

            for (int i = 0; i < number_of_nodes; i++) {
                if (array[v][i] && !visited[i]) {
                    (*top)++;
                    stack[*top] = i;
                }
            }
        }
    }
}

int main() {
    int number_of_nodes;

    printf("Enter Number of Nodes:\n>>> ");
    scanf("%d", &number_of_nodes);

    int **arr = (int **)calloc(number_of_nodes, sizeof(int *));

    for (int i = 0; i < number_of_nodes; i++) {
        arr[i] = (int *)calloc(number_of_nodes, sizeof(int));
    }

    for (int i = 0; i < number_of_nodes; i++) {
        for (int j = 0; j < number_of_nodes; j++) {
            if (i != j) {
                printf("Is there an edge between %d and %d? [1/0] \n>>> ", i, j);
                int edge = 0;
                scanf("%d", &edge);
                arr[i][j] = edge;
            } else {
                arr[i][j] = 0;
            }
        }
    }

    printf("\nProvide a starting node:\n>>> ");
    int start = 0;
    scanf("%d", &start);
    printf("\nDFS is:\n");

    int *stack = (int *)calloc(number_of_nodes, sizeof(int));
    int top = -1;

    int *visited = (int *)calloc(number_of_nodes, sizeof(int));

    dfs(arr, start, number_of_nodes, stack, &top, visited);
    printf("\n");

    return 0;
}