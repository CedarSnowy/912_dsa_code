/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#pragma warning(disable : 4996 4800)
#include <cstdlib>
#include <cstdio>
#include <cmemory>

class Bitmap { //λͼBitmap�ࣺ�Կռ���Ϊ��������ʡ��ʼ��ʱ�䣨���������룬��֧��ɾ����
private:
   Rank* F; Rank N; //��ģΪN������F����¼[k]����ǵĴ��򣨼�����ջT[]�е��ȣ�
   Rank* T; Rank top; //����ΪN��ջT����¼����Ǹ�λ�ȵ�ջ���Լ�ջ��ָ��

protected:
   inline bool valid( Rank r ) { return ( 0 <= r ) && ( r < top ); }

public:
   Bitmap( Rank n = 8 ) //��ָ������Ĭ�ϣ���ģ��������ͼ��Ϊ������ʱѡ�ý�С��Ĭ��ֵ��
      { N = n; F = new Rank[N]; T = new Rank[N]; top = 0; } //��O(1)ʱ������ʽ�س�ʼ��
   ~Bitmap() { delete[] F; delete[] T; } //����ʱ�ͷſռ�

// �ӿ�
   inline void set( Rank k ) { //����
      if ( test( k ) ) return; //�����Ѵ���ǵ�λ
      F[k] = top++; T[F[k]] = k; //����У�黷
   }
   inline bool test( Rank k ) //����
      { return valid( F[k] ) && ( k == T[F[k]] ); }
};