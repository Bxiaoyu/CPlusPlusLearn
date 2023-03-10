#pragma once
#ifndef _DLINKSTACK_H_
#define _DLINKSTACK_H_
#include "AStack.h"
#include "DLinkList.h"

namespace DLinkStack
{
	template<typename T>
	class DLinkStack : public AStack<T>, public DLinkList<T>
	{

	};
}

#endif