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

	String T2;
	Create(T2, "abb");
	Traverse(T2, visit);
	printf("index=%d\n", Index(T, T2, 1));

	return 0;
}