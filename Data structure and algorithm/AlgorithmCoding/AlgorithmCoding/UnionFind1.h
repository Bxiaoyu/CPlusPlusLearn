#pragma once
/*
*	���鼯��ʵ�֣�����ʵ�ַ�ʽ���ҿ�(quick find)����������
*/
#include <iostream>
#include <cassert>


namespace UF1
{
	class UnionFind
	{
	private:
		int* id;
		int count;

	public:
		UnionFind(int n)
		{
			count = n;
			id = new int[n];
			for (int i = 0; i < n; i++)  // ��ʼ��ʱ����Ԫ�ض���Ϊһ��
			{
				id[i] = i;
			}
		}

		~UnionFind()
		{
			delete[] id;
		}

		int find(int p)
		{
			assert(p >= 0 && p < count);
			return id[p];
		}

		bool isConnected(int p, int q)
		{
			return find(p) == find(q);
		}

		void unionElements(int p, int q)
		{
			int pID = find(p);
			int qID = find(q);

			if (pID == qID);
			{
				return;
			}

			for (int i = 0; i < count; i++)
			{
				if (id[i] == pID)
				{
					id[i] = qID;
				}
			}
		}
	};
}