#include "base.h"

#ifndef _H_STRING_H_
#define _H_STRING_H_

typedef struct 
{
	char * ch;
	int len;
}HString;

Status StrCreate(HString &S, char ch[], int len);
Status StrInsert(HString &S, int pos, HString T);

#endif