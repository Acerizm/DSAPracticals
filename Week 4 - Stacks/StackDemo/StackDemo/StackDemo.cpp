// StackDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	// 3a)
	Stack s;
	// 3b)
	int item;
	s.push(item = 3);
	//3c)
	s.push(item = 4);
	//3d)
	// get the top of the item;
	// and display
	s.getTop(item);
	cout << "3d)" << endl;
	cout << item << " is the top of the stack!" << endl;
	//3e)
	//display all the items 
	//inOrderofInsertion;
	cout << "3e)" << endl;
	s.displayInOrderOfInsertion();
	// 3f)
	// just pop the top item from the stack
	// without returning the value
	s.pop();
	// 3g)
	cout << "3g)" << endl;
	s.displayInOrderOfInsertion();
	//Coversion of infix to postfix
	string infix;
	
	cout << "Please enter an infix: ";
	getline(cin, infix);

	

}

