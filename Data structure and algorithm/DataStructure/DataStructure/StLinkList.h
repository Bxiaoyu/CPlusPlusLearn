#pragma once
#ifndef _STLINKLIST_H_
#define _STLINKLIST_H_
#include "C.h"
#include "helper.h"


const int MAX_SIZE = 10;  // ��̬�������󳤶ȣ�����ʵ��Ӧ����ƣ�

namespace NPSTLinkList
{
	/*!
	 * @brief ��̬�����࣬�洢�������У������ݽṹ�ںշ��������ڲ���������Ӧ�ã�
	 * @tparam T ��������
	*/
	template<typename T>
	class StLinkList
	{
		struct component
		{
			T data;
			int link;  // ����ָ�룬ָʾ��һ��Ԫ�ص�λ��
		};

	private:
		component SL[MAX_SIZE];
	private:
		int NEW()
		{
			int i = SL[MAX_SIZE - 1].link;  // ���������һ������λ��
			if (i)  // ��������ǿ�
			{
				SL[MAX_SIZE - 1].link = SL[i].link;  // ���������ͷ���ָ��ԭ��������ĵڶ������
			}
			return i;
		}

		void DELETE(int k)
		{
			SL[k].link = SL[MAX_SIZE - 1].link;  // ���ս����±�ָ��������ĵ�һ�����
			SL[MAX_SIZE - 1].link = k;  // ���������ͷ���ָ���»��յĽ��
		}
	public:
		StLinkList()
		{
			int i;
			SL[0].link = 0;  // SL[0]Ϊ�������ͷ
			SL[MAX_SIZE - 1].link = 1;  // 1Ϊ��������ĵ�һ����Ԫ
			for (i = 1; i < MAX_SIZE - 2; ++i)
			{
				SL[i].link = i + 1;
			}
			SL[MAX_SIZE - 2].link = 0;
		}

		void ClearList()
		{
			int j, i = SL[MAX_SIZE - 1].link;  // iָʾ���������һ�����λ��
			while (i)  // δ����������β
			{
				j = i;  // jָʾ��ǰ����λ��
				i = SL[i].link;  // iָ����һ�����λ��
			}
			SL[j].link = SL[0].link;  // ����ĵ�һ�����ӵ����ý���β��
			SL[0].link = 0;  // �����
		}

		bool ListEmpty() const
		{
			return SL[0].link == 0;  // �ձ�ͷ����link��Ϊ0
		}

		int ListLength() const
		{
			int j = 0;
			int i = SL[0].link;  // iָʾ����ĵ�һ������λ��
			while (i)
			{
				i = SL[i].link;
				j++;
			}
			return j;
		}

		bool PriorElem(T e, bool(*eq)(T, T), T& pre_e) const
		{
			int i = SL[0].link;
			int j;
			do 
			{
				j = i;
				i = SL[i].link;
			} while (i && !eq(SL[i].data, e));
			if (i)
			{
				pre_e = SL[j].data;
				return true;
			}
			return false;
		}

		bool NextElem(T e, bool(*eq)(T, T), T& next_e) const
		{
			int i = SL[0].link;
			while (i)
			{
				if (eq(e, SL[i].data) && SL[i].link)  // �ҵ���Ԫ�ز��к��
				{
					next_e = SL[SL[i].link].data;  // ��e�ĺ�̸�ֵ��next_e
					return true;
				}
				i = SL[i].link;
			}
			return false;
		}

		bool ListInsert(int i, T e)
		{
			int m, k = 0;  // kָʾ��ͷ�ڵ��λ��
			for (m = 1; m < i; ++m)  // ʹkָʾ��i-1�����
			{
				k = SL[k].link;
				if (k == 0)  // �ѵ���β
				{
					break;
				}
			}
			if (m < i)  // ����û�е�i-1�����
			{
				return false;
			}
			else
			{
				m = NEW();
				if (m)
				{
					SL[m].data = e;
					SL[m].link = SL[k].link;
					SL[k].link = m;
					return true;
				}
				return false;
			}
		}

		bool ListDelete(int i, T& e)
		{
			int m, k = 0;
			for (m = 1; m < i; ++m)  // k����ƶ�i-1����㣬ʹkָʾ��i-1�����
			{
				k = SL[k].link;
				if (k == 0)
				{
					break;
				}
			}
			if (m < i || SL[k].link == 0)  // ����û�е�i-1��������û�е�i�����
			{
				return false;
			}
			else
			{
				m = SL[k].link;
				SL[k].link = SL[m].link;
				e = SL[m].data;
				DELETE(m);
				return true;
			}
		}

		void ListTraverse(void(*visit)(T*))
		{
			int i = SL[0].link;
			while (i)
			{
				visit(&SL[i].data);
				i = SL[i].link;
			}
			cout << endl;
		}
	};

	// ����
	void test_func()
	{
		StLinkList<int> list;
		int e, e0 = 3;
		bool i;
		int j, k;
		for (j = 1; j <= 5; ++j)
		{
			i = list.ListInsert(j, j);
		}
		cout << "��L�ı�β���β���1-5��L=";
		list.ListTraverse(mprint<int>);
		cout << "L�Ƿ�Ϊ�գ�" << boolalpha << list.ListEmpty() << "����L�ĳ���=";
		cout << list.ListLength() << endl;
		i = list.PriorElem(e0, equal, e);
		if (i)
		{
			cout << "Ԫ��" << e0 << "��ǰ��Ϊ" << e << endl;
		}
		else
		{
			cout << "Ԫ��" << e0 << "��ǰ����";
		}
		i = list.NextElem(e0, equal, e);
		if (i)
		{
			cout << "Ԫ��" << e0 << "�ĺ��Ϊ" << e << endl;
		}
		else
		{
			cout << "Ԫ��" << e0 << "�޺�̣�";
		}
		k = list.ListLength();
		for (j = k+1; j >= k; j--)
		{
			i = list.ListDelete(j, e);
			if (i)
			{
				cout << "ɾ����" << j << "��Ԫ�سɹ�����ֵΪ" << e << endl;
			}
			else
			{
				cout << "ɾ����" << j << "��Ԫ��ʧ�ܣ������ڴ�Ԫ�أ���";
			}
		}
		cout << "�������L��Ԫ�أ�";
		list.ListTraverse(mprint<int>);
		list.ClearList();
		cout << "���L��L=";
		list.ListTraverse(mprint<int>);
		cout << "L�Ƿ�Ϊ�գ�" << boolalpha << list.ListEmpty() << "����L�ĳ���=";
		cout << list.ListLength() << endl;
	}
}

#endif