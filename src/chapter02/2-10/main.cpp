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

void CreateLinkList(LinkList &L, int n)
{
	Init(L);
	for (int i = 1; i <= n; i++)
	{
		Insert(L, i, i);
	}
}

int main()
{
	LinkList head;
	CreateLinkList(head, 10);
	Traverse(head, visit);

	ElemType e = 500;
	Delete(head, 5, e);
	printf("e = %d\n", e);
	Traverse(head, visit);
	
	return 0;
}