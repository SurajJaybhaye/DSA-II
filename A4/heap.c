#include <stdio.h>

void heapify(int arr[], int len, int start)
{
    int left = 2 * start + 1;
    int right = 2 * start + 2;
    int curr = start;

    if (left < len && arr[left] > arr[curr])
    {
        curr = left;
    }
    if (right < len && arr[right] > arr[curr])
    {
        curr = right;
    }

    if (curr != start)
    {
        int temp = arr[start];
        arr[start] = arr[curr];
        arr[curr] = temp;
        heapify(arr, len, curr);
    }

    return;
}

void heapSort(int arr[], int len)
{
    int end = len / 2 + 1;
    for (int i = end; i >= 0; i--)
    {
        heapify(arr, len, i);
    }
    for (int i = 0; i < len; i++)
    {
        int temp = arr[0];
        arr[0] = arr[len - i - 1];
        arr[len - i - 1] = temp;

        heapify(arr, len - 1 - i, 0);
    }
}
