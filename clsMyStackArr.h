#pragma once
#include "clsMyQueueArr.h"
#include <iostream>

template <class T > class clsMyStackArr  : public clsMyQueueArr <T>
{
public:


	void Push(T data)
	{
		clsMyQueueArr <T>::_MyDynamicArr.InsertAtBeginning(data);
	}
	T Top()
	{
		return clsMyQueueArr<T>::Front();
	}

	T Bottom()
	{
		return clsMyQueueArr <T>::Back();
	}


};

