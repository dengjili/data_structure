#include "base.h"

#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

typedef struct 
{
	int coef; //系数
	int expn; //指数
} ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode * next;
} LNode, * Link, * Position;

typedef struct 
{
	Link head, tail;
	int len;
} LinkList;

typedef LinkList polynomial;

Status equal(int e1, int e2);

// 输人m项的系数和指数,建立表示一元多项式的有序链表
void CreatePolyn(polynomial &P, int m);
// 销毁一元多项式P
void DestroyPolyn(polynomial &P);
// 打印输出一元多项式P
void PrintPolyn(polynomial P);
// 返回一元多项式P中的项数
int polynLength(polynomial P);
// 完成多项式相加运算,即:Pa=Pa+Pb,并销毁一元多项式Pb
void Addpolyn( polynomial &Pa, polynomial &Pb);
// 完成多项式相减运算,即:Pa=Pa-Pb,并销毁一元多项式Pb
void SubtractPolym(polynomial &Pa, polynomial &pb);
// 完成多项式相乘运算,即:Pa=Pa*Pb,并销毁一元多项式Pb
void Multiplypolyn(polynomial &Pa, polynomial &Pb);
// 依a的指数值<(或=)(或>)b的指数值,分别返回-1、0和+
int cmp(ElemType a, ElemType b);


#endif