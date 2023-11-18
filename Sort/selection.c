#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *array, int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        int imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[imin])
            {
                imin = j;
            }
        }

        int temp = array[i];
        array[i] = array[imin];
        array[imin] = temp;
    }
}

void main()
{
    int n = 0;
    printf("Enter no of elements:\n>>> ");
    scanf("%d", &n);

    int *array = (int *)calloc(n, sizeof(0));

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter elements: \n>>> ");
        scanf("%d", &array[i]);
    }

    selection_sort(array, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}