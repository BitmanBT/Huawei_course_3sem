#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <cstdlib>

template <typename T>
class Stack
{
private:
    const size_t default_size = 2;
    
    T* stackPtr_;
    size_t size_;
    size_t top_;

    inline void DoubleSize();

public:
    Stack();
    Stack(size_t size, T* stackPtr);
    Stack(const Stack& another);
    Stack(Stack&& another);
    ~Stack();

    Stack& operator = (const Stack& another);
    Stack& operator = (Stack&& another);

    bool operator == (const Stack& another) const;
    bool operator != (const Stack& another) const;

    inline void push(const T& value);
    inline T pop();

    inline size_t getStackSize() const;
    inline T* getPtr() const;
    inline size_t getTop() const;
};

#endif // STACK_H_INCLUDED
