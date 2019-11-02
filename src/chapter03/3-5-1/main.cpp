#include <stdio.h>
#include "queue.h"

void visit(LinkQueue Q)
{
	Queue node = Q.front->next;

	while (node)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int main()
{
	LinkQueue Q;
	Init(Q);

	for (int i = 1; i <= 10; i++)
	{
		Insert(Q, i);
	}
	Traverse(Q, visit);

	Destroy(Q);

	return 0;
}