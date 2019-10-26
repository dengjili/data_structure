#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "link.h"

void visit(LinkList L)
{
	Link node = L.head->next;

	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}


// 在第i个元素之前插入元素
Status Insert(LinkList &L, int i, ElemType e)
{
	Link prior;
	Status status = LocatePos(L, i - 1, prior);
	if (status == ERROR)
	{
		return ERROR;
	}

	Link node;
	status = MakeNode(node, e);
	if (status == ERROR)
	{
		return ERROR;
	}
	InsertFirst(prior, node);
	L.len++;

	return OK;
}

int main()
{
	LinkList La;
	Init(La);

	for (int i = 1; i < 7; i++)
	{
		Insert(La, i, i * 2);
	}

	Traverse(La, visit);

	return 0;
}