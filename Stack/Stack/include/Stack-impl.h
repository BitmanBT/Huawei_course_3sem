#ifndef STACK-IMPL_H_INCLUDED
#define STACK-IMPL_H_INCLUDED

#include "Stack.h"
#include <cstdlib>

template <typename T>
Stack<T>::Stack() :
    size_(default_size), top_(0)
{
    stackPtr_ = new T[size_];
}

template <typename T>
Stack<T>::Stack(size_t size, T* stackPtr) :
    stackPtr_(stackPtr), size_(size), top_(0)
{}

template <typename T>
Stack<T>::Stack(const Stack& another) :
    size_(another.size_), top_(another.top_)
{
    stackPtr_ = new T[size_];

    for (size_t i = 0; i < size_; i++)
    {
        stackPtr_[i] = another.stackPtr_[i];
    }
}

template <typename T>
Stack<T>::Stack(Stack&& another) :
    stackPtr_(another.stackPtr_), size_(another.size_), top_(another.top_)
{
    another.stackPtr_ = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    delete [] stackPtr;
}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack& another)
{
    size_ = another.size_;
    top_ = another.top_;
    
    for (size_t i = 0; i < size_; i++)
    {
        stackPtr_[i] = another.stackPtr_[i];
    }

    return stackPtr_;
}

template <typename T>
Stack<T>& Stack<T>::operator = (Stack&& another)
{
    size_ = another.size_;
    top_ = another.top_;
    
    delete [] stackPtr;

    stackPtr = another.stackPtr_;

    another.stackPtr_ = nullptr;

    return stackPtr_;
}

template <typename T>
bool Stack<T>::operator == (const Stack& another) const
{
    bool check = false;

    if (top_ != another.top_)
    {
        return check;
    }

    for (size_t i = 0; i <= top_; i++)
    {
        if (stackPtr_[i] != another.stackPtr_[i])
            return check;
    }

    check = true;
    return check;
}

template <typename T>
bool Stack<T>::operator != (const Stack& another) const
{
    bool check = true;

    if (top_ != another.top_)
    {
        return check;
    }

    for (size_t i = 0; i <= top_; i++)
    {
        if (stackPtr_[i] != another.stackPtr_[i])
            return check;
    }

    check = false;
    return check;
}

template <typename T>
inline void Stack<t>::DoubleSize()
{
    size_t old_size = size_;
    size_ *= 2;
    T* newPtr = new T[size_];

    for (size_t i = 0; i < old_size; i++)
    {
        newPtr[i] = stackPtr_[i];
    }

    delete [] stackPtr_;
    stackPtr_ = newPtr;
}

template <typename T>
inline void Stack<T>::push(const T& value)
{
    if (top_ == size_ - 2)
        DoubleSize();

    stackPtr_[top_++] = value;
}

template <typename T>
inline T Stack<T>::pop()
{
    T to_return = stackPtr_[top_];
    top_--;

    return to_return;
}

template <typename T>
inline size_t Stack<T>::getStackSize() const
{
    return size_;
}

template <typename T>
inline T* Stack<T>::getPtr() const
{
    return stackPtr_;
}

template <typename T>
inline size_t Stack<T>::getTop() const
{
    return top_;
}

#endif // STACK-IMPL_H_INCLUDED
