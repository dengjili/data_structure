#include <stdio.h>
#include <stdlib.h>
#include "HString.h"

void Traverse(HString T)
{
	for (int i = 0; i < T.len; i++)
	{
		printf("%c", T.ch[i]);
	}
	printf("\n");
}

int main()
{
	HString T;
	StrCreate(T, "aaaaabbbbbfffff", 15);
	Traverse(T);
	HString T2;
	StrCreate(T2, "eeeee", 5);
	Traverse(T2);

	StrInsert(T, 6, T2);
	Traverse(T);

	return 0;
}