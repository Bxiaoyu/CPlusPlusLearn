#pragma once
#ifndef _HSTRING_H_
#define _HSTRING_H_
#include "C.h"

class HString
{
private:
	char* ch;
	int length;  // 串长度
public:
	HString()
	{
		ch = nullptr;
		length = 0;
	}

	HString(const char* str)
	{
		length = strlen(str);
		ch = new char[length];
		assert(ch != nullptr);
		for (int i = 0; i < length; ++i)  // 复制str到ch
		{
			ch[i] = str[i];
		}
	}

	HString(const HString& s)
	{
		length = s.length;
		ch = new char[length];
		assert(ch != nullptr);
		for (int i = 0; i < length; ++i)
		{
			ch[i] = s.ch[i];
		}
	}

	~HString()
	{
		ClearString();
	}

	void ClearString()
	{
		if (ch != nullptr)  // 串不空
		{
			delete[] ch;
			ch = nullptr;  // ch不指向任何存储空间
		}
		length = 0;
	}

	void StrAssign(const char* str)
	{
		ClearString();
		length = strlen(str);
		if (length)
		{
			ch = new char[length];
			assert(ch != nullptr);
			for (int i = 0; i < length; ++i)
			{
				ch[i] = str[i];
			}
		}
	}

	void StrCopy(const HString& s)
	{
		ClearString();
		ch = new char[s.length];
		assert(ch != nullptr);
		for (int i = 0; i < s.length; ++i)
		{
			ch[i] = s.ch[i];
		}
		length = s.length;
	}

	bool IsEmpty() const
	{
		return length == 0;
	}

	int StrCompare(const HString& s) const
	{
		for (int i = 0; i < length && i < s.length; ++i)
		{
			if (ch[i] != s.ch[i])
			{
				return ch[i] - s.ch[i];
			}
		}
		return length - s.length;
	}

	int Length() const
	{
		return length;
	}

	void Concat(const HString& s1, const HString& s2)
	{
		int i;
		ClearString();
		length = s1.length + s2.length;
		ch = new char[length];
		assert(ch != nullptr);
		for (i = 0; i < s1.length; ++i)
		{
			ch[i] = s1.ch[i];
		}
		for (i = 0; i < s2.length; ++i)
		{
			ch[s1.length + i] = s2.ch[i];
		}
	}

	bool SubString(HString& sub, int pos, int len) const
	{
		if (pos < 1 || pos > length || len < 0 || len > length - pos + 1)
		{
			return false;
		}
		sub.ClearString();
		if (len)
		{
			sub.ch = new char[len];
			assert(sub.ch != nullptr);
			for (int i = 0; i < len; ++i)
			{
				sub.ch[i] = ch[pos + i - 1];
			}
			sub.length = len;
		}
		return true;
	}

	bool StrInsert(int pos, const HString& s)
	{
		int i;
		char* p;
		if (pos	< 1 || pos > length + 1)  // pos不合法
		{
			return false;
		}
		if (s.length)
		{
			p = new char[length + s.length];
			assert(p != nullptr);
			length += s.length;
			for (i = 0; i < pos - 1; ++i)
			{
				p[i] = ch[i];
			}
			for (i = 0; i < s.length; ++i)
			{
				p[pos + i - 1] = s.ch[i];
			}
			for (i = pos - 1; i < length; ++i)
			{
				p[i + s.length] = ch[i];
			}
			delete[] ch;
			ch = p;
		}
		return true;
	}

	bool StrDelete(int pos, int len)
	{
		int i;
		char* p;
		if (length < pos + len - 1)
		{
			return false;
		}
		p = new char[length - len];
		assert(p != nullptr);
		for (i = 0; i < pos - 1; ++i)
		{
			p[i] = ch[i];
		}
		for (i = pos - 1; i < length - len; ++i)
		{
			p[i] = ch[i + len];
		}
		length -= len;
		delete[] ch;
		ch = p;
		return true;
	}

	void StrPrint() const
	{
		for (int i = 0; i < length; ++i)
		{
			cout << ch[i];
		}
		cout << endl;
	}

	int Index(const HString& s, int pos) const
	{
		HString sub;
		if (pos > 0)
		{
			for (int i = pos; i <= length - s.length + 1; ++i)
			{
				SubString(sub, i, s.length);
				if (sub.StrCompare(s) == 0)
				{
					return i;
				}
			}
		}
		return 0;
	}

	bool RePlace(const HString& T, const HString& V)
	{
		int i = 1;
		if (!T.length)
		{
			return false;
		}

		while (i)
		{
			i = Index(T, i);
			if (i)
			{
				StrDelete(i, T.length);
				StrInsert(i, V);
				i += V.length;
			}
		}
		return true;
	}
};

#endif