#include "wordindex.h"

// 初始化操作，置索引表idxlist为空表，且在idxlist.item[0]设一空串
void InitIdxList(IdxListType &idxlist)
{
	idxlist.last = 0;
}

// 从文件F读入一个书目信息到书目串缓冲区buf
void GetLine(FILE * f, char * &Buffer)
{
	Buffer = (char *) malloc(sizeof(char) * MaxLineLen);
	if (!Buffer)
	{
		exit(OVERFLOW);
	}
	fgets(Buffer, MaxLineLen, f);

	// 因为最后一行没有回车符
	int i = strlen(Buffer);
	if(Buffer[i - 1] == '\n') 
    {
		Buffer[i-1]=0;
    }
}

// 从buf中提取书名关键词到词表wdlist，书号存入bno
void ExtractKeyWord(char * Buffer, WordListType &w, int &bno)
{
	char * delim = " ";
	char * result = strtok(Buffer, delim);
	bno = atoi(result);

	int len = 6;
	char ignore_char[][10] = { "an","a","of","the","to","and" };

	for (;result != NULL; result = strtok(NULL, delim))
	{
		result = strlwr(result);

		Status isIgnore = FALSE;
		for (int j = 0; j < len; j++)
		{
			if (strcmp(result, ignore_char[j]) == 0)
			{
				isIgnore = TRUE;
				break;
			}
		}

		if (isIgnore == FALSE)
		{
			w.item[w.last] = result;
			w.last++;
		}
	}
}

// 将生成的索引表idxlist输出到文件g
void PutText(FILE *g,IdxListType idxlist)
{

}


// 用wd返回词表wdlist中第i个关键词。
void GetWord(int i, HString &wd, WordListType wdlist)
{
	char * p = * (wdlist.item + i);
	StrAssign(wd, p);
}

Status StrEqual(HString e1, HString e2)
{
	if (e1.len != e2.len)
	{
		return FALSE;
	}
	
	for (int i = 0; i < e1.len; i++)
	{
		if (* (e1.ch + i) != * (e2.ch + i))
		{
			return FALSE;
		}
	}
	return TRUE;
}

// 在索引表idxlist中查询是否存在与wd相等的关键词。若存在，则返回其在索引表中的位置，且b取值TRUE；否则返回插入位置，且b取值FALSE
int Locate(IdxListType &idxlist, HString wd, Status &b, WordListType wdlist)
{
	for (int i = 0; i < idxlist.last; i++)
	{
		if (StrEqual(idxlist.item[i].key, wd) == TRUE)
		{
			b = TRUE;
			return i;
		}
	}

	b = FALSE;
	return idxlist.last;
}

// 将书号为bno的书名关键词按词典顺序插入索引表idxlist
Status InsIdxList(IdxListType &idxlist, WordElemType bno, WordListType wdlist)
{
	for (int i = 1; i < wdlist.last; i++)
	{
		HString wd;
		Init(wd);
		GetWord(i, wd, wdlist);
		Status b;
		int j = Locate(idxlist, wd, b, wdlist);
		// 匹配不上，添加新的索引项
		if (b == FALSE)
		{
			InsertNewKey(idxlist, j, wd);
		}
		
		// 添加书号
		b = InsertBook(idxlist, j, bno);
		if (b == ERROR)
		{
			exit(OVERFLOW);
		}
	}

	return OK;
}

// 在索引表idxlist的第i项上插入新关键词wd，并初始化书号索引的链表为空表
void InsertNewKey(IdxListType &idxlist, int i, HString wd)
{
	idxlist.item[i].key = wd;
	Init(idxlist.item[i].bnolist);
	idxlist.last++;
}

// 在索引表idxlist的第i项中插入书号为bno的索引
Status InsertBook(IdxListType &idxlist, int i, int bno)
{
	Link p = NULL;
	Status status = MakeNode(p, bno);
	if (!p)
	{
		return ERROR;
	}
	Append(idxlist.item[i].bnolist, p);
	return OK;
}