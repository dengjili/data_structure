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
	// 1. 遍历Lb
	for (int i = 1; i <= b_len; i++)
	{
		// 2. 取出第i个元素
		status = Get(Lb, i, e);
		// 3. 判断La中是否包括元素e，如果不包括，插入
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