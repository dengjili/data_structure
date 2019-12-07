#include "base.h"

#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef int ElemType;

#define MAX_ARRAY_DIM 8
typedef struct 
{
	// 数组元素基址，由InitArray分配
	ElemType * base;
	int dim;
	// 数组维界基址，由InitArray分配,存储各维的长度的数组
	int * bounds;
	// 数组映像函数常量基址，其实就是ci，确切说的是几个存储单元。
	int * constants;
}Array;

// 若维数dim和随后的各维长度合法,则构造相应的数组A,并返回OK
Status InitArray(Array &A, int dim, ...);
// 销毁数组A
Status DestroyArray(Array &A);
// A是n维数组,e为元素变量,随后是n个下标值。
// 若各下标不超界,则e赋值为所指定的A的元素值,并返回OK
Status Value(ElemType &e, Array A, ...);
// A是n维数组,e为元素变量,随后是n个下标值。
// 若下标不超界,则将e的值赋给所指定的A的元素,并返回OK
Status Assign(Array &A, ElemType e, ...);

#endif