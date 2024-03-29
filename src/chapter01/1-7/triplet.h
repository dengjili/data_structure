#include "base.h"

#ifndef _TRIPLET_H_
#define _TRIPLET_H_

// 所有的类型都统一定义为ElemType
typedef int ElemType;

typedef ElemType * Triplet;

Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3);
Status DestroyTriplet(Triplet T);
Status Get(Triplet T, int i, ElemType &e);
Status Put(Triplet &T, int i, ElemType e);
Status IsAscending(Triplet T);
Status IsDescending(Triplet T);
Status Max(Triplet T, ElemType &e);
Status Min(Triplet T, ElemType &e);
void print(Triplet T);

#endif