#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];   // First element as pivot
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        // Find element greater than pivot
        while (i <= high && arr[i] <= pivot)
        {
            i++;
        }

        // Find element smaller than pivot
        while (j >= low && arr[j] > pivot)
        {
            j--;
        }

        // Swap if i and j have not crossed
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }

    // Put pivot in its correct position
    swap(&arr[low], &arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nAfter sorting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}