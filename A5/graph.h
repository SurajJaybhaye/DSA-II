#include <stdbool.h>

typedef struct graph
{
	int **arr;
	int size;
} G;

void init(G *g, char *str);
void display(G g);
void printDegree(G g);
int isConnected(G g);
void displayComponents(G g);
int isAdjacent(G g, int a, int b);
void print_all_cycles(int *adj_matrix[], int n, bool visited[], int vertex, int start_vertex, int cycle[], int cycle_size);
void find_cycles(int *adj_matrix[], int n);