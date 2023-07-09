typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct Queue
{
    node *rare, *front;
} Q;

void Qinit(Q **q);
void enqueue(Q **pq, int data);
int dequeue(Q **pq);
int top(Q *q);
int isEmpty(Q *q);
