#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void visit(String T)
{
	for (int i = 1; i <= T[0]; i++)
	{
		printf("%c", T[i]);
	}
	printf("\n");
}

int main()
{
	String T;
	String T2;
	Create(T, "aaaaabbbbbfffff");
	Create(T2, "cccccdddddeeee");
	Traverse(T, visit);
	Traverse(T2, visit);
	String T3;
	Concat(T3, T, T2);
	Traverse(T3, visit);

	return 0;
}