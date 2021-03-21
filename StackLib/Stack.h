#ifndef _STACKLIST_
#define _STACKLIST_
#include<iostream>
using namespace std;
template<class t>
class Stack {
private:
	struct StackNode
	{
		t item;
		StackNode* next;
	};
	StackNode* topPtr, * curPtr;
	int count;
public:
	Stack() {
		topPtr = NULL;
		count = 0;
	}

	Stack(const Stack& _v) {
		topPtr = _v.topPtr;
	}

	bool isEmpty()
	{
		return topPtr == NULL;
	}

	void push(t newItem)
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

	void pop() {
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

	void pop(t& stackTop)
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

	void getTop(t stackTop)
	{
		if (isEmpty())
			cout << "stack empty on getTop";
		else
			stackTop = topPtr->item;
		cout << "\nTop Element of the stack is " << stackTop;
		cout << endl;
	}
	void display()
	{
		curPtr = topPtr;
		cout << "\nItems in the stack : ";
		cout << "[ ";
		while (curPtr != NULL)
		{
			cout << curPtr->item;
			curPtr = curPtr->next;
		}
		cout << " ]\n";
	}

	t get_min() {
		t min = topPtr->item;;
		curPtr = topPtr->next;
		while (curPtr != NULL) {
			if (min > curPtr->item)
				min = curPtr->item;
			curPtr = curPtr->next;
		}
		return min;
	}

	t get_max() {
		t max = topPtr->item;;
		curPtr = topPtr->next;
		while (curPtr != NULL) {
			if (max < curPtr->item)
				max = curPtr->item;
			curPtr = curPtr->next;
		}
		return max;
	}

	int get_count() {
		return count;
	}
};
#endif

