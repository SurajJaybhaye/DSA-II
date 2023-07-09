#include <stdio.h>
#include <string.h>
#include "graph.h"

int main(int argc, char **argv)
{

	char filename[20];
	strcpy(filename, "");
	strcat(filename, argv[1]);

	// printf("%s", filename);
	// return 0;
	G g;
	G *ph = &g;
	init(ph, filename);

	while (1)
	{
		printf("Enter \n1. To display graph \n2. To display degree of each vertices \n3. To verify graph is connected or not \n4. To Display number of components in the Graph and vertices in each component. \n5. Check if one vertex is adjacent to another \n6. Display all cycles in the Graph \n");
		int choice;
		scanf("%d", &choice);

		if (choice == 1)
		{
			display(*ph);
		}
		else if (choice == 2)
		{
			printDegree(g);
		}
		else if (choice == 3)
		{
			int t = isConnected(g);
			if (t == 1)
			{
				printf("Connected \n");
			}
			else
			{
				printf("Not Connected \n");
			}
		}
		else if (choice == 4)
		{
			displayComponents(g);
		}
		else if (choice == 5)
		{
			int a, b;
			printf("Enter the vertices in range from 0 to %d \n", g.size - 1);
			scanf("%d %d", &a, &b);
			if (a < 0 || b < 0 || a >= g.size || b >= g.size)
			{
				printf("Enter valid vertices \n");
				continue;
			}

			int t = isAdjacent(g, 0, 3);
			if (t == 1)
			{
				printf("Adjacent \n");
			}
			else
			{
				printf("Not Adjacent \n");
			}
		}
		else if (choice == 6)
		{
			find_cycles(g.arr, g.size);
		}
		else
		{
			printf("Enter valid choice \n");
		}
	}

	return 0;
}
