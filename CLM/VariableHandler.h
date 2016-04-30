#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include "InFix.h"

using namespace std;

class VariableHandler
{
public:
	VariableHandler();
	~VariableHandler();
	double handle(string expression);
private:
	unordered_map<string, double>* variables;
};

