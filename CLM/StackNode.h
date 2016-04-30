#pragma once

template <class T>
class StackNode
{
public:
	StackNode()
	{
		next = nullptr;
	}
	~StackNode()
	{
		next = nullptr;
	}

	StackNode(T value, StackNode<T>* next)
	{
		this->next = next;
		this->value = value;
	}

	void setValue(T value)
	{
		this->value = value;
	}

	void setNext(StackNode<T>* next) { this->next = next; }

	T getValue() { return this->value; }

	StackNode<T>* getNext() { return this->next; }

private:
	T value;
	StackNode<T>* next;
};

