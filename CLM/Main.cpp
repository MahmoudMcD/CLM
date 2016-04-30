#include <iostream>
#include "Stack.h"


using namespace std;

int main()
{
	Stack<int>* stack = new Stack<int>();
	stack->push(10);
	stack->push(20);
	cout << stack->pop() << " " << stack->pop() << endl;
	return 0;
}