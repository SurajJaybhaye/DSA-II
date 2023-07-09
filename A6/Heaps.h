#include "graph.h"

typedef struct heap
{
    node **arr;
    int size;
    int rare;
} heap;

void initHeap(heap *h, int size);
void insertHeap(heap *h, node *val);
node *dequeueHeap(heap *h);
void printHeap(heap *h);
int isEmptyHeap(heap h);