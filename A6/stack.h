#include <stdbool.h>
typedef struct stackNode
{
	int data;
	struct stackNode *next;
} stackNode;
typedef struct stackNode *stack;

void initS(stack *n);
int push(stack *s, int value);
int pop(stack *s);
int peekS(stack s);
int isEmptyS(stack s);
