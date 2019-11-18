#include "wordindex.h"

// ��ʼ����������������idxlistΪ�ձ�����idxlist.item[0]��һ�մ�
void InitIdxList(IdxListType &idxlist)
{
	idxlist.last = 0;
}

// ���ļ�F����һ����Ŀ��Ϣ����Ŀ��������buf
void GetLine(FILE * f, char * &Buffer)
{
	Buffer = (char *) malloc(sizeof(char) * MaxLineLen);
	if (!Buffer)
	{
		exit(OVERFLOW);
	}
	fgets(Buffer, MaxLineLen, f);

	// ��Ϊ���һ��û�лس���
	int i = strlen(Buffer);
	if(Buffer[i - 1] == '\n') 
    {
		Buffer[i-1]=0;
    }
}

// ��buf����ȡ�����ؼ��ʵ��ʱ�wdlist����Ŵ���bno
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

// �����ɵ�������idxlist������ļ�g
void PutText(FILE *g,IdxListType idxlist)
{

}


// ��wd���شʱ�wdlist�е�i���ؼ��ʡ�
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

// ��������idxlist�в�ѯ�Ƿ������wd��ȵĹؼ��ʡ������ڣ��򷵻������������е�λ�ã���bȡֵTRUE�����򷵻ز���λ�ã���bȡֵFALSE
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

// �����Ϊbno�������ؼ��ʰ��ʵ�˳�����������idxlist
Status InsIdxList(IdxListType &idxlist, WordElemType bno, WordListType wdlist)
{
	for (int i = 1; i < wdlist.last; i++)
	{
		HString wd;
		Init(wd);
		GetWord(i, wd, wdlist);
		Status b;
		int j = Locate(idxlist, wd, b, wdlist);
		// ƥ�䲻�ϣ�����µ�������
		if (b == FALSE)
		{
			InsertNewKey(idxlist, j, wd);
		}
		
		// ������
		b = InsertBook(idxlist, j, bno);
		if (b == ERROR)
		{
			exit(OVERFLOW);
		}
	}

	return OK;
}

// ��������idxlist�ĵ�i���ϲ����¹ؼ���wd������ʼ���������������Ϊ�ձ�
void InsertNewKey(IdxListType &idxlist, int i, HString wd)
{
	idxlist.item[i].key = wd;
	Init(idxlist.item[i].bnolist);
	idxlist.last++;
}

// ��������idxlist�ĵ�i���в������Ϊbno������
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