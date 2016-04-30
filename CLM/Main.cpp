#include <iostream>
#include <string>
#include "PostFix.h"

using namespace std;

int main()
{
	string expression;
	getline(cin, expression);
	PostFix postFix(expression);
	cout << postFix.evaluate() << endl;
	return 0;
}