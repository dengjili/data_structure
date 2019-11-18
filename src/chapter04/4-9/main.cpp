#include <stdio.h>
#include <stdlib.h>
#include "HString.h"
#include "wordindex.h"

void Traverse(IdxListType idxlist)
{
	for (int i = 0; i < idxlist.last; i++)
	{
		HString key = idxlist.item[i].key;
		for (int i = 0; i < key.len; i++)
		{
			printf("%c", key.ch[i]);
		}
		LinkList bnolist = idxlist.item[i].bnolist;
		Link node = bnolist.head->next;
		while (node)
		{
			printf("->%d", node->data);
			node = node->next;
		}
		printf("\n");
		
	}
}

int main()
{
	FILE * f, * g;
	WordElemType BookNo;
	char * Buffer = NULL;
	
	if ((f = fopen("BookInfo.txt", "r")) == NULL) 
	{
		printf("ERROR in open BookInfo.txt!\n");
		exit(OVERFLOW);
	}
	
	IdxListType idxlist;
	InitIdxList(idxlist);

	while (!feof(f))
	{
		WordListType wdlist;
		wdlist.last = 0;

		GetLine(f, Buffer);
		ExtractKeyWord(Buffer, wdlist, BookNo);

		InsIdxList(idxlist, BookNo, wdlist);
	}

	// 输出到屏幕
	Traverse(idxlist);
	// 不实现输出到文件，和输出到屏幕没有什么区别
	/**if ((g = fopen("BookIdx.txt", "w")) == NULL) 
	{
		printf("ERROR in open BookIdx.txt!\n");
		exit(OVERFLOW);
	}*/
	// PutText(g, idxlist);

	printf("\n");

	return 0;
}