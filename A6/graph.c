#include <stdio.h>
#include <stdlib.h>
// #include "graph.h"
#include "queue.h"
#include "stack.h"
#include "Heaps.h"

void init(G *g, char *str)
{

    FILE *fp = fopen(str, "r");
    if (!fp)
    {
        printf("File not opened !!!");
        return;
    }

    int size;
    fscanf(fp, "%d", &size);
    g->size = size;

    g->arr = (node **)malloc(sizeof(node) * size);

    for (int i = 0; i < size; i++)
    {
        g->arr[i] = NULL;
    }

    int sr, temp;

    node *trav;
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%d ", &sr);
        trav = g->arr[sr];
        for (int j = 0; j < size; j++)
        {
            fscanf(fp, "%d ", &temp);
            if (temp == 0)
            {
                continue;
            }
            node *neigh = (node *)malloc(sizeof(node));

            if (!neigh)
            {
                printf("Memory is not allocated !!! \n");
                return;
            }
            neigh->start = i;
            neigh->end = j;
            neigh->weight = temp;
            neigh->next = NULL;

            if (trav == NULL)
            {
                g->arr[sr] = neigh;
                trav = neigh;
            }
            else
            {
                trav->next = neigh;
                trav = trav->next;
            }
        }
    }

    return;
}

void printGraph(G g)
{
    node *temp;
    for (int i = 0; i < g.size; i++)
    {
        temp = g.arr[i];
        printf("%d ", i);
        while (temp)
        {
            printf("  |%d %d %d|  ", temp->start, temp->weight, temp->end);
            temp = temp->next;
        }
        printf("\n");
    }
}

void bfs(G *g, int start)
{
    queue q;
    queue *pq = &q;
    int *visited = (int *)calloc(sizeof(int), g->size);

    if (!visited)
    {
        printf("Not allocated successfully !!! \n");
        return;
    }

    initQ(pq);

    if (start > g->size || start < 0)
    {
        printf("Enter valid start \n");
        return;
    }

    enqueueQ(pq, start);
    visited[start] = 1;
    node *trav;

    while (!isEmptyQ(*pq))
    {
        int temp = dequeueQ(pq);
        printf("%d ", temp);
        trav = g->arr[temp];

        while (trav)
        {
            if (visited[trav->end] == 0)
            {
                visited[trav->end] = 1;
                enqueueQ(pq, trav->end);
            }
            trav = trav->next;
        }
    }

    printf("\n");

    return;
}

void dfs(G *g, int start)
{

    stack s;
    stack *ps = &s;
    int *visited = (int *)calloc(sizeof(int), g->size);

    if (!visited)
    {
        printf("Not allocated successfully !!! \n");
        return;
    }

    initS(ps);

    if (start > g->size || start < 0)
    {
        printf("Enter valid start \n");
        return;
    }

    push(ps, start);
    visited[start] = 1;
    node *trav;

    while (!isEmptyS(*ps))
    {
        int temp = pop(ps);
        printf("%d ", temp);
        trav = g->arr[temp];

        while (trav)
        {
            if (visited[trav->end] == 0)
            {
                visited[trav->end] = 1;
                push(ps, trav->end);
            }
            trav = trav->next;
        }
    }

    printf("\n");

    return;
}

void initSpanning(G *g, int size)
{
    g->size = size;
    g->arr = (node **)malloc(sizeof(node *) * size);

    if (!g->arr)
    {
        printf("Memory not allocated !!! \n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        g->arr[i] = NULL;
    }

    return;
}

void buildSpanning(G *g, int start, int weight, int end)
{
    node *nn = (node *)malloc(sizeof(node));

    if (!nn)
    {
        printf("Memory Not Allocated !!! \n");
        return;
    }

    nn->start = start;
    nn->weight = weight;
    nn->end = end;
    nn->next = NULL;

    node *temp = g->arr[start];
    if (temp == NULL)
    {
        g->arr[start] = nn;
    }
    else
    {
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }

    // second part
    node *nn2 = (node *)malloc(sizeof(node));
    if (!nn2)
    {
        free(nn);
        printf("Not allocated \n");
        return;
    }

    nn2->start = end;
    nn2->end = start;
    nn2->weight = weight;

    temp = g->arr[end];
    if (temp == NULL)
    {
        g->arr[end] = nn2;
    }
    else
    {
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = nn2;
    }

    return;
}

void krushkal(G *g, G *spanning)
{
    heap h;
    heap *hp = &h;
    spanning->size = g->size;

    initHeap(hp, 1);
    int visited[g->size];

    for (int i = 0; i < g->size; i++)
    {
        visited[i] = i;
    }

    for (int i = 0; i < g->size; i++)
    {
        node *temp = g->arr[i];
        // printf("%d ", i);
        while (temp)
        {
            // printf("| %d %d %d | \n", temp->start, temp->weight, temp->end);
            insertHeap(hp, temp);
            temp = temp->next;
        }
    }

    // return NULL;

    int count = 0;
    while (count < g->size - 1)
    {
        node *temp = dequeueHeap(hp);

        if (temp == NULL)
        {
            return;
        }
        int start = temp->start;
        int weight = temp->weight;
        int end = temp->end;

        if (visited[start] != visited[end])
        {
            for (int i = 0; i < g->size; i++)
            {
                if (i != start && visited[i] == visited[start])
                {
                    visited[i] = visited[end];
                }
            }
            visited[start] = visited[end];
            // for (int i = 0; i < g->size; i++)
            // {
            //     printf("%d ", visited[i]);
            // }
            // printf("\n");

            buildSpanning(spanning, start, weight, end);
            count++;
        }
    }

    // printGraph(*spanning);
    return;
}
