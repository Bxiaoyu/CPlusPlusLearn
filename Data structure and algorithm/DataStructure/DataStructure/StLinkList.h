#pragma once
#ifndef _STLINKLIST_H_
#define _STLINKLIST_H_

const int MAX_SIZE = 10;  // 静态链表的最大长度（根据实际应用设计）

namespace NPSTLinkList
{
	template<typename T>
	class StLinkList
	{
		struct component
		{
			T data;
			int link;  // 链接指针，指示下一个元素的位置
		};

	private:
		component SL[MAX_SIZE];
	private:
		int NEW()
		{
			int i = SL[MAX_SIZE - 1].link;  // 备用链表第一个结点的位置
			if (i)  // 备用链表非空
			{
				SL[MAX_SIZE - 1].link = SL[i].link;  // 备用链表的头结点指向原备用链表的第二个结点
			}
			return i;
		}

		void DELETE(int k)
		{
			SL[k].link = SL[MAX_SIZE - 1].link;  // 回收结点的下标指向备用链表的第一个结点
			SL[MAX_SIZE - 1].link = k;  // 备用链表的头结点指向新回收的结点
		}
	public:
		StLinkList()
		{
			int i;
			SL[0].link = 0;  // SL[0]为空链表表头
			SL[MAX_SIZE - 1].link = 1;  // 1为备用链表的第一个单元
			for (i = 1; i < MAX_SIZE - 2; ++i)
			{
				SL[i].link = i + 1;
			}
			SL[MAX_SIZE - 2].link = 0;
		}

		void ClearList()
		{
			int j, i = SL[MAX_SIZE - 1].link;  // i指示备用链表第一个结点位序
			while (i)  // 未到备用链表尾
			{
				j = i;  // j指示当前结点的位序
				i = SL[i].link;  // i指向下一个结点位序
			}
			SL[j].link = SL[0].link;  // 链表的第一个结点接到备用结点的尾部
			SL[0].link = 0;  // 链表空
		}

		bool ListEmpty() const
		{
			return SL[0].link == 0;  // 空表头结点的link域为0
		}

		int ListLength() const
		{
			int j = 0;
			int i = SL[0].link;  // i指示链表的第一个结点的位序
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
				if (eq(e, SL[i].data) && SL[i].link)  // 找到该元素并有后继
				{
					next_e = SL[SL[i].link].data;  // 将e的后继赋值给next_e
					return true;
				}
				i = SL[i].link;
			}
			return false;
		}

		bool ListInsert(int i, T e)
		{
			int m, k = 0;  // k指示表头节点的位序
			for (m = 1; m < i; ++m)  // 使k指示第i-1个结点
			{
				k = SL[k].link;
				if (k == 0)  // 已到表尾
				{
					break;
				}
			}
			if (m < i)  // 表中没有第i-1个结点
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