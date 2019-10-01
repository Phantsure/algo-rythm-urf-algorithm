#include <stdio.h>

#define ARRSIZE 10

void merge(int arr[], int low, int m, int high)
{
    int n1 = m - low + 1;
    int n2 = high - m;

    int l[n1];
    int r[n2];

    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        r[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void msort(int arr[], int low, int high)
{
    if (low < high)
    {
        int m = (low + high) / 2;

        msort(arr, low, m);
        msort(arr, m + 1, high);

        merge(arr, low, m, high);
    }
}

int main()
{
    int arr[ARRSIZE] = {1, 8, 12, 5, 7, 0, -6, 2, 4, 9};
    msort(arr, 0, ARRSIZE - 1);
    for (int i = 0; i < ARRSIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}