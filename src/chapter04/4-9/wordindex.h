#include "base.h"
#include "HString.h"
#include "link.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _H_WORD_INDEX_H_
#define _H_WORD_INDEX_H_

#define MaxBookNum 1000    // 假设只对1000本书建索引表
#define MaxKeyNum 2500     // 索引表的最大容量
#define MaxLineLen 500     // 书目串的最大长度
#define MaxWordNum 10      // 词表的最大容量

// 词表类型(顺序表)
typedef struct 
{
	char * item[MaxWordNum + 1];   // 字符串的数组
	int last;		 // 词表的长度
}WordListType;

typedef int WordElemType;	// 定义链表的数据元素类型为整型(书号类型)

// 基础项定义
typedef struct
{
	HString key;	// 关键词
	LinkList bnolist;	// 存放书号索引的链表
}IdxTermType;           // 索引项类型

// 组合
typedef struct
{
	IdxTermType item[MaxKeyNum + 1];
	int last;
}IdxListType;	// 索引表类型（有序表）

// 初始化操作，置索引表idxlist为空表，且在idxlist.item[0]设一空串
void InitIdxList(IdxListType &idxlist);

// 从文件F读入一个书目信息到书目串缓冲区buf
void GetLine(FILE * f, char * &Buffer);

// 从buf中提取书名关键词到词表wdlist，书号存入bno
void ExtractKeyWord(char * Buffer, WordListType &w, int &bno);

// 将书号为bno的书名关键词按词典顺序插入索引表idxlist
Status InsIdxList(IdxListType &idxlist, WordElemType bno, WordListType wdlist);

// 将生成的索引表idxlist输出到文件g
void PutText(FILE *g,IdxListType idxlist);

// 用wd返回词表wdlist中第i个关键词。
void GetWord(int i, HString &wd, WordListType wdlist);

// 在索引表idxlist中查询是否存在与wd相等的关键词。若存在，则返回其在索引表中的位置，且b取值TRUE；否则返回插入位置，且b取值FALSE
int Locate(IdxListType &idxlist, HString wd, Status &b, WordListType wdlist);

// 在索引表idxlist的第i项上插入新关键词wd，并初始化书号索引的链表为空表
void InsertNewKey(IdxListType &idxlist, int i, HString wd);

// 在索引表idxlist的第i项中插入书号为bno的索引
Status InsertBook(IdxListType &idxlist, int i, int bno);

#endif