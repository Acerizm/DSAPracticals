// CharStack.h - Char Stack (Pointer-based implementation)

#pragma once
#include <iostream>
using namespace std;



class CharStack
{
private:
	struct Node
	{
		char   item;
		Node*  next;
	};

	Node *topNode;

public:
	CharStack();
	~CharStack();

	//push (add) item on top of the stack
	bool push(char item);

	//pop (remove) item from top of stack
	bool pop();					// version 1
	bool pop(char &item);		// version 2

	//get item at the top of stack 
	char getTop();				// version 1
	void getTop(char &item);	// version 2

	//check if the stack is empty
	bool isEmpty();

	//display items in stack in order
	void displayInOrder();

	//display items in stack in order of insertion
	void displayInOrderOfInsertion();
};

