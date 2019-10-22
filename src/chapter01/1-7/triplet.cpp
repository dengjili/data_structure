#include <stdlib.h>
#include <stdio.h>
#include "triplet.h"

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3)
{
	T = (Triplet) malloc(sizeof(ElemType) * 3);
	if (!T)
	{
		return ERROR;
	}
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;
	return OK;
}

Status DestroyTriplet(Triplet T)
{
	free(T);
	T = NULL;
	return OK;
}

Status Get(Triplet T, int i, ElemType &e)
{
	if (i >= 1 && i <= 3)
	{
		e = T[i -  1];
		return OK;
	}
	return ERROR;
}

Status Put(Triplet &T, int i, ElemType e)
{
	if (i >= 1 && i <= 3)
	{
		T[i -  1] = e;
		return OK;
	}
	return ERROR;
}

Status IsAscending(Triplet T)
{
	return T[0] <= T[1] && T[1] <= T[2];
}

Status IsDescending(Triplet T)
{
	return !(IsAscending(T));
}

Status Max(Triplet T, ElemType &e)
{
	ElemType max = T[0] > T[1] ? T[0] : T[1];
	e =  max > T[2] ? max : T[2];
	return OK;
}

Status Min(Triplet T, ElemType &e)
{
	ElemType min = T[0] < T[1] ? T[0] : T[1];
	e =  min < T[2] ? min : T[2];
	return OK;
}

void print(Triplet T)
{
	printf("index 0 value : %d\n", T[0]);
	printf("index 1 value : %d\n", T[1]);
	printf("index 2 value : %d\n", T[2]);
}