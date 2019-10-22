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
	return e1 == e2 ? OK : ERROR;
}

int main()
{
	List L;
	ElemType e;
	
	Status s = Init(L);
	if (s == OK)
	{
		printf("init success!\n");
	}
	for (int i = 1; i < 13; i++)
	{
		Insert(L, i, i);
	}
	Delete(L, 4, e);
	Traverse(L, visit);

	int index = Locate(L, 10, equal);
	printf("index = %d\n", index);

	return 0;
}