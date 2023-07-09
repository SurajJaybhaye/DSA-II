#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "Queue.h"

void Qinit(Q **pq)
{
	Q *q = (*pq);
	q->rare = NULL;
	q->front = NULL;
}

void enqueue(Q **pq, int data)
{

	Q *q = (*pq);

	node *new_node = (node *)malloc(sizeof(node));

	new_node->data = data;
	new_node->next = NULL;

	if (q->rare == NULL)
	{
		q->rare = new_node;
		q->front = new_node;
		return;
	}

	q->rare->next = new_node;
	q->rare = new_node;

	return;
}

int dequeue(Q **pq)
{

	Q *q = (*pq);

	if (q->front == NULL)
		return INT_MIN;

	int temp = q->front->data;
	node *np = q->front;
	q->front = q->front->next;

	if (q->front == NULL)
		q->rare = NULL;

	free(np);

	return temp;
}

int top(Q *q)
{

	if (q->front == NULL)
	{
		return INT_MIN;
	}

	return q->front->data;
}

int isEmpty(Q *q)
{

	return q->front == NULL;
}
