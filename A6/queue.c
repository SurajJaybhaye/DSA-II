#include "queue.h"
#include "stdio.h"
#include "limits.h"
#include "stdlib.h"

void initQ(queue *q)
{
	q->front = NULL;
	q->rear = NULL;
}

int isEmptyQ(queue q)
{
	return q.front == NULL;
}

void enqueueQ(queue *q, int num)
{
	if (isEmptyQ(*q))
	{
		q->rear = malloc(sizeof(list));
		q->front = q->rear;
		q->rear->n = num;
		q->rear->next = NULL;
		return;
	}
	q->rear->next = malloc(sizeof(list));
	q->rear = q->rear->next;
	q->rear->n = num;
	q->rear->next = NULL;
	return;
}
int dequeueQ(queue *q)
{
	if (isEmptyQ(*q))
		return INT_MIN;
	int result;
	list *temp;
	if (q->rear == q->front)
	{
		result = q->rear->n;
		temp = q->rear;
		q->rear = q->front = NULL;
		free(temp);
	}
	else
	{
		temp = q->front;
		result = q->front->n;
		q->front = q->front->next;
		free(temp);
	}
	return result;
}
int queueSize(queue q)
{
	list *f = q.front;
	list *r = q.rear;
	if (!f)
		return 0;
	int count = 0;
	while (f)
	{
		count++;
		f = f->next;
	}
	return count;
}
