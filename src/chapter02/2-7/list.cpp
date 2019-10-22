#include <stdlib.h>
#include "list.h"

Status Init(List &L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
	{
		exit(OVERFLOW);
	}
	L.length = 0;
	L.size = LIST_INIT_SIZE;
	return OK;
}
void Destory(List &L)
{
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.size = 0;
}

void Clear(List &L)
{
	L.length = 0;
	L.size = 0;
}

Status IsEmpty(List L)
{
	return L.size;
}

int Length(List L)
{
	return L.length;
}

Status Get(List L, int i, ElemType &e)
{
	// 1. 合法性检查
	if (i < 1 || i > L.length)
	{
		return ERROR;
	}
	
	e = * (L.elem + i - 1);
	return OK;
}

int Locate(List L, ElemType e, Status (* compare)(ElemType, ElemType))
{
	// 位置都是从1开始
	int index = 1;
	// [begin, end) 前闭后开
	ElemType * begin = L.elem, * end = (L.elem +  L.length);
	for (; begin < end; begin++, index++)
	{
		if ((* compare)(* begin, e) == TRUE)
		{
			return index;
		}
	}
	return FALSE;
}

Status Insert(List &L, int i, ElemType e)
{
	// 1. 插入位置合法性检查
	if (i < 1 || i > L.length + 1)
	{
		return ERROR;
	}
	// 2. 是否需要扩容
	if (L.length >= L.size)
	{
		ElemType * newElem = (ElemType *)realloc(L.elem, (L.size + LIST_INCREMENT) * sizeof(ElemType));
		if (!newElem)
		{
			exit(OVERFLOW);
		}
		L.elem = newElem;
		L.size += LIST_INCREMENT;
	}

	// 3. 移动，挪出插入位置
	ElemType * begin = (L.elem + i - 1);
	for (ElemType * tail = (L.elem + L.length - 1); tail >= begin; --tail)
	{
		* (tail + 1) = * tail;
	}
	
	// 4. 将元素插入位置
	* begin = e;
	L.length++;

	return OK;
}

Status Delete(List &L, int i, ElemType &e)
{
	// 1. 插入位置合法性检查
	if (i < 1 || i > L.length)
	{
		return ERROR;
	}
	
	ElemType * begin = (L.elem + i - 1), * end = L.elem + L.length - 1;
	e = * begin;

	// 2. 移动，挪出插入位置
	for (; begin < end ; begin++)
	{
		* begin = * (begin + 1);
	}

	L.length--;
	return OK;
}


void Traverse(List L, void (* visit)(List))
{
	(* visit)(L);
}
