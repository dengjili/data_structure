#include "base.h"

#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef int ElemType;

#define MAX_ARRAY_DIM 8
typedef struct 
{
	// ����Ԫ�ػ�ַ����InitArray����
	ElemType * base;
	int dim;
	// ����ά���ַ����InitArray����,�洢��ά�ĳ��ȵ�����
	int * bounds;
	// ����ӳ����������ַ����ʵ����ci��ȷ��˵���Ǽ����洢��Ԫ��
	int * constants;
}Array;

// ��ά��dim�����ĸ�ά���ȺϷ�,������Ӧ������A,������OK
Status InitArray(Array &A, int dim, ...);
// ��������A
Status DestroyArray(Array &A);
// A��nά����,eΪԪ�ر���,�����n���±�ֵ��
// �����±겻����,��e��ֵΪ��ָ����A��Ԫ��ֵ,������OK
Status Value(ElemType &e, Array A, ...);
// A��nά����,eΪԪ�ر���,�����n���±�ֵ��
// ���±겻����,��e��ֵ������ָ����A��Ԫ��,������OK
Status Assign(Array &A, ElemType e, ...);

#endif