#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "link.h"

void visit(LinkList L)
{
	Link node = L.head->next;

	printf("P(x) = ");
	while (node != NULL)
	{
		if (node->data.coef == 0)
		{
		}
		else if (node->data.expn == 0)
		{
			printf("%d", node->data.coef);
		}
		else if (node->data.coef == 1)
		{
			printf("x^%d", node->data.expn);
		}
		else 
		{
			printf("%dx^%d", node->data.coef, node->data.expn);
		}
		node = node->next;

		if (node != NULL)
		{
			printf(" + ");
		}
	}
	printf("\n");
}

void CreatePolyn3(polynomial &P, int m)
{
	Init(P);
	Position head = GetHead(P);
	head->data.coef = 0;
	head->data.expn = -1;

	ElemType e;
	e.coef = 0;
	e.expn = 0;

	Link node, prior_node = NULL;
	for (int i = 3; i <= m; i++)
	{
		e.coef = i * -1;
		e.expn = i * 2;

		if (!LocateElem(P, e, prior_node, equal))
		{
 			if (MakeNode(node, e))
			{
				InsertFirst(prior_node, node);
				if (P.tail == prior_node)
				{
					P.tail = node;
				}
			}
		}
	}
}

void CreatePolyn2(polynomial &P, int m)
{
	Init(P);
	Position head = GetHead(P);
	head->data.coef = 0;
	head->data.expn = -1;

	ElemType e;
	e.coef = 0;
	e.expn = 0;

	Link node, prior_node = NULL;
	for (int i = 0; i <= m; i++)
	{
		e.coef = i + 1;
		e.expn = i * 2;

		if (!LocateElem(P, e, prior_node, equal))
		{
 			if (MakeNode(node, e))
			{
				InsertFirst(prior_node, node);
				if (P.tail == prior_node)
				{
					P.tail = node;
				}
			}
		}
	}
}

int main()
{
	polynomial P;
	CreatePolyn(P, 6);
	Traverse(P, visit);

	polynomial P2;
	CreatePolyn2(P2, 10);
	Traverse(P2, visit);

	Addpolyn(P, P2);
	Traverse(P, visit);

	printf("\n");

	polynomial P3;
	CreatePolyn(P3, 6);
	Traverse(P3, visit);
	polynomial P4;
	CreatePolyn3(P4, 4);
	Traverse(P4, visit);
	Addpolyn(P3, P4);
	Traverse(P3, visit);

	return 0;
}