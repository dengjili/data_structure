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


void check(SElemType * string)
{
	Stack S;
	Init(S);

	SElemType e;
	while (* string != '\0')
	{
		printf("%c", * string);
		if (* string == '[' || * string == '(')
		{
			Push(S, * string);
		}
		else
		{
			GetTop(S, e);
			if (e== '[' && * string == ']')
			{
				Pop(S, e);
			}
			else if (e== '(' && * string == ')')
			{
				Pop(S, e);
			}
			else
			{
				Push(S, * string);
			}
		}
		string++;
	}

	if (IsEmpty(S))
	{
		printf(" OK\n");
	}
	else
	{
		printf(" ERROR\n");
	}

	Destroy(S);
}


int main()
{
	check("[](()[])");
	check("[]()[])");

	return 0;
}