#include <stdio.h>
#include "base.h"
#include "triplet.h"

int main()
{
	Triplet T;
	ElemType e;
	// 初始化
	Status status = InitTriplet(T, 1, 3, 2);
	if (status == OK)
	{
		printf("success init\n");
	}
	else
	{
		printf("failed init\n");
	}

	// 获取元素
	Get(T, 2, e);
	printf("index 1 value : %d\n", e);
	// 设置元素
	Put(T, 2, 100);
	Get(T, 2, e);
	printf("index 1 value : %d\n", e);
	// 是否升序
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

	// 销毁
	DestroyTriplet(T);

	return 0;
}