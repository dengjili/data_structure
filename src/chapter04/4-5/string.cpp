#include "string.h"

Status Create(String &T, char str[])
{
	int index = 0;
	while (str[index] != '\0')
	{
		T[index + 1] = str[index];
		index++;
	}
	T[0] = index;

	return OK;
}

void Traverse(String T, void (* visit)(String))
{
	(* visit)(T);
}

Status Concat(String &T, String T1, String T2)
{
	Status uncut = OK;
	// 能够存下来所有的字符
	if (T1[0] + T2[0] <= MAX_STRING_LEN)
	{
		for (int i = 1; i <= T1[0]; i++)
		{
			T[i] = T1[i];
		}
		for (int i = 1; i <= T2[0]; i++)
		{
			T[i + T1[0]] = T2[i];
		}
		T[0] = T1[0] + T2[0];
	}
	else if (T1[0] < MAX_STRING_LEN)
	{
		for (int i = 1; i <= T1[0]; i++)
		{
			T[i] = T1[i];
		}
		for (int i = 1; i + T1[0] <= MAX_STRING_LEN; i++)
		{
			T[i + T1[0]] = T2[i];
		}
		T[0] = MAX_STRING_LEN;
		uncut = FALSE;
	}
	else
	{
		for (int i = 1; i <= MAX_STRING_LEN; i++)
		{
			T[i] = T1[i];
		}
		T[0] = MAX_STRING_LEN;
		uncut = FALSE;
	}

	return uncut;
}

Status SubString(String &Sub, String S, int pos, int len)
{
	if (pos < 0 || pos > S[0] || len < 0 || len  > S[0] - pos + 1)
	{
		return ERROR;
	}

	for (int i = 1; i <= len; i++)
	{
		Sub[i] = S[pos + i - 1];
	}
	Sub[0] = len;

	return OK;
}

int Index(String S, String T, int pos)
{

	if (pos < 1 || pos > S[0])
	{
		return FALSE;
	}

	int i = pos;
	int j = 1;

	while (i <= S[0] && j <= T[0])
	{
		if (S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}

	}

	if (j > T[0])
	{
		return i - T[0];
	}

	return FALSE;
}