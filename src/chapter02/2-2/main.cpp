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
	ElemType ea, eb;
	int len_a = Length(La);
	int len_b = Length(Lb);

	int i = 1, j = 1;
	while (i <= len_a && j <= len_b)
	{
		Get(La, i, ea);
		Get(Lb, j, eb);
		if (ea < eb)
		{
			Insert(Lc, Length(Lc) + 1, ea);
			i++;
		}
		else
		{
			Insert(Lc, Lc.length + 1, eb);
			j++;
		}
	}

	while (i <= len_a)
	{
		Get(La, i, ea);
		Insert(Lc, Length(Lc) + 1, ea);
		i++;
	}

	while (j <= len_b)
	{
		Get(Lb, j, eb);
		Insert(Lc, Lc.length + 1, eb);
		j++;
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