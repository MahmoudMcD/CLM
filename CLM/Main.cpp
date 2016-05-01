#include <iostream>
#include <string>
#include "VariableHandler.h"

using namespace std;

int main()
{
	string expression;
	VariableHandler variableHandler;
	while (true)
	{
		cout << ">> ";
		getline(cin, expression);
		try
		{
			cout << variableHandler.handle(expression) << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}
	return 0;
}