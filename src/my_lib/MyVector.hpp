#pragma once
#include <iostream>

template<typename T>
class MyVector
{
    private:
    T* ptr;
    size_t mSize=0;
    size_t mCapacity=0;
    public:
    MyVector();
    MyVector(size_t size, const T& defaultVal = T());
    void push_back(T val);
    T pop_back();
    size_t capacity();
    size_t size();
    void clear();
};

template<typename T>
MyVector<T>::MyVector()
{
    mCapacity = 0;
    mSize = 0;
}

template<typename T>
MyVector<T>::MyVector(size_t capacity, const T& default_val)
{
    ptr = new T[capacity];
    mCapacity = capacity;
    mSize = capacity;
}

template<typename T>
void MyVector<T>::push_back(T val)
{
    if(mSize>=mCapacity)
    {
        mCapacity = mCapacity*2;
        T* new_ptr = new int[mCapacity];
        for(int i=0;i<mSize;++i)
        {
            new_ptr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = new_ptr;
    }
    ptr[++mSize] = val;
}

template<typename T>
T MyVector<T>::pop_back()
{
    return ptr[mSize--];
}

template<typename T>
size_t MyVector<T>::size()
{
    return mSize;
}

template<typename T>
size_t MyVector<T>::capacity()
{
    return mCapacity;
}

template<typename T>
void MyVector<T>::clear()
{
    delete[] ptr;
    ptr=0;
    mSize = 0;
    mCapacity = 0;
}
