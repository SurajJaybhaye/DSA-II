#include "stack.h"
#include <stdlib.h>
#include <limits.h>

void initS(stack *s)
{
	*s = NULL;
	return;
}

int push(stack *s, int value)
{
	stackNode *n = malloc(sizeof(stackNode));
	if (!n)
		return 0;
	n->data = value;
	n->next = *s;
	*s = n;
	return 1;
}
int pop(stack *s)
{
	if (!(*s))
		return INT_MIN;
	int result = (*s)->data;
	stackNode *n = *s;
	(*s) = (*s)->next;
	free(n);
	n = NULL;
	return result;
}
int peekS(stack s)
{
	if (!s)
		return INT_MIN;
	return s->data;
}
int isEmptyS(stack s)
{
	return !s;
}
