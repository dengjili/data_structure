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

int main()
{
	List La;
	Init(La);
	for (int i = 1; i < 13; i++)
	{
		Insert(La, i, i);
	}
	
	ElemType e;
	Delete(La, 5, e);
	Traverse(La, visit);
	printf("e = %d\n", e);
	
	return 0;
}