// S12345678Practical4.cpp 

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#include "CharStack.h"
#include "IntegerStack.h"

void demo();
string convertToPostfix(string infix);
int evaluatePostfix(string expr);
int getPrecedence(char opr);

int main()
{
	string infix;
	string postfix;

	cout << "Enter an infix expression : ";
	getline(cin, infix);

	postfix = convertToPostfix(infix);
	cout << "Infix string   : " << infix << endl;
	cout << "Postfix string : " << postfix << endl;
	cout << "Result         : " << evaluatePostfix(postfix) << endl;

	system("PAUSE");
    return 0;
}

void demo()
{
	string infix;
	string postfix;

	infix = "1 - 2 * 3";
	postfix = convertToPostfix(infix);
	cout << "Infix string:   " << infix << endl;
	cout << "Postfix string: " << postfix << endl;
	cout << "Result = " << evaluatePostfix(postfix) << endl << endl;

	infix = "1 - 2 * 3 + 4";
	postfix = convertToPostfix(infix);
	cout << "Infix string:   " << infix << endl;
	cout << "Postfix string: " << postfix << endl;
	cout << "Result = " << evaluatePostfix(postfix) << endl << endl;

	infix = "8 / 2 * (1 + (4 - 2) ^ 2)";
	postfix = convertToPostfix(infix);
	cout << "Infix string:   " << infix << endl;
	cout << "Postfix string: " << postfix << endl;
	cout << "Result = " << evaluatePostfix(postfix) << endl << endl;
}

// convert infix expression to postfix expression
string convertToPostfix(string infix)
{
	CharStack operatorStack;
	string postfix;

	int characterCount = infix.length();
	char topOperator;
	for (int index = 0; index < characterCount; index++)
	{
		bool done = false;
		char nextChar = infix.at(index);
		if (nextChar == ' ') {}	// skip space, go to next char
		else
			if (isalnum(nextChar))	// alphanumeric character
				postfix = postfix + nextChar;
			else					// operator
			{
				switch (nextChar)
				{
				case '^': operatorStack.push(nextChar);
					break;

				case '+':
				case '-':
				case '*':
				case '/': while (!done && !operatorStack.isEmpty())
				{
					operatorStack.getTop(topOperator);
					if (getPrecedence(nextChar) <= getPrecedence(topOperator))
					{
						postfix = postfix + topOperator;
						operatorStack.pop();
					}
					else
						done = true;
				}
						  operatorStack.push(nextChar);
						  break;

				case '(': operatorStack.push(nextChar);
					break;

				case ')': // stack is not empty if infix expression is valid
					topOperator = operatorStack.getTop(); operatorStack.pop();
					while (topOperator != '(')
					{
						postfix = postfix + topOperator;
						topOperator = operatorStack.getTop(); operatorStack.pop();
					}
					break;

				default: break;
				}
			}
		cout << nextChar << "\t" << postfix << endl;
	}
	while (!operatorStack.isEmpty())
	{
		topOperator = operatorStack.getTop(); operatorStack.pop();
		postfix = postfix + topOperator;
		cout << topOperator << "\t" << postfix << endl;
	}
	return postfix;
}

// evaluate postfix expression
int evaluatePostfix(string expr)
{
	IntegerStack valueStack;
	int n, opd1, opd2, result;

	int count = expr.size();
	for (int i = 0; i < count; i++)
	{
		char c = expr.at(i);
		if (c == ' ') {}				// space, skip and go to next char
		else
			if (isdigit(c))				// number
			{
				n = (int)(c - '0');		// convert to number
				valueStack.push(n);		// push onto the stack
			}
			else						// operator
			{ // pop the 2 operands, operate on them and push result back onto the stack
				switch (c)
				{
				case '+':	opd2 = valueStack.getTop(); valueStack.pop();
					opd1 = valueStack.getTop(); valueStack.pop();
					result = opd1 + opd2;
					break;

				case '-':	opd2 = valueStack.getTop(); valueStack.pop();
					opd1 = valueStack.getTop(); valueStack.pop();
					result = opd1 - opd2;
					break;

				case '*':	opd2 = valueStack.getTop(); valueStack.pop();
					opd1 = valueStack.getTop(); valueStack.pop();
					result = opd1 * opd2;
					break;

				case '/':	opd2 = valueStack.getTop(); valueStack.pop();
					opd1 = valueStack.getTop(); valueStack.pop();
					result = opd1 / opd2;
					break;

				case '^':	opd2 = valueStack.getTop(); valueStack.pop();
					opd1 = valueStack.getTop(); valueStack.pop();
					result = pow(opd1, opd2);
					break;

				default:	break;
				}
				valueStack.push(result);	// push onto the stack
			}
	}
	return valueStack.getTop();
}


// get the precedence of an operator
int getPrecedence(char opr)
{
	switch (opr)
	{
	case '^': return 3;		// highest

	case '*':
	case '/': return 2;

	case '+':
	case '-': return 1;

	case '(':
	case ')': return 0;		// lowest
	}

	return -1;
}

