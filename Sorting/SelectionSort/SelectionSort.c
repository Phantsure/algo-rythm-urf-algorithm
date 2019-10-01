#include <stdio.h>

#define ARRSIZE 10

int main()
{

    int arr[ARRSIZE] = {1, 8, 3, 6, 20, 5, -5, 2, 9, 12};

    int temp = 0;

    for (int i = 0; i < ARRSIZE - 1; i++)
    {
        for (int j = i + 1; j < ARRSIZE; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < ARRSIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
