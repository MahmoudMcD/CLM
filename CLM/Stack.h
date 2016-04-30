#pragma once
#include "StackNode.h"

template <class T>
class Stack
{
public:
	Stack()
	{
		sentinel.setNext(nullptr);
	}
	~Stack()
	{
		// delete all nodes in the stack 
		StackNode<T>* temp = sentinel.getNext();
		StackNode<T>* toBeDeleted = temp;
		while (temp != nullptr)
		{
			toBeDeleted = temp;
			temp = temp->getNext();
			delete(toBeDeleted);
		}
	}

	void push(T value)
	{
		sentinel.setNext(new StackNode<T>(value, sentinel.getNext()));
		size++;
	}

	T pop()
	{

		if (!isEmpty())
		{
			StackNode<T>* temp = sentinel.getNext();
			T tempValue = temp->getValue();
			sentinel.setNext(sentinel.getNext()->getNext());
			size--;
			delete(temp);
			return tempValue;
		}
		return 0;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	int getSize() { return size; }

private:
	StackNode<T> sentinel; 
	int size = 0;
};

