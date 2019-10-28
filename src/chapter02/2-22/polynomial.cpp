#include <stdlib.h>
#include "polynomial.h"
#include "link.h"

Status equal(int e1, int e2)
{
	return e1 == e2 ? TRUE : FALSE;
}

// ����m���ϵ����ָ��,������ʾһԪ����ʽ����������
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
// ����һԪ����ʽP
void DestroyPolyn(polynomial &P);
// ��ӡ���һԪ����ʽP
void PrintPolyn(polynomial P);
// ����һԪ����ʽP�е�����
int polynLength(polynomial P);
// ��ɶ���ʽ�������,��:Pa=Pa+Pb,������һԪ����ʽPb
void Addpolyn( polynomial &Pa, polynomial &Pb)
{
	// ha��hb�ֱ�ָ��Pa��Pb��ͷ���
	Position ha= GetHead(Pa);
	Position hb= GetHead(Pb);
	// qa��qb�ֱ�ָ��Ba����b�е�ǰ���
	Position qa= NextPos(Pa, ha);
	Position qb= NextPos(Pb, hb);

	while (qa && qb)
	{
		// a��bΪ�����е�ǰ�Ƚ�Ԫ��
		ElemType a = getCurElem(qa);
		ElemType b = getCurElem(qb);

		switch ( cmp(a, b))
		{
		case -1:
			// ����ʽPA�е�ǰ����ָ��ֵС
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
			// ����ʽPB�е�ǰ����ָ��ֵС
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
		// ����Pb��ʣ����
		Append(Pa, qb);
	}

	// �ͷ���Pb��ͷ���
	FreeNode(hb);
}
// ��ɶ���ʽ�������,��:Pa=Pa-Pb,������һԪ����ʽPb
void SubtractPolym(polynomial &Pa, polynomial &pb);
// ��ɶ���ʽ�������,��:Pa=Pa*Pb,������һԪ����ʽPb
void Multiplypolyn(polynomial &Pa, polynomial &Pb);
// ��a��ָ��ֵ<(��=)(��>)b��ָ��ֵ,�ֱ𷵻�-1��0��+
int cmp(ElemType a, ElemType b)
{
	int e1 = a.expn;
	int e2 = b.expn;
	return e1 < e2 ? -1 : (e1 > e2 ? 1 : 0);
}
