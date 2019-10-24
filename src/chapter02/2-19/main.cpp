#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "double_linked_list.h"

void visit(DuLinkList L)
{
	DuLinkList node = L->next;

	while (node != L)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int main()
{
	DuLinkList L;
	Init(L);

	for (int i = 1; i < 6; i++)
	{
		Insert(L, i, i * 2);
	}

	Insert(L, 3, 5);
	Insert(L, 1, 1);
	Traverse(L, visit);

	return 0;
}