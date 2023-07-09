typedef struct list{
	int n;
	struct list *next;
}list;
typedef struct queue{
	list *front, *rear;	
}queue;
void initQ(queue *);
int isFullQ(queue);
int isEmptyQ(queue);
void enqueueQ(queue *, int);
int dequeueQ(queue *);
int queueSize(queue);
