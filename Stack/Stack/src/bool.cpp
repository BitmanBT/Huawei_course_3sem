#include "../include/Stack.h"

template<> Stack<bool>::Stack() :
    size_(default_size), top_(0)
{
    stackPtr_ = new bool[size_];
}

template<> Stack<bool>::Stack(size_t size, bool* stackPtr) :
    stackPtr_(stackPtr), size_(size), top_(0)
{}

template<> Stack<bool>::Stack(const Stack& another) :
    size_(another.size_), top_(another.top_)
{
    stackPtr_ = new bool[size_];

    for (size_t i = 0; i < size_; i++)
    {
        stackPtr_[i] = another.stackPtr_[i];
    }
}

template<> Stack<bool>::Stack(Stack&& another) :
    stackPtr_(another.stackPtr_), size_(another.size_), top_(another.top_)
{
    another.stackPtr_ = nullptr;
}

template<> Stack<bool>::~Stack()
{
    delete[] stackPtr_;
}

template<> Stack<bool>& Stack<bool>::operator = (const Stack& another)
{
    size_ = another.size_;
    top_ = another.top_;
    
    for (size_t i = 0; i < size_; i++)
    {
        stackPtr_[i] = another.stackPtr_[i];
    }

    return *this;
}

template<> Stack<bool>& Stack<bool>::operator = (Stack&& another)
{
    size_ = another.size_;
    top_ = another.top_;
    
    delete[] stackPtr_;

    stackPtr_ = another.stackPtr_;

    another.stackPtr_ = nullptr;

    return *this;
}

template<> bool Stack<bool>::operator == (const Stack& another) const
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

template<> bool Stack<bool>::operator != (const Stack& another) const
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

template<> inline void Stack<bool>::DoubleSize()
{
    size_t old_size = size_;
    size_ *= 2;
    bool* newPtr = new bool[size_];

    for (size_t i = 0; i < old_size; i++)
    {
        newPtr[i] = stackPtr_[i];
    }

    delete[] stackPtr_;
    stackPtr_ = newPtr;
}

template<> inline void Stack<bool>::push(const bool& value)
{
    if (top_ == size_ - 2)
        DoubleSize();

    stackPtr_[top_++] = value;
}

template<> inline bool Stack<bool>::pop()
{
    bool to_return = stackPtr_[top_];
    top_--;

    return to_return;
}

template<> inline size_t Stack<bool>::getStackSize() const
{
    return size_;
}

template<> inline bool* Stack<bool>::getPtr() const
{
    return stackPtr_;
}

template<> inline size_t Stack<bool>::getTop() const
{
    return top_;
}
