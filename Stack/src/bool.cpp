#include "../include/Stack.h"

Stack<bool>::Stack() :
    size_(defoult_size), top_(0)
{
    stackPtr_ = new char[size_];
}

Stack<bool>::Stack(size_t size, bool* stackPtr) :
    size_(size), top_(0), stackPtr_(stackPtr)
{}

Stack<bool>::Stack(const Stack* another) :
    size_(another.size_), top_(another.top_)
{
    stackPtr_ = new char[size_];

    for (size_t i = 0; i < size_; i++)
    {
        stackPtr_[i] = another.stackPtr_[i];
    }
}

Stack<bool>::Stack(Stack&& another) :
    size_(another.size_), top_(another.top_), stackPtr_(another.stackPtr_)
{
    another.stackPtr_ = nullptr;
}

Stack<bool>::~Stack()
{
    delete[] stackPtr;
}

Stack<bool>::operator = (const Stack& another) :
    size_(another.size_), top_(another.top_)
{
    for (size_t i = 0; i < size_; i++)
    {
        stackPtr_[i] = another.stackPtr_[i];
    }

    return stackPtr_;
}

Stack<bool>::operator = (Stack&& another) :
    size_(another.size_), top_(another.top_)
{
    delete[] stackPtr;

    stackPtr = another.stackPtr_;

    another.stackPtr_ = nullptr;

    return stackPtr_;
}

bool Stack<bool>::operator == (const bool& another)
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

bool Stack<bool>::operator != (const bool& another)
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

inline void Stack<bool>::DoubleSize()
{
    size_t old_size = size_;
    size_ *= 2;
    bool* newPtr = new char[size_];

    for (size_t i = 0; i < old_size; i++)
    {
        newPtr[i] = stackPtr_[i];
    }

    delete[] stackPtr_;
    stackPtr_ = newPtr;
}

inline void Stack<bool>::push(const bool& value)
{
    if (top_ == size_ - 2)
        DoubleSize();

    stackPtr_[top_++] = value;
}

inline T Stack<bool>::pop()
{
    bool to_return = stackPtr_[top_];
    top_--;

    return to_return;
}

inline size_t Stack<bool>::getStackSize() const
{
    return size_;
}

inline bool* Stack<bool>::getPtr() const
{
    return stackPtr_;
}

inline size_t Stack<bool>::getTop() const
{
    return top_;
}