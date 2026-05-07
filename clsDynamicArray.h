#pragma once

#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:
    int _Size = 0;           // number of elements stored
    int _Capacity = 0;       // allocated memory size

public:
    T* OriginalArray;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;

        _Size = Size;
        _Capacity = (Size == 0 ? 1 : Size);

        OriginalArray = new T[_Capacity];
    }

    ~clsDynamicArray()
    {
        if (OriginalArray != nullptr)
            delete[] OriginalArray;
    }

    bool SetItem(int index, T Value)
    {
        if (index >= _Size || index < 0)
        {
            cout << "Index out of range!\n";
            return false;
        }

        OriginalArray[index] = Value;
        return true;
    }

    int Size() { return _Size; }
    int Capacity() { return _Capacity; }

    bool IsEmpty() { return (_Size == 0); }

    void PrintList()
    {
        for (int i = 0; i < _Size; i++)
            cout << OriginalArray[i] << " ";

        cout << "\n";
    }

    void Swap(T& A, T& B)
    {
        T temp = A;
        A = B;
        B = temp;
    }

    T GetItem(int index)
    {
        if (index < 0 || index >= _Size)
        {
            cout << "Index Out Of Range\n";
            return T();
        }

        return OriginalArray[index];
    }

    void Reverse()
    {
        for (int i = 0; i < _Size / 2; i++)
            Swap(OriginalArray[i], OriginalArray[_Size - 1 - i]);
    }

    void Clear()
    {
        delete[] OriginalArray;
        _Size = 0;
        _Capacity = 1;
        OriginalArray = new T[_Capacity];
    }

    void EnsureCapacity()
    {
        if (_Size < _Capacity)
            return;

        _Capacity = (_Capacity == 0) ? 1 : _Capacity * 2;

        T* Temp = new T[_Capacity];

        for (int i = 0; i < _Size; i++)
            Temp[i] = OriginalArray[i];

        delete[] OriginalArray;
        OriginalArray = Temp;
    }

    void Resize(int NewSize)
    {
        if (NewSize < 0)
            NewSize = 0;

        if (NewSize > _Capacity)
        {
            while (_Capacity < NewSize)
                _Capacity *= 2;
        }

        T* Temp = new T[_Capacity];

        int elementsToCopy = (_Size < NewSize) ? _Size : NewSize;

        for (int i = 0; i < elementsToCopy; i++)
            Temp[i] = OriginalArray[i];

        delete[] OriginalArray;
        OriginalArray = Temp;
        _Size = NewSize;
    }

    bool DeleteItemAt(int index)
    {
        if (index < 0 || index >= _Size)
        {
            cout << "Index out of range!\n";
            return false;
        }

        for (int i = index; i < _Size - 1; i++)
            OriginalArray[i] = OriginalArray[i + 1];

        _Size--;
        return true;
    }

    bool DeleteFirstItem() { return DeleteItemAt(0); }

    bool DeleteLastItem() { return DeleteItemAt(_Size - 1); }

    int Find(T data)
    {
        for (int i = 0; i < _Size; i++)
            if (data == OriginalArray[i]) return i;

        return -1;
    }

    bool DeleteItem(T data)
    {
        int index = Find(data);
        if (index == -1)
        {
            cout << "Data Not found";
            return false;
        }
        return DeleteItemAt(index);
    }

    void InsertAt(int index, T data)
    {
        if (index < 0 || index > _Size)
        {
            cout << "Index out of range!\n";

            return;
        }

        EnsureCapacity();

        for (int i = _Size; i > index; i--)
            OriginalArray[i] = OriginalArray[i - 1];

        OriginalArray[index] = data;
        _Size++;
    }

    void InsertAtBeginning(T data)
    {
        InsertAt(0, data);
    }
    void InsertAtEnd(T data)
    {
        InsertAt(_Size, data);

    }

    void InsertAfter(int index, T data)
    {
        InsertAt(index + 1 , data);
    }
    void InsertBefor(int index, T data)
    {
        InsertAt(index - 1, data);
    }

    
};
