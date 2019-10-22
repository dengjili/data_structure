#include <stdio.h>
#include "base.h"
#include "list.h"

void visit(List L)
{
	for (ElemType * e = L.elem; e <  (L.elem + L.length); e++)
	{
		printf("%d ", * e);
	}
	printf("\n");
}

Status equal(ElemType e1, ElemType e2)
{
	return e1 == e2 ? TRUE : FALSE;
}

void MergeSort(List &Lc, List La, List Lb)
{
	ElemType * la_end = La.elem + La.length;
	ElemType * lb_end = Lb.elem + Lb.length;

	ElemType * la_begin = La.elem;
	ElemType * lb_begin = Lb.elem;
	while (la_begin < la_end && lb_begin < lb_end)
	{
		if (* la_begin < * lb_begin)
		{
			Insert(Lc, Lc.length + 1, * la_begin);
			la_begin++;
		}
		else
		{
			Insert(Lc, Lc.length + 1, * lb_begin);
			lb_begin++;
		}
	}

	while (la_begin < la_end)
	{
		Insert(Lc, Lc.length + 1, * la_begin);
		la_begin++;
	}

	while (lb_begin < lb_end)
	{
		Insert(Lc, Lc.length + 1, * lb_begin);
		lb_begin++;
	}
}

int main()
{
	List La, Lb;
	Init(La);
	Init(Lb);
	for (int i = 1; i < 13; i++)
	{
		Insert(La, i, i * 3);
	}
	for (int i = 1; i < 23; i++)
	{
		Insert(Lb, i, i * 2);
	}
	Traverse(La, visit);
	Traverse(Lb, visit);

	List Lc;
	Init(Lc);

	MergeSort(Lc, La, Lb);
	Traverse(Lc, visit);
	printf("La length = %d\n", Length(La));
	printf("Lb length = %d\n", Length(Lb));
	printf("Lc length = %d\n", Length(Lc));
	return 0;
}