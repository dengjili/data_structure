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

void Union(List &La, List Lb)
{
	ElemType e;
	int b_len = Length(Lb);
	Status status;
	// 1. ����Lb
	for (int i = 1; i <= b_len; i++)
	{
		// 2. ȡ����i��Ԫ��
		status = Get(Lb, i, e);
		// 3. �ж�La���Ƿ����Ԫ��e�����������������
		if (status == OK && Locate(La, e, equal) == FALSE )
		{
			Insert(La, La.length + 1, e);
		}
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

	Union(La, Lb);
	Traverse(La, visit);
	return 0;
}