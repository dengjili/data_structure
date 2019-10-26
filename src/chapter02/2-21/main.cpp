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

// 合并两个线性表
Status Merge(LinkList &La, LinkList &Lb, LinkList &Lc)
{
	if (!Init(Lc))
	{
		return ERROR;
	}

	Position ha = GetHead(La);
	Position hb = GetHead(Lb);

	Position pa = NextPos(La, ha);
	Position pb = NextPos(Lb, hb);

	Link node;

	while (pa && pb)
	{
		ElemType a = getCurElem(pa);
		ElemType b = getCurElem(pb);

		if (a < b)
		{
			DeleteFirst(ha, node);
			Append(Lc, node);
			pa = NextPos(La, ha);
		}
		else
		{
			DeleteFirst(hb, node);
			Append(Lc, node);
			pb = NextPos(Lb, hb);
		}
	}

	if (pa)
	{
		Append(Lc, pa);
	}
	else
	{
		Append(Lc, pb);
	}

	FreeNode(ha);
	FreeNode(hb);

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

	LinkList Lb;
	Init(Lb);

	for (int i = 1; i < 4; i++)
	{
		Insert(Lb, i, i * 3);
	}

	Traverse(Lb, visit);

	LinkList Lc;
	Merge(La, Lb, Lc);
	Traverse(Lc, visit);

	return 0;
}