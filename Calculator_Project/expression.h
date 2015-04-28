#include <iostream>
#include <string>
#include "stackList.h"
#include <cmath>

using namespace std;

class Expression
{
private:
	double value;
	string postfix;
	string infixExpression;

	//helper functions
	char isFunctionName(const string& f);
	double calc(double a, double b, char ptr);
	bool Expression::IsLowerProirty(char op1, char op2);

	bool is_operator(char c)
	{
		return c == '+' || c == '-' || c == '/' || c == '*' || c == '%';
	}

	int operatorStrenght(char op);


public:
	Expression(const string& s) :infixExpression(s){}

	string toPostfix();
	double Expression::evaluate();
};