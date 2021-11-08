#ifndef TEST-IMPL_H_INCLUDED
#define TEST-IMPL_H_INCLUDED

#include <cstdlib>
#include <gtest/gtest.h>
#include "../include/Stack-impl.h"

class TestStack : public ::testing::Test
{
protected:
	Stack<int> stack;
};

TEST(TestStack, AssignmentOperator)
{
	this->stack.push(5);
	this->stack.push(5);

	EXPEXT_EQ(stack[0], stack[1]);

	this->stack.pop();
	this->stack.pop();

	this->stack.push(1);
	this->stack.push(5);

	EXPECT_NE(this->stack[0], this->stack[1]);
}

TEST(TestStack, EqualOperator)
{
	this->stack.push(5);
	this->stack.push(5);

	EXPECT_TRUE(this->stack[0] == this->stack[1]);

	this->stack.pop();
	this->stack.pop();

	this->stack.push(1);
	this->stack.push(5);

	EXPECT_FALSE(this->stack[0] == this->stack[1]);
}

TEST(TestStack, NotEqualOperator)
{
	this->stack.push(5);
	this->stack.push(5);

	EXPECT_FALSE(this->stack[0] != this->stack[1]);

	this->stack.pop();
	this->stack.pop();

	this->stack.push(1);
	this->stack.push(5);

	EXPECT_TRUE(this->stack[0] != this->stack[1]);
}

TEST(TestStack, DoubleSize)
{
	for(int i = 0; i < 3, i++)
		this->stack.push(5);

	EXPECT_EQ(this->stack.size_, 2 * this->stack.default_size);
}

TEST(TestStack, Push)
{
	this->stack.push(5);

	EXPECT_EQ(this->stack[0], 5);
}

TEST(TestStack, Pop)
{
	this->stack.push(5);

	int check = this->stack.pop();

	EXPECT_EQ(check, 5);
	EXPECT_EQ(this->stack.top_, 0);
}

TEST(TestStack, getStackSize)
{
	EXPECT_EQ(this->stack.getStackSize(), this->stack.default_size);
}

TEST(TestStack, getPtr)
{
	EXPECT_EQ(this->stack.getPtr(), this->stack.stackPtr_);
}

TEST(TestStack, getTop)
{
	EXPECT_EQ(this->stack.getTop(), this->stack.top_)
}

#endif // TEST-IMPL_H_INCLUDED