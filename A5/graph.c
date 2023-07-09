#include <stdio.h>
#include "Queue.h"
#include <limits.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include "graph.h"

void init(G *g, char *str)
{

	FILE *fp = fopen(str, "r");
	if (!fp)
	{
		return;
	}

	fseek(fp, 0, 0);

	int sr, size;

	fscanf(fp, "%d %d\n", &sr, &size);
	g->size = size;

	if (size <= 0)
	{
		printf("Enter valid size. \n");
	}

	g->arr = (int **)malloc(sizeof(int *) * size);
	if (!g->arr)
	{
		printf("Memory is not allocated !!! \n");
		return;
	}

	for (int i = 0; i < size; i++)
	{
		g->arr[i] = NULL;
	}

	for (int i = 0; i < size; i++)
	{

		g->arr[i] = (int *)malloc(sizeof(int) * size);
		if (!g->arr[i])
		{
			printf("Not Allocated \n");
			return;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int n;
			fscanf(fp, "%d ", &n);
			g->arr[i][j] = n;
		}
	}

	fclose(fp);

	return;
}

void display(G g)
{

	printf("As Matrix : \n\n");

	for (int i = 0; i < g.size; i++)
	{
		for (int j = 0; j < g.size; j++)
		{
			printf(" %d ", g.arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Start Index : End Index : Weight \n");
	for (int i = 0; i < g.size; i++)
	{
		for (int j = 0; j < g.size; j++)
		{
			if (g.arr[i][j] != 0)
			{

				printf("%d : %d : %d\n", i, j, g.arr[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void printDegree(G g)
{

	printf("Printing Degree of each Vertices ...  \n");
	printf("      Sr. no.  ||    Degree \n");

	for (int i = 0; i < g.size; i++)
	{
		int degree = 0;
		for (int j = 0; j < g.size; j++)
		{
			if (g.arr[i][j] != 0)
			{
				degree++;
			}
		}
		printf("\t%d.\t \t%d \n", i, degree);
	}
}

int isConnected(G g)
{

	Q pq;
	Q *q = &pq;
	Qinit(&q);
	int visited[g.size];
	for (int i = 0; i < g.size; i++)
		visited[i] = 0;

	// start from 0
	enqueue(&q, 0);
	visited[0] = 1;

	while (!isEmpty(q))
	{
		int t = dequeue(&q);
		for (int i = 0; i < g.size; i++)
		{
			if (g.arr[i] != 0 && visited[i] == 0)
			{
				visited[i] = 1;
				enqueue(&q, i);
			}
		}
	}

	for (int i = 0; i < g.size; i++)
	{
		if (visited[i] == 0)
		{
			return 0; // not connected
		}
	}

	return 1; // connected
}

void bfs(G g, int visited[], int start)
{

	Q pq;
	Q *q = &pq;
	Qinit(&q);

	enqueue(&q, start);
	visited[start] = 1;

	while (!isEmpty(q))
	{
		int t = dequeue(&q);
		printf("%d ", t);
		for (int i = 0; i < g.size; i++)
		{
			if (g.arr[i] != 0 && visited[i] == 0)
			{
				visited[i] = 1;
				enqueue(&q, i);
			}
		}
	}
}

void displayComponents(G g)
{

	int visited[g.size];
	for (int i = 0; i < g.size; i++)
		visited[i] = 0;

	int count = 0;

	for (int i = 0; i < g.size; i++)
	{
		if (visited[i] == 0)
		{
			count++;
			printf("\nComponent %d : \n", count);
			printf("Vertices : \n");
			bfs(g, visited, i);
			printf("\n");
		}
	}

	printf("Total Components : %d \n", count);
	return;
}

int isAdjacent(G g, int a, int b)
{

	if (a < 0 || b < 0 || a >= g.size || b >= g.size)
	{
		printf("Enter valid choice of Vertices \n");
		return INT_MIN;
	}

	return g.arr[a][b] != 0;
}

void print_all_cycles(int *adj_matrix[], int n, bool visited[], int vertex, int start_vertex, int cycle[], int cycle_size)
{
	visited[vertex] = true;		  // Mark current vertex as visited
	cycle[cycle_size++] = vertex; // Add current vertex to the cycle

	if (cycle_size > 2 && start_vertex == vertex)
	{
		printf("Cycle: ");
		for (int i = 0; i < cycle_size; i++)
		{
			printf("%d ", cycle[i]);
		}
		printf("\n");
	}

	for (int neighbor = 0; neighbor < n; neighbor++)
	{
		if (adj_matrix[vertex][neighbor] && !visited[neighbor])
		{
			print_all_cycles(adj_matrix, n, visited, neighbor, start_vertex, cycle, cycle_size);
		}
	}

	visited[vertex] = false; // Reset visited flag for backtracking
}

void find_cycles(int *adj_matrix[], int n)
{
	bool visited[n];
	int cycle[n];

	for (int start_vertex = 0; start_vertex < n; start_vertex++)
	{
		for (int i = 0; i < n; i++)
		{
			visited[i] = false; // Initialize visited array for each starting vertex
		}
		print_all_cycles(adj_matrix, n, visited, start_vertex, start_vertex, cycle, 0);
	}
}
