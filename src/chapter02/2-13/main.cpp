#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "linklist_array.h"

void visit(LinkList S, int head)
{
	int index = S[head].cur;
	while (index > 0)
	{
		printf("%d ", S[index].data);
		index = S[index].cur;
	}
	printf("\n");
}

Status equal(ElemType e1, ElemType e2)
{
	return e1 == e2 ? TRUE : FALSE;
}

int main()
{
	LinkList S1;
	Init(S1);
	int head = Malloc(S1);
	ElemType temp, tail = head;
	int m = 5, n = 5;
	for (int j = 1; j <= 5; j++)
	{
		temp = Malloc(S1);
		S1[temp].data = j;
		S1[tail].cur = temp;
		tail = temp;
	}
	S1[tail].cur = 0;
	Traverse(S1, head, visit);

	ElemType e = 3;
	printf("e=%d, index=%d\n", e, Locate(S1, head, e));
	return 0;
}