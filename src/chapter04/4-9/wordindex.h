#include "base.h"
#include "HString.h"
#include "link.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _H_WORD_INDEX_H_
#define _H_WORD_INDEX_H_

#define MaxBookNum 1000    // ����ֻ��1000���齨������
#define MaxKeyNum 2500     // ��������������
#define MaxLineLen 500     // ��Ŀ������󳤶�
#define MaxWordNum 10      // �ʱ���������

// �ʱ�����(˳���)
typedef struct 
{
	char * item[MaxWordNum + 1];   // �ַ���������
	int last;		 // �ʱ�ĳ���
}WordListType;

typedef int WordElemType;	// �������������Ԫ������Ϊ����(�������)

// �������
typedef struct
{
	HString key;	// �ؼ���
	LinkList bnolist;	// ����������������
}IdxTermType;           // ����������

// ���
typedef struct
{
	IdxTermType item[MaxKeyNum + 1];
	int last;
}IdxListType;	// ���������ͣ������

// ��ʼ����������������idxlistΪ�ձ�����idxlist.item[0]��һ�մ�
void InitIdxList(IdxListType &idxlist);

// ���ļ�F����һ����Ŀ��Ϣ����Ŀ��������buf
void GetLine(FILE * f, char * &Buffer);

// ��buf����ȡ�����ؼ��ʵ��ʱ�wdlist����Ŵ���bno
void ExtractKeyWord(char * Buffer, WordListType &w, int &bno);

// �����Ϊbno�������ؼ��ʰ��ʵ�˳�����������idxlist
Status InsIdxList(IdxListType &idxlist, WordElemType bno, WordListType wdlist);

// �����ɵ�������idxlist������ļ�g
void PutText(FILE *g,IdxListType idxlist);

// ��wd���شʱ�wdlist�е�i���ؼ��ʡ�
void GetWord(int i, HString &wd, WordListType wdlist);

// ��������idxlist�в�ѯ�Ƿ������wd��ȵĹؼ��ʡ������ڣ��򷵻������������е�λ�ã���bȡֵTRUE�����򷵻ز���λ�ã���bȡֵFALSE
int Locate(IdxListType &idxlist, HString wd, Status &b, WordListType wdlist);

// ��������idxlist�ĵ�i���ϲ����¹ؼ���wd������ʼ���������������Ϊ�ձ�
void InsertNewKey(IdxListType &idxlist, int i, HString wd);

// ��������idxlist�ĵ�i���в������Ϊbno������
Status InsertBook(IdxListType &idxlist, int i, int bno);

#endif