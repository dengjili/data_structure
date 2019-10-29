#include <stdio.h>
#include "stack.h"

void visit(Stack S)
{
	SElemType e = 0;
	while (S.base != S.top)
	{
		Pop(S, e);
		printf("%d ", e);
	}
	printf("\n");
}

void conversion(int num, int scale)
{
	Stack S;
	Init(S);

	while (num > 0)
	{
		Push(S, num % scale);
		num = num / scale;	
	}

	SElemType e;
	while (!IsEmpty(S))
	{
		Pop(S, e);
		printf("%d", e);
	}
	printf("\n");

	Destroy(S);
}


int main()
{
	conversion(17, 2);
	conversion(17, 8);
	conversion(17, 16);

	return 0;
}