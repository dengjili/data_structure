#include "base.h"

#ifndef _H_STRING_H_
#define _H_STRING_H_

typedef struct 
{
	char * ch;
	int len;
}HString;

/** ���������ĺ���ԭ��˵�� */

Status Init(HString &T);

// ����һ����ֵ���ڴ����� chars�Ĵ�T
Status StrAssign(HString &T, char* chars);

// ����S��Ԫ�ظ���,��Ϊ���ĳ���
int StrLength(HString S);

// ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T�򷵻�ֵ<0
int StrCompare(HString S, HString T);

// ��S��Ϊ�մ�,���ͷ�S��ռ�ռ䡣
Status ClearString(HString &S);

// ��T������S1��S2���Ӷ��ɵ��´�
Status Concat(HString &T, HString S1, HString S2);

// 1��pos�� StrEngth(S)��0��1en�� StrEngth(S)-pos+1��
// ���ش�S�ĵ�pos���ַ��𳤶�Ϊ1en���Ӵ���
Status SubString(HString &sub, HString S, int pos, int len);

#endif