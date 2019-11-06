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
	Create(T, "aaaaabbbbbfffff");
	Traverse(T, visit);
	String T5;
	SubString(T5, T, 5, 5);
	Traverse(T5, visit);

	return 0;
}