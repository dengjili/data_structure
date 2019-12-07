#include "array.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

// ��ά��dim�����ĸ�ά���ȺϷ�,������Ӧ������A,������OK
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
	
	// �ܳ���
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
	// �����ڴ�
	A.base = (ElemType *) malloc(dim * sizeof(ElemType));
	if (!A.base)
	{
		exit(OVERFLOW);
	}

	// ����ӳ����������ַ����ʵ����ci��ȷ��˵���Ǽ����洢��Ԫ
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
// ��������A
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

// ��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A�е���Ե�ַoff
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

// A��nά����,eΪԪ�ر���,�����n���±�ֵ��
// �����±겻����,��e��ֵΪ��ָ����A��Ԫ��ֵ,������OK
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
// A��nά����,eΪԪ�ر���,�����n���±�ֵ��
// ���±겻����,��e��ֵ������ָ����A��Ԫ��,������OK
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