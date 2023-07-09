#include <stdio.h>
#include <malloc.h>
#include "heap.h"

int main()
{
    int n = 100;
    int arr[n];

    FILE *fp = fopen("file.txt", "r");
    fscanf(fp, "%d", &n);

    int temp;
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", arr + i);
    }

    fclose(fp);

    heapSort(arr, n);

    printf("Assending Order : \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Decending Order : \n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}