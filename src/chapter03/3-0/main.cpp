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


int main()
{
	Stack S;
	Init(S);

	for (int i = 1; i <= 5; i++)
	{
		Push(S, i);
	}
	Traverse(S, visit);

	return 0;
}