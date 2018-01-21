// List.h - Specification of List ADT

#pragma once
#include <iostream>
#include <string>
using namespace std;	


typedef int ItemType1;

class Stack
{
private:
	struct Node {
		ItemType1 item;
		Node *next; // this allows me to store the address of the next node that i would like to link to!
	};

	Node *topNode; //This is to declare the first node/ the head of the linked list 
	// Node *firstNode; means that it is a linked list implementation! :D

public:

	//Default constructor
	Stack();
	//Destructor
	~Stack();

	//check if the stack is empty
	bool isEmpty();

	//push item on top of the stack
	bool push(ItemType1 &item);

	//pop item from top of stack
	bool pop();

	//retrieve item from top of stack
	void getTop(ItemType1 &item);

	//retrieve and pop item from top of stack
	bool pop(ItemType1 &item);

	//display items in stack in order
	void displayInOrder();

	//display items in stack in order of insertion
	void displayInOrderOfInsertion();
	
	void evaluateInfix(ItemType1 infix); 
	
};
 
