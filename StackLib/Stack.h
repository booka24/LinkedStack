#ifndef _STACKLIST_
#define _STACKLIST_
#include<iostream>
using namespace std;
template<class t>
class Stack {
protected:
    struct StackNode
	{
		t item;
		StackNode* next;
	};
	StackNode* topPtr;
	int count;
	void get_all(t* temp);
public:
	Stack();
	Stack(Stack<t>& v);
	bool isEmpty();
    void push(t newItem);
	void pop();
	void pop(t& stackTop);
    t getTop();
	t get_min();
	t get_max();
	int get_count();
	void operator=(Stack<t>& v);
};


template<class t>
inline void Stack<t>::get_all(t* temp)
{
	temp = new t[count];
    
}

template<class t>
inline Stack<t>::Stack()
{
		topPtr = NULL;
		count = 0;
}

template<class t>
inline Stack<t>::Stack(Stack<t>& v)
{
	count = v.count;
	t* temp = new t[count];
	StackNode* curPtr = v.topPtr;
	int i = 0;
	while (curPtr != NULL) {
		temp[i] = curPtr->item;
		curPtr = curPtr->next;
		i++;
	}
	for (int i = count - 1; i >= 0; i--)
		push(temp[i]);
}

template<class t>
inline bool Stack<t>::isEmpty()
{
	return topPtr == NULL;
}

template<class t>
inline void Stack<t>::push(t newItem)
{
	StackNode* newPtr = new StackNode;
	if (newPtr == NULL)
		cout << "Stack push cannot allocate memory";
	else
	{
		newPtr->item = newItem;
		newPtr->next = topPtr;
		topPtr = newPtr;
		count++;
	}
}

template<class t>
inline void Stack<t>::pop()
{
	if (isEmpty())
		throw "Stack empty on pop";
	else {
		StackNode* temp = topPtr;
		topPtr = topPtr->next;
		temp->next = NULL;
		delete temp;
		count--;
	}
}

template<class t>
inline void Stack<t>::pop(t& stackTop)
{
	if (isEmpty())
		cout << "Stack empty on pop";
	else {
		stackTop = topPtr->item;
		StackNode* temp = topPtr;
		topPtr = topPtr->next;
		temp->next = NULL;
		delete temp;
		count--;
	}
}

template<class t>
inline t Stack<t>::getTop()
{
	if (isEmpty())
		throw "stack empty on getTop";
	else
		return topPtr->item;
}

template<class t>
inline t Stack<t>::get_min()
{
	StackNode* curPtr;
	t min = topPtr->item;;
	curPtr = topPtr->next;
	while (curPtr != NULL) {
		if (min > curPtr->item)
			min = curPtr->item;
		curPtr = curPtr->next;
	}
	return min;
}

template<class t>
inline t Stack<t>::get_max()
{
	StackNode* curPtr;
	t max = topPtr->item;;
	curPtr = topPtr->next;
	while (curPtr != NULL) {
		if (max < curPtr->item)
			max = curPtr->item;
		curPtr = curPtr->next;
	}
	return max;
}

template<class t>
inline int Stack<t>::get_count()
{
	return count;
}

template<class t>
inline void Stack<t>::operator=(Stack<t>& v)
{
	for (int i = 0; i < count; i++)
		pop();
	count = v.count;
	t* temp = new t[count];
	StackNode* curPtr = v.topPtr;
	int i = 0;
	while (curPtr != NULL) {
		temp[i] = curPtr->item;
		curPtr = curPtr->next;
		i++;
	}
	for (int i = count - 1; i >= 0; i--)
		push(temp[i]);
}

#endif