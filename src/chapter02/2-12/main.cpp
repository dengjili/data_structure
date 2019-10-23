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

void MergeLinkList(LinkList &La, LinkList &Lb, LinkList &Lc)
{
	Lc = La;
	LinkList pc = Lc;

	LinkList pa = La->next;
	LinkList pb = Lb->next;

	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}

	if (pa)
	{
		pc->next = pa;
	} 
	else
	{
		pc->next = pb;
	}

	free(Lb);

}

int main()
{
	LinkList head;
	Init(head);
	for (int i = 1; i < 13; i++)
	{
		printf("status = %d\n", Insert(head, i, i * 2));
	}
	Insert(head, 1, 1);
	Insert(head, 5, 500);

	// ´íÎóÎ»ÖÃ²âÊÔ
	printf("status = %d\n", Insert(head, -1, 1));
	printf("status = %d\n", Insert(head, 100, 1));
	
	Traverse(head, visit);

	ElemType e;
	printf("status = %d\n", Delete(head, -1, e));
	printf("status = %d\n", Delete(head, 100, e));
	printf("status = %d\n", Delete(head, 14, e));
	printf("status = %d\n", Delete(head, 5, e));
	printf("status = %d\n", Delete(head, 1, e));
	Traverse(head, visit);

	LinkList head_c;
	CreateLinkList(head_c, 10);
	Traverse(head_c, visit);

	LinkList Lc;
	MergeLinkList(head, head_c, Lc);
	Traverse(Lc, visit);
	
	return 0;
}