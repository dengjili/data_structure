#include <stdlib.h>
#include "HString.h"

Status StrCreate(HString &S, char ch[], int len)
{
	S.ch = (char *)malloc(len * sizeof(char));
	S.len = len;
	
	for (int i = 0; i < S.len; i++)
	{
		S.ch[i] = ch[i];
	}

	return OK;
}

Status StrInsert(HString &S, int pos, HString T)
{
	if (pos < 1 || pos > S.len + 1)
	{
		return ERROR;
	}

	if (T.len > 0)
	{
		S.ch = (char *)realloc(S.ch, (S.len + T.len) * sizeof(char));
		if (!S.ch)
		{
			exit(OVERFLOW);
		}

		// 1.move
		for (int i = S.len - 1; i >= pos - 1; i--)
		{
			S.ch[i + T.len] = S.ch[i];
		}
		// 2.copy
		for (int i = 0; i < T.len; i++)
		{
			S.ch[pos - 1 + i] = T.ch[i];
		}
		S.len += T.len;
	}

	return OK;
}