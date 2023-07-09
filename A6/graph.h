typedef struct node
{
    int weight;
    int start;
    int end;
    struct node *next;
} node;

typedef struct graph
{
    node **arr;
    int size;
} G;

void init(G *g, char *str);
void bfs(G *g, int start);
void dfs(G *g, int start);
void initSpanning(G *g, int size);
void krushkal(G *g, G *spanning);

void printGraph(G g);