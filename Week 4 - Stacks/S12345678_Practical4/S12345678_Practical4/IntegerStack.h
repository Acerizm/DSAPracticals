#pragma once
#include <iostream>
using namespace std;



class IntegerStack
{
private:
	struct Node
	{
		int	  item;
		Node* next;
	};

	Node* topNode;

public:
	IntegerStack();
	~IntegerStack();

	//push (add) item on top of the stack
	bool push(int item);

	//pop (remove) item from top of stack
	bool pop();					// version 1
	bool pop(int &item);		// version 2

	//get item at the top of stack 
	int getTop();				// version 1
	void getTop(int &item);		// version 2

	//check if the stack is empty
	bool isEmpty();

	//display items in stack in order
	void displayInOrder();

	//display items in stack in order of insertion
	void displayInOrderOfInsertion();
};

