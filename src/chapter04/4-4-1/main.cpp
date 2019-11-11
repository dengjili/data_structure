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
	Init(T);
	StrAssign(T, "asdf");
	Traverse(T);
	HString S;
	Init(S);
	StrAssign(S, "bbbb");
	Traverse(S);
	printf("compare=%d\n", StrCompare(T, S));

	HString T3;
	Init(T3);
	Concat(T3, T, S);
	Traverse(T3);

	SubString(T, T3, 2, 4);
	Traverse(T);

	return 0;
}