#include "base.h"

#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

typedef struct 
{
	int coef; //ϵ��
	int expn; //ָ��
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

// ����m���ϵ����ָ��,������ʾһԪ����ʽ����������
void CreatePolyn(polynomial &P, int m);
// ����һԪ����ʽP
void DestroyPolyn(polynomial &P);
// ��ӡ���һԪ����ʽP
void PrintPolyn(polynomial P);
// ����һԪ����ʽP�е�����
int polynLength(polynomial P);
// ��ɶ���ʽ�������,��:Pa=Pa+Pb,������һԪ����ʽPb
void Addpolyn( polynomial &Pa, polynomial &Pb);
// ��ɶ���ʽ�������,��:Pa=Pa-Pb,������һԪ����ʽPb
void SubtractPolym(polynomial &Pa, polynomial &pb);
// ��ɶ���ʽ�������,��:Pa=Pa*Pb,������һԪ����ʽPb
void Multiplypolyn(polynomial &Pa, polynomial &Pb);
// ��a��ָ��ֵ<(��=)(��>)b��ָ��ֵ,�ֱ𷵻�-1��0��+
int cmp(ElemType a, ElemType b);


#endif