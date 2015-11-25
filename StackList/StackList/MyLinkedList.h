#ifndef __MYLINKEDLIST_H__
#define __MYLINKEDLIST_H__

#include "Defs.h"


template <class TYPE>
class ListNode
{
public:
	TYPE data = NULL;

	ListNode(const TYPE& data) : data(data){}

public:
	ListNode<TYPE>* next = NULL;
	
};

template <class TYPE>
class MyLinkedList
{
public:
	ListNode<TYPE>* start = NULL;


	MyLinkedList(){}
	

	~MyLinkedList(){}

	void PushBack(const TYPE& n)
	{
		ListNode<TYPE>* node = new ListNode<TYPE>(n);
		
		
		if(start == NULL)
			start = node;
		
		else
		{
			ListNode<TYPE>* tmpIterator = GetLast();
			tmpIterator->next = node;
			node->next = NULL;
		}
		
	}
	
	ListNode<TYPE>* GetLast()
	{
		ListNode<TYPE>* tmpIterator = start;

		if (tmpIterator != NULL)
		{
			while (tmpIterator->next)
			{
				tmpIterator = tmpIterator->next;
			}
		}
		return tmpIterator;
	}
	ListNode<TYPE>* GetPreviousLast()
	{
		ListNode<TYPE>* tmpIterator = start;
		
		if (tmpIterator->next != NULL)
		{
			while (tmpIterator->next->next)
			{
				tmpIterator = tmpIterator->next;
			}
		}
		return tmpIterator;
	}

	uint Size()const
	{
		ListNode<TYPE>* tmpIterator = start;
		uint count = 0;
		while (tmpIterator)
		{
			count++;
			tmpIterator = tmpIterator->next;
		}
		return count;
	}

	bool Empty()const
	{
		return start == NULL;
	}
	void Clear()
	{
		ListNode<TYPE>* tmpIterator = start;
		ListNode<TYPE>* secondTmpIterator = start;

		while (tmpIterator)
		{
			secondTmpIterator = tmpIterator;
			tmpIterator = tmpIterator->next;
			delete secondTmpIterator;
		}
		start = NULL;
	}

	ListNode<TYPE>* front(){ return start;}
	ListNode<TYPE>* back(){ return GetLast();}

	void PushFront(TYPE n)
	{
		
		ListNode<TYPE>* tmpIterator = start;


		ListNode<TYPE>* node = new ListNode<TYPE>(n);


		if (start == NULL)
			start = node;
		else
		{
			node->next = start;
			start = node;
		}

	}
	bool PopBack(TYPE& buffer)
	{
		bool ret = false;

		if (start != NULL)
		{
			ListNode<TYPE>* tmpIterator = GetLast();
			ListNode<TYPE>* tmpIteratorPrevious = GetPreviousLast();
			buffer = tmpIterator->data;
			tmpIteratorPrevious->next = NULL;
			delete tmpIterator;
			ret = true;

			if (Size() == 0)
				start = NULL;
		}


		return ret;

	}

	bool PopFront(TYPE& buffer)
	{
		bool ret = false;

		if (start != NULL)
		{
			ListNode<TYPE>* tmpIterator = start;
			buffer = tmpIterator->data;
			start = tmpIterator->next;
			delete tmpIterator;
			ret = true;
		}

		return ret;

	}
	void Insert(uint pos, TYPE data)
	{
		if (pos <= (Size() + 1) && start != NULL)//You could use PushBack anyway but I wanted to be able to put a node after the last position. That's why there's a +1 in size.
		{
			ListNode<TYPE>* tmpIterator = FindNode(pos);
			ListNode<TYPE>* newNode = new ListNode<TYPE>(data);
			newNode->next = tmpIterator;
			if (Size() >= 2)
			{
				ListNode<TYPE>* tmpIteratorPrevious = FindNode((pos - 1));
				tmpIteratorPrevious->next = newNode;
			}
			else
				start = newNode;
			
			
		}
		
	}
	void Remove(uint pos)
	{
		if (pos <= (Size()) && start != NULL)
		{
			ListNode<TYPE>* tmpIterator = FindNode(pos);
			
			if (pos >= 2)
			{
				ListNode<TYPE>* tmpIteratorPrevious = FindNode((pos - 1));
				tmpIteratorPrevious->next = tmpIterator->next;
			}
			else
			{
				start = tmpIterator->next;
			}	
				delete tmpIterator;
		}

	}


	ListNode<TYPE>* FindNode(uint pos)const
	{
		if (start != NULL)
		{
			ListNode<TYPE>* tmpIterator = start;

			for (int i = 1; i < pos; i++)
			{
				tmpIterator = tmpIterator->next;
			}

			return tmpIterator;
		}
	}


	ListNode<TYPE>* operator[](uint n)
	{
		if (n < Size())
		{
			return FindNode(n);
		}
	}

};

#endif