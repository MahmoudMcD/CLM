#include "InFix.h"
#include <sstream>

using namespace std;


InFix::InFix(string expression)
{
	operatorStack = new Stack<char>();
	this->expression = expression;
}


InFix::~InFix()
{
	delete(operatorStack);
}

double InFix::evaluate()
{
	toPostFix();
	PostFix newPostFix(newExpression);
	return newPostFix.evaluate();
}

void InFix::toPostFix()
{
	double number = 0;
	int numberInHand = 0, dotFound = 0, dotPlace = 0;
	char currentChar, tempChar;
	
	for (int i = 0; i < expression.length(); i++)
	{
		currentChar = expression[i];
		if (currentChar <= '9' && currentChar >= '0')
		{
			numberInHand = 1;
			if (dotFound)
				number = number + (currentChar - '0') / pow(10, ++dotPlace);
			else
				number = (number * 10) + (currentChar - '0');
		}
		else if (currentChar == '.')
			dotFound = 1;
		else if (currentChar == ' ')
		{
			if (numberInHand)
			{ 
				ostringstream s;
				s << " " << number;
				newExpression += s.str();
				numberInHand = 0;
				dotPlace = 0;
				dotFound = 0;
				number = 0;
			}
		}
		else if (currentChar == ')')
		{
			
			while (!operatorStack->isEmpty())
			{
				tempChar = operatorStack->pop();
				if (tempChar == '(')
					break;
				newExpression = newExpression +" "+tempChar;
			}
		}
		else
		{
			while (!operatorStack->isEmpty())
			{
				tempChar = operatorStack->peak();
				if (giveHierarchy(tempChar) >= giveHierarchy(currentChar) && tempChar != '(')
				{
					tempChar = operatorStack->pop();
					newExpression = newExpression + " " + tempChar;
				}
				else
					break;
			}
			operatorStack->push(currentChar);
		}
	}

	if (numberInHand)
	{
		ostringstream s;
		s << " " << number;
		newExpression += s.str();
	}

	while (!operatorStack->isEmpty())
	{
		tempChar = operatorStack->pop();
		if (tempChar == '(')
			throw "Invalid expression triggerd in InFix";
		newExpression = newExpression + " " + tempChar;
	}
}


int InFix::giveHierarchy(char operatorChar)
{
	switch (operatorChar)
	{
	case '+':
	case '-':
		return 0;
	case '*':
	case '/':
	case '^':
		return 1;
	case '(':
		return 3;
	default:
		throw "Invalid Operator used. triggerd in InFix";
	}
}