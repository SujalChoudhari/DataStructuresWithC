#include <stdio.h>

void selection_sort(int *array, int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        int imin = i;
        for (int j = i + 1; j < n - 1; j++)
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
    int array[] = {40, 50, 20, 10, 5, 6, 7, 29, 55};
    int n = 9;

    selection_sort(array, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}