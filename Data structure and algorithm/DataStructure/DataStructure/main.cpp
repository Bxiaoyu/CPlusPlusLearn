#include <iostream>
#include "SqList.h"
#include "LinkList.h"
#include "LinkListCy.h"
#include "DLinkList.h"
#include "LinkListNH.h"
#include "DLinkListNH.h"
#include "StLinkList.h"
#include "SqStack.h"
#include "DLinkStack.h"
//#include "LinkQueue.h"
#include "SqQueueCy.h"

using namespace std;
using namespace NPSqList;
using namespace NPLinkList;
using namespace NPLinkListCy;
using namespace NPDLinkList;
using namespace NPLinkListNH;
using namespace NPDLinkListNH;
using namespace NPSTLinkList;
using namespace NPSQSTACK;
using namespace NPDLinkStack;
//using namespace NPLinkQueue;
using namespace NPSqQueueCy;

int main(int argc, char* argv[])
{
	//NPSqList::test_func();
	//NPLinkList::test_func();
	//NPLinkListCy::test_func();
	//NPDLinkList::test_func();
	//NPLinkListNH::test_func();
	//NPDLinkListNH::test_func();
	//NPSTLinkList::test_func();
	//NPSQSTACK::test_func();
	//NPDLinkStack::test_func();
	//NPLinkQueue::test_func();
	NPSqQueueCy::test_func();
	return 0;
}