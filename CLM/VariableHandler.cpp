#include "VariableHandler.h"



VariableHandler::VariableHandler()
{
	variables = new unordered_map<string, double>();
}


VariableHandler::~VariableHandler()
{
}


double VariableHandler::handle(string expression)
{
	int variableInHand = 0, tempI = 0;
	int variableNameStart = 0, variableNameEnd = 0;
	int type = 0, startOfRest = 0;
	char currentChar, tempChar;
	string variableName;

	/* if a variable is found pass untill anything not alphanumric or a space is found to get the full name
	 * of the variable
	 * when the full name is found find the type by passing untill anything but = or space is found 
	 * if = is found then this is an assignment ( type = 1 )
	 * handle the rest and save it in variable
	 * else 
	 * subsitute the variable name with it's value and procced 
	*/
	for (int i = 0; i < expression.length(); i++)
	{
		currentChar = expression[i];
		if (isalpha(currentChar))
		{
			variableInHand = 1;
			variableNameStart = tempI = i;
			tempChar = currentChar;
			
			while (isalnum(tempChar) && tempI < expression.length())
				tempChar = expression[++tempI];
			
			variableNameEnd = tempI;
			
			variableName = expression.substr(variableNameStart, variableNameEnd - variableNameStart);

			while ((tempChar == ' ' || tempChar == '=') && tempI < expression.length())
			{
				if (tempChar == '=')
				{
					type = 1;
					break;
				}
				tempChar = expression[++tempI];
			}
			//  012345678
			// "name + 10"
			// this means that the expression contains an assignment expression
			if (type)
			{
				(*variables)[variableName] = handle(expression.substr(tempI += 2, expression.length() - (--tempI)));
				cout << variableName << " : " << (*variables)[variableName] << endl;
				auto variable = variables->find(variableName);
				if (variable != variables->end())
					cout << "COool !" << endl;
				return (*variables)[variableName];
			}
			else
			{
				auto variableInHash = variables->find(variableName);
				if (variableInHash != variables->end())
				{
					ostringstream s;
					s << " " << variableInHash->second;
					expression.replace(variableNameStart, variableNameEnd - variableNameStart, s.str());
				}
				else
					throw new exception("Variable Not Found");
			}
		}
	}
	InFix newInFix(expression);
	return newInFix.evaluate();
}