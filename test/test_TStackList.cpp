#include "Stack.h"
#include <gtest.h>

TEST(LinkedStack, can_create_LinkedStack)
{
	ASSERT_NO_THROW(Stack<int> S_INT);
}

TEST(LinkedStack, create_empty_LinkedStack)
{
	Stack<int> s;

	EXPECT_EQ(true, s.isEmpty());
}

TEST(LinkedStack, can_push)
{
	Stack<int> s;

	ASSERT_NO_THROW(s.push(3));
}
TEST(TStackList, can_assing_StackList)
{
	Stack<int> s1;
	s1.push(1);
	Stack<int> s2;
	s2 = s1;
	
	EXPECT_EQ(1, s2.getTop());
}

TEST(LinkedStack, can_copy_LinkedStack)
{
	Stack<int> s;
	s.push(2);
	s.push(3);
	Stack<int> s2(s);
	ASSERT_NO_THROW();
}

TEST(LinkedStack, can_get_element)
{
	Stack<int> s;
	s.push(4);
	int i;
	s.pop(i);
	EXPECT_EQ(4,i);
}

TEST(LinkedStack, cant_get_if_empty)
{
	Stack<int> s;

	ASSERT_ANY_THROW(s.pop());
}

TEST(LinkedStack, can_get_count)
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	EXPECT_EQ(2, s.get_count());
}

TEST(LinkedStack, DOP_can_get_max_elem_DOP)
{
	Stack<int> s;
	s.push(1);
	s.push(7);
	s.push(3);
	s.push(14);
	s.push(61);
	s.push(2);
	EXPECT_EQ(61, s.get_max());
}

TEST(LinkedStack, DOP_can_get_min_elem_DOP)
{
	Stack<int> s;
	s.push(1);
	s.push(7);
	s.push(3);
	s.push(14);
	s.push(61);
	s.push(2);
	EXPECT_EQ(1, s.get_min());
}