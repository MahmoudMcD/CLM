#pragma once
#include "PostFix.h"
class InFix
{
public:
	InFix(string expression);
	~InFix();
	double evaluate();
	void toPostFix();
	string getPostFixExpression() { return newExpression; }
private:
	Stack<char>* operatorStack;
	string expression;
	string newExpression;
	int giveHierarchy(char operatorChar);
};

