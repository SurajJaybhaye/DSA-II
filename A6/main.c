#include <stdio.h>
#include "Heaps.h"

int main(int argc, char **argv)
{

    G g;
    G *gp = &g;

    char *filename = argv[1];

    init(gp, filename);
    // printGraph(g);
    G span;
    G *spanning = &span; 
    initSpanning(spanning, gp->size);
    krushkal(gp, spanning);
 

    while (1)
    {
        printf("Enter \n1. To bfs Traversal \n2. To dfs Traversal \n3. To to dfs Traversal of minimum spanning Tree \n4. To print Spanning Edges \n5. Exit \n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {

            bfs(gp, 0);
        }
        else if (choice == 2)
        {
            dfs(gp, 0);
        }
        else if (choice == 3)
        {

            bfs(spanning, 0);
        }
        else if (choice == 4)
        {

            printGraph(*spanning);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Enter valid choice !!! \n");
        }
    }

    return 0;
}
