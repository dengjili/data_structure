#include <stdlib.h>
#include "linklist_array.h"

Status Init(LinkList &S)
{
	for (int i = 0; i < MAX_SIZE - 1; i++)
	{
		S[i].cur = i + 1;
	}
	S[MAX_SIZE - 1].cur = 0;
	return OK;
}

int Malloc(LinkList &S)
{
	int i = S[0].cur;
	if (i != 0)
	{
		S[0].cur = S[i].cur;
	}
	return i;
}

void Free(LinkList &S, int k)
{
	S[k].cur = S[0].cur;
	S[0].cur = k;
}

int Locate(LinkList S, int head, ElemType e)
{
	int i = S[head].cur;
	while (i != 0 && S[i].data != e)
	{
		i = S[i].cur;
	}
	return i;
}

void Traverse(LinkList L, int head, void (* visit)(LinkList, int))
{
	(* visit)(L, head);
}