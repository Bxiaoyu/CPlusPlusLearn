#pragma once
#ifndef _STLINKLIST_H_
#define _STLINKLIST_H_

const int MAX_SIZE = 10;  // ��̬�������󳤶ȣ�����ʵ��Ӧ����ƣ�

namespace NPSTLinkList
{
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
		}
	};
}

#endif