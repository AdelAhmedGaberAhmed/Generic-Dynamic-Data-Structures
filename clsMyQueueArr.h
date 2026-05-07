#pragma once
#include "clsDynamicArray.h"
#include <iostream>

template <class T> class clsMyQueueArr
{

protected:
	clsDynamicArray <T> _MyDynamicArr;

public:
	void Push(T data)
	{
		_MyDynamicArr.InsertAtEnd(data);
	}

	void Pop()
	{
		_MyDynamicArr.DeleteFirstItem();
	}
	void Print()
	{
		if (_MyDynamicArr.IsEmpty())
			cout << "Queue Is Empty\n";
		_MyDynamicArr.PrintList();

	}
	void Reverse()
	{
		_MyDynamicArr.Reverse();
	}

	int  Size()
	{
		return _MyDynamicArr.Size();
	}

	T Front()
	{
		return _MyDynamicArr.GetItem(0);
	}
	T Back()
	{
		return _MyDynamicArr.GetItem(_MyDynamicArr.Size() - 1);
	}

	T GetItem(int index)
	{
		return _MyDynamicArr.GetItem(index);
	}

	void InsertAfter(int index , T data)
	{
		_MyDynamicArr.InsertAfter(index, data);
	}

	void InsertBefor(int index, T data)
	{
		_MyDynamicArr.InsertBefor(index, data);
	}

	void UpdateItem(int index, T Newdata)
	{
		_MyDynamicArr.SetItem(index, Newdata);
	}

	bool IsEmpty()
	{
		return _MyDynamicArr.IsEmpty();
	}

	void InsertAtFront(T data)
	{
		_MyDynamicArr.InsertAtBeginning(data);
	}

	void InsertAtBack(T data)
	{
		_MyDynamicArr.InsertAtEnd(data);
	}

	void Clear()
	{
		_MyDynamicArr.Clear();
	}
};

