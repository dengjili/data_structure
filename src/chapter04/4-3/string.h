#include "base.h"

#ifndef _STRING_H_
#define _STRING_H_

#define MAX_STRING_LEN 255

// 下标为0存放串长度
typedef unsigned char String[MAX_STRING_LEN + 1];

Status Create(String &T, char str[]);
void Traverse(String T, void (* visit)(String));
Status Concat(String &T, String T1, String T2);
Status SubString(String &Sub, String S, int pos, int len);

int Index(String S, String T, int pos);




#endif