#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int t = atoi(argv[1]);
    char *filename = argv[2];
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%d\n", t);
    while (t > 0)
    {
        int num = rand();
        fprintf(fp, "%d ", num);
        t--;
    }
    return 0;
}