#include "PostFix.h"



PostFix::PostFix(string expression)
{
	stack = new Stack<double>();
	this->expression = expression;
}


PostFix::~PostFix()
{
	delete(stack);
}


double PostFix::evaluate()
{
	double number = 0;
	int numberInHand = 0, dotFound = 0, dotPlace = 0;
	int numbersCount = 0;
	char currentChar;

	/* Evaluating PostFix with multi-digit float numbers 
	   Ilerate through the expression string if a digit found check if a dot were found
	   if so :
			divide the digit by 10^digitPlace and add it to the number and increase the dotPlace
	   else
			multiply the number by 10 and add the digit
	  
	   If a '.' were found : dotFound = 1
	   if a ' ' were found : if numberInHand push it to the stack and reset all parameters
	   else meaning a operator were found, evaluate the operator   
	 */
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
				stack->push(number);
				numberInHand = 0;
				dotFound = 0;
				number = 0;
				dotPlace = 0;
				numbersCount++;
			}
		}
		else
		{
			if (numberInHand)
			{
				stack->push(number);
				numberInHand = 0;
				dotFound = 0;
				dotPlace = 0;
				number = 0;
				numbersCount++;
			}
			evaluateOperator(currentChar);
		}
	}

	if (numberInHand && numbersCount <= 1)
		return number;

	if (stack->getSize() != 1)
		throw "Invalid PostFix Expression.. triggered in PostFix";

	return stack->pop();
}


void PostFix::evaluateOperator(char operatorChar)
{
	if (stack->getSize() < 2)
		throw "InValid postFix Expression.. triggered in PostFix";

	double secondNumber = stack->pop();
	double firstNumber = stack->pop();

	switch (operatorChar)
	{
	case '+':
		stack->push(firstNumber + secondNumber);
		break;
	case '-':
		stack->push(firstNumber - secondNumber);
		break;
	case '*':
		stack->push(firstNumber * secondNumber);
		break;
	case '/':
		stack->push(firstNumber / secondNumber);
		break;
	case '^':
		stack->push(pow(firstNumber, secondNumber));
		break;
	default:
		throw "Invalid Operator used. triggerd in PostFix";
	}
}
