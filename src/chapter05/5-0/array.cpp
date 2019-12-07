#include "array.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

// 若维数dim和随后的各维长度合法,则构造相应的数组A,并返回OK
Status InitArray(Array &A, int dim, ...)
{
	if (dim < 1 || dim > MAX_ARRAY_DIM)
	{
		return ERROR;
	}
	A.dim = dim;
	A.bounds = (int *) malloc(dim * sizeof(int));
	if (!A.bounds)
	{
		exit(OVERFLOW);
	}
	
	// 总长度
	int elemtotal = 1;
	va_list ap;
	va_start(ap, dim);
	for (int i = 0; i < dim; i++)
	{
		A.bounds[i] = va_arg(ap, int);
		if (A.bounds[i] < 0)
		{
			exit(OVERFLOW);
		}
		elemtotal *= A.bounds[i];
	}
	va_end(ap);
	// 分配内存
	A.base = (ElemType *) malloc(dim * sizeof(ElemType));
	if (!A.base)
	{
		exit(OVERFLOW);
	}

	// 数组映像函数常量基址，其实就是ci，确切说的是几个存储单元
	A.constants = (int *) malloc(dim * sizeof(int));
	if (!A.constants)
	{
		exit(OVERFLOW);
	}
	A.constants[dim - 1] = 1;
	for (int i = dim - 2; i >= 0; i--)
	{
		A.constants[i] = A.bounds[i + 1] * A.constants[i + 1];
	}
	return OK;
}
// 销毁数组A
Status DestroyArray(Array &A)
{
	if (!A.base)
	{
		free(A.base);
		A.base = NULL;
	}
	if (!A.bounds)
	{
		free(A.bounds);
		A.bounds = NULL;
	}
	if (!A.constants)
	{
		free(A.constants);
		A.constants = NULL;
	}

	return OK;
}

// 若ap指示的各下标值合法，则求出该元素在A中的相对地址off
Status Locate(Array A, va_list ap, int &off) 
{
	off = 0;
	for (int i = 0; i < A.dim; i++)
	{
		int ind = va_arg(ap, int);
		if (ind < 0 || ind > A.bounds[i])
		{
			return ERROR;
		}
		off += A.constants[i] * ind;
	}

	return OK;
}

// A是n维数组,e为元素变量,随后是n个下标值。
// 若各下标不超界,则e赋值为所指定的A的元素值,并返回OK
Status Value(ElemType &e, Array A, ...)
{
	va_list ap;
	va_start(ap, A);
	
	int offset = 0;
	if (Locate(A, ap, offset) != OK)
	{
		return ERROR;
	}
	e = * (A.base + offset);
	va_end(ap);

	return OK;
}
// A是n维数组,e为元素变量,随后是n个下标值。
// 若下标不超界,则将e的值赋给所指定的A的元素,并返回OK
Status Assign(Array &A, ElemType e, ...)
{
	va_list temp;
	va_start(temp, e);

	int offset = 0;
	if (Locate(A, temp, offset) != OK)
	{
		return ERROR;
	}
	* (A.base + offset) = e;
	va_end(temp);

	return OK;
}