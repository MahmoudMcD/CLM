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
		cout << variableHandler.handle(expression) << endl;
	}
	return 0;
}