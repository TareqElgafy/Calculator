#include "expression.h"

string Expression::toPostfix(){


	stackList<char> operatorsStack;
	string enteredAlpha = "";
	bool fun = false;
	for (int i = 0; i < infixExpression.length(); i++){

		if (isspace(infixExpression[i]) /*infixExpression[i] == ' '*/) continue;

		else if (infixExpression[i] >= '0' && infixExpression[i] <= '9' || infixExpression[i] == '.'){

			postfix += infixExpression[i];

		}


		else if (is_operator(infixExpression[i]))
		{
			postfix = postfix + " ";

			if (operatorsStack.empty())
			{
				operatorsStack.push(infixExpression[i]);
			}

			else if (!operatorsStack.empty()){

				while (!operatorsStack.empty() && IsLowerProirty(infixExpression[i], operatorsStack.top()) && operatorsStack.top() != '('){

					postfix = postfix + operatorsStack.top() + " ";
					operatorsStack.pop();

				}

				operatorsStack.push(infixExpression[i]);

			}

		}


		else if (infixExpression[i] == '('){

			if (isFunctionName(enteredAlpha))
			{

				operatorsStack.push(isFunctionName(enteredAlpha));
				enteredAlpha = "";
			}



			operatorsStack.push(infixExpression[i]);

		}

		else if (infixExpression[i] == ')')
		{
			while (!operatorsStack.empty() && operatorsStack.top() != '(') {
				postfix = postfix + " " + operatorsStack.top();
				operatorsStack.pop();

			}
			operatorsStack.pop(); // for the '('

		}
		else if (isalpha(infixExpression[i]))
		{
			enteredAlpha += infixExpression[i];
		}


		for (int i = 1; i < postfix.length(); i++) {
			if (postfix[i] == ' '&& postfix[i] == postfix[i - 1]) throw "error";
		}

	}

	while (!operatorsStack.empty()) {
		postfix = postfix + " " + operatorsStack.top();
		operatorsStack.pop();
	}

	return postfix;
}

double Expression::evaluate(){
	if (postfix == "")
		this->toPostfix();

	string operand = ""; int j = 0;
	double temp1, temp2, temp_answer;

	stackList<double> PTA;
	string::iterator p = postfix.begin();

	while (p != postfix.end()){
		operand = "";
		if (*p >= '0' && *p <= '9') {
			while (*p != ' '){
				operand += *p;
				p++;
			}
			PTA.push(stod(operand));
			//cout << PTA.top() << endl;
		}

		if (is_operator(*p))  /*p == '+' ||*p == '-' ||*p == '*' ||*p == '/' ||*p == '%'*/
		{
			temp1 = PTA.top(); PTA.pop();
			temp2 = PTA.top(); PTA.pop();
			temp_answer = calc(temp1, temp2, *p);
			PTA.push(temp_answer);
		}
		if (*p == 's' || *p == 'c' || *p == 't' || *p == 'e'){

			temp1 = PTA.top(); PTA.pop();
			temp_answer = calc(temp1, 0, *p);
			PTA.push(temp_answer);

		}

		p++;
	}
	value = PTA.top();
	return PTA.top();

}

double Expression::calc(double a, double b, char ptr){
	switch (ptr){
	case('+') : return b + a; break;
	case('-') : return b - a; break;
	case('*') : return b*a; break;
	case('/') : return b / a; break;
	case('%') : return ((int)b % (int)a); break;
	case('s') : return sin(a); break;
	case('c') : return cos(a); break;
	case('t') : return tan(a); break;
	case('e') : return exp(a); break;


	default: return 0;
	}
}

char Expression::isFunctionName(const string& f){

	if (f == "sin") return 's';
	else if (f == "cos") return 'c';
	else if (f == "tan") return 't';
	else if (f == "exp") return 'e';
	else return 0;

}

bool Expression::IsLowerProirty(char op1, char op2){

	int op1Strenght = operatorStrenght(op1);
	int op2Strenght = operatorStrenght(op2);

	if (op1Strenght == op2Strenght) return true; // as the left operator will be the higher priority 

	if (op1Strenght < op2Strenght) return true;
	if (op1Strenght > op2Strenght) return false;

}

int Expression::operatorStrenght(char op){
	int strengh = 0;
	switch (op)
	{
	case '+':strengh = 1; break;
	case '-':strengh = 1; break;
	case '*':strengh = 2; break;
	case '/':strengh = 2; break;
	case '%':strengh = 2; break;
	case 's':strengh = 2; break;
	case 'c':strengh = 2; break;
	case 't':strengh = 2; break;
	case 'e':strengh = 2; break;



	}
	return strengh;

}