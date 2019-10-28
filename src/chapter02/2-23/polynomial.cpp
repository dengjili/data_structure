#include <stdlib.h>
#include "polynomial.h"
#include "link.h"

Status equal(int e1, int e2)
{
	return e1 == e2 ? TRUE : FALSE;
}

// 输人m项的系数和指数,建立表示一元多项式的有序链表
void CreatePolyn(polynomial &P, int m)
{
	Init(P);
	Position head = GetHead(P);
	head->data.coef = 0;
	head->data.expn = -1;

	ElemType e;
	e.coef = 0;
	e.expn = 0;

	Link node, prior_node = NULL;
	for (int i = 1; i <= m; i++)
	{
		e.coef = i;
		e.expn = i * 2;

		if (!LocateElem(P, e, prior_node, equal))
		{
 			if (MakeNode(node, e))
			{
				InsertFirst(prior_node, node);
				if (P.tail == prior_node)
				{
					P.tail = node;
				}
			}
		}
	}
}
// 销毁一元多项式P
void DestroyPolyn(polynomial &P);
// 打印输出一元多项式P
void PrintPolyn(polynomial P);
// 返回一元多项式P中的项数
int polynLength(polynomial P);
// 完成多项式相加运算,即:Pa=Pa+Pb,并销毁一元多项式Pb
void Addpolyn( polynomial &Pa, polynomial &Pb)
{
	// ha和hb分别指向Pa和Pb的头结点
	Position ha= GetHead(Pa);
	Position hb= GetHead(Pb);
	// qa和qb分别指向Ba和助b中当前结点
	Position qa= NextPos(Pa, ha);
	Position qb= NextPos(Pb, hb);

	while (qa && qb)
	{
		// a和b为两表中当前比较元素
		ElemType a = getCurElem(qa);
		ElemType b = getCurElem(qb);

		switch ( cmp(a, b))
		{
		case -1:
			// 多项式PA中当前结点的指数值小
			ha = qa;
			qa = NextPos(Pa, ha);
			break;
		case 0:
			if ((a.coef + b.coef) != 0)
			{
				SetCurElem(qa, a.coef + b.coef);
				ha = qa;
			}
			else
			{
				DeleteFirst(ha, qa);
				FreeNode(qa);
			}
			DeleteFirst(hb, qb);
			FreeNode(qb);
			qa = NextPos(Pa, ha);
			qb = NextPos(Pb, hb);
			break;
		case 1:
			// 多项式PB中当前结点的指数值小
			DeleteFirst(hb, qb);
			InsertFirst(ha, qb);

			ha = qb;
			qa = NextPos(Pa, ha);
			qb = NextPos(Pb, hb);
			break;
		}
	}

	if(!IsEmpty(Pb)) 
	{
		// 链接Pb中剩余结点
		Append(Pa, qb);
	}

	// 释放助Pb的头结点
	FreeNode(hb);
}
// 完成多项式相减运算,即:Pa=Pa-Pb,并销毁一元多项式Pb
void SubtractPolym(polynomial &Pa, polynomial &pb);
// 完成多项式相乘运算,即:Pa=Pa*Pb,并销毁一元多项式Pb
void Multiplypolyn(polynomial &Pa, polynomial &Pb);
// 依a的指数值<(或=)(或>)b的指数值,分别返回-1、0和+
int cmp(ElemType a, ElemType b)
{
	int e1 = a.expn;
	int e2 = b.expn;
	return e1 < e2 ? -1 : (e1 > e2 ? 1 : 0);
}
