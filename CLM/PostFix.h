#pragma once
#include "Stack.h"
#include <string>

using namespace std;

class PostFix
{
public:
	PostFix(string expression);
	~PostFix();
	double evaluate();

private: 
	Stack<double>* stack;
	string expression;
	void evaluateOperator(char);
};

