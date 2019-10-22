#include <stdio.h>
#include "base.h"
#include "triplet.h"

int main()
{
	Triplet T;
	ElemType e;
	// ��ʼ��
	Status status = InitTriplet(T, 1, 3, 2);
	if (status == OK)
	{
		printf("success init\n");
	}
	else
	{
		printf("failed init\n");
	}

	// ��ȡԪ��
	Get(T, 2, e);
	printf("index 1 value : %d\n", e);
	// ����Ԫ��
	Put(T, 2, 100);
	Get(T, 2, e);
	printf("index 1 value : %d\n", e);
	// �Ƿ�����
	status = IsAscending(T);
	if (status == OK)
	{
		printf("is asc\n");
	}
	else
	{
		printf("is not asc\n");
	}
	
	Put(T, 3, 200);
	status = IsAscending(T);
	if (status == OK)
	{
		printf("is asc\n");
	}
	else
	{
		printf("is not asc\n");
	}

	Max(T, e);
	printf("max value : %d\n", e);
	Min(T, e);
	printf("min value : %d\n", e);

	// ����
	DestroyTriplet(T);

	return 0;
}