#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "linklist.h"

void visit(LinkList L)
{
	LinkList node = L->next;

	while (node)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

Status equal(ElemType e1, ElemType e2)
{
	return e1 == e2 ? TRUE : FALSE;
}


int main()
{
	LinkList head;
	Init(head);
	for (int i = 1; i < 13; i++)
	{
		printf("status = %d\n", Insert(head, i, i * 2));
	}
	
	Traverse(head, visit);

	ElemType e;
	Get(head, 10, e);
	printf("e = %d\n", e);
	
	return 0;
}