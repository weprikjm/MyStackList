#include "MyLinkedList.h"

template<class TYPE>
class MyStackList
{
public:
	MyStackList(){}

	void Push(const TYPE& n)
	{
		list.PushFront(n);
	}

	bool Pop(TYPE& n)
	{
		return list.PopFront(n);
	}

	MyLinkedList<TYPE> list;
};