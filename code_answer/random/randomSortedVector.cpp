/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "UniPrint/print.h"
#include "vector/vector.h"

Vector<int> //���ɳ���Ϊn���������������Ԫ��ȡֵ����[min, max]
randomSortedVector ( Rank n, int min, int max ) { //ACP, Vol.2, Algorithm S
   /*DSA*/printf ( "creating a random sorted vector of size %d...\n", n );
   Vector<int> A;
   for ( int i = min; i <= max; i++ )
      if ( rand() % ( max - i + 1 ) < (int)n )
         { A.insert ( i ); n--; }
   return A;
}