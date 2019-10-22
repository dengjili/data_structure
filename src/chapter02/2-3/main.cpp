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
	
	Traverse(La, visit);
	printf("La length = %d\n", Length(La));
	
	return 0;
}