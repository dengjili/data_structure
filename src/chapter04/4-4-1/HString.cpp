#include <stdlib.h>
#include "HString.h"

Status Init(HString &T)
{
	T.ch = NULL;
	T.len = 0;
	return OK;
}

// ����һ����ֵ���ڴ����� chars�Ĵ�T
Status StrAssign(HString &T, char * chars)
{
	if (T.ch)
	{
		free(T.ch);
		T.ch = NULL;
	}

	int len = 0;
	while (* (chars + len) != '\0')
	{
		len++;
	}

	if (len > 0)
	{
		T.ch = (char *) malloc(sizeof(char) * len);
		if (!T.ch)
		{
			exit(OVERFLOW);
		}

		// copy
		for (int i = 0; i < len; i++)
		{
			* (T.ch + i) = * (chars + i);
		}
		T.len = len;
	}

	return len;
}

// ����S��Ԫ�ظ���,��Ϊ���ĳ���
int StrLength(HString S)
{
	return S.len;
}

// ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T�򷵻�ֵ<0
int StrCompare(HString S, HString T)
{
	for (int i = 0; i < S.len && i < T.len; i++)
	{
		if (S.ch[i] != T.ch[i])
		{
			return S.ch[i] - T.ch[i];
		}
	}

	return S.len - T.len;
}

// ��S��Ϊ�մ�,���ͷ�S��ռ�ռ䡣
Status ClearString(HString &T)
{
	if (T.ch)
	{
		free(T.ch);
		T.ch = NULL;
	}
	T.len = 0;
	return OK;
}

// ��T������S1��S2���Ӷ��ɵ��´�
Status Concat(HString &T, HString S1, HString S2)
{
	if (T.ch)
	{
		free(T.ch);
	}

	if (S1.len + S2.len > 0)
	{
		T.ch = (char *) malloc(sizeof(char) * (S1.len + S2.len));
		if (!T.ch)
		{
			exit(OVERFLOW);
		}

		// copy
		for (int i = 0; i < S1.len; i++)
		{
			* (T.ch + i) = * (S1.ch + i);
		}
		for (int i = 0; i < S2.len; i++)
		{
			* (T.ch + i + S1.len) = * (S2.ch + i);
		}
		T.len = S1.len + S2.len;
	}

	return OK;
}

// 1��pos�� StrEngth(S)��0��1en�� StrEngth(S)-pos+1��
// ���ش�S�ĵ�pos���ַ��𳤶�Ϊ1en���Ӵ���
Status SubString(HString &sub, HString S, int pos, int len)
{
	if (pos < 1 || pos > S.len || len < 0 || len > S.len - pos + 1)
	{
		return ERROR;
	}
	if (sub.ch)
	{
		free(sub.ch);
	}

	if (len == 0)
	{
		sub.ch = NULL;
		sub.len = 0;
	}
	else
	{
		sub.ch = (char *) malloc(sizeof(char) * len);
		if (!sub.ch)
		{
			exit(OVERFLOW);
		}

		// copy
		for (int i = 0; i < len; i++)
		{
			sub.ch[i] = S.ch[pos - 1 + i];
		}
		sub.len = len;
	}

	return OK;
}
