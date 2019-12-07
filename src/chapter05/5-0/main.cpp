#include <stdio.h>
#include "array.h"
 
// ËÄÎ¬ÑİÊ¾
int main()
{
   Array A;
   // int a[3][2][2];
   InitArray(A, 4, 3, 2, 2, 1);

   int value = 1;
   for (int i = 0; i < 3; i++)
   {
	   for (int j = 0; j < 2; j++)
	   {
			for (int k = 0; k < 2; k++)
			{
				for (int m = 0; m < 1; m++) 
				{
					printf("(x, y, z, m) = (%d, %d, %d, %d) = %d\n", i, j, k, m, value);
					Assign(A, value++, i, j, k, m);
				}
			}
	   }
   }

   int * p = A.base;
   for (int i = 0; i < 12; i++)
   {
	   printf("%d ", * (p + i));
   }
   printf("\n");

   ElemType e = 1;
   Value(e, A, 1, 1, 1, 0);
   printf("(1, 1, 1, 0) = %d\n", e);

   return 0;
}

/*
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0}
dim=1, bounds={12}, elemtotal=1 * 12 = 12, constants={1}
{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 0}}
dim=2, bounds={3, 4}, elemtotal=3 * 4 = 12, constants={4, 1}
{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}, {11, 0}}}
dim=3, bounds={3, 2, 2}, elemtotal=3 * 2 * 2 = 12, constants={4, 2, 1}
{{{{1}, {2}}, {{3}, {4}}}, {{{5}, {6}}, {{7}, {8}}}, {{{9}, {10}}, {{11}, {0}}}}
dim=4, bounds={3, 2, 2, 1}, elemtotal=3 * 2 * 2 * 1 = 12, constants={4, 2, 1, 1}
ÈıÎ¬

#include <stdio.h>
#include "array.h"
 
int main()
{
   Array A;
   // int a[3][2][2];
   InitArray(A, 3, 3, 2, 2);

   int value = 1;
   for (int i = 0; i < 3; i++)
   {
	   for (int j = 0; j < 2; j++)
	   {
			for (int k = 0; k < 2; k++)
			{
				printf("(x, y, z) = (%d, %d, %d) = %d\n", i, j, k, value);
				Assign(A, value++, i, j, k);
			}
	   }
   }

   int * p = A.base;
   for (int i = 0; i < 12; i++)
   {
	   printf("%d ", * (p + i));
   }
   printf("\n");

   ElemType e = 1;
   Value(e, A, 1, 1, 1);
   printf("(1, 1, 1) = %d\n", e);

   return 0;
}

*/