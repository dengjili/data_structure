#include "base.h"

#ifndef _H_STRING_H_
#define _H_STRING_H_

typedef struct 
{
	char * ch;
	int len;
}HString;

/** 基本操作的函数原型说明 */

Status Init(HString &T);

// 生成一个其值等于串常量 chars的串T
Status StrAssign(HString &T, char* chars);

// 返回S的元素个数,称为串的长度
int StrLength(HString S);

// 若S>T,则返回值>0;若S=T,则返回值=0;若S<T则返回值<0
int StrCompare(HString S, HString T);

// 将S清为空串,并释放S所占空间。
Status ClearString(HString &S);

// 用T返回由S1和S2联接而成的新串
Status Concat(HString &T, HString S1, HString S2);

// 1≤pos≤ StrEngth(S)且0≤1en≤ StrEngth(S)-pos+1。
// 返回串S的第pos个字符起长度为1en的子串。
Status SubString(HString &sub, HString S, int pos, int len);

#endif