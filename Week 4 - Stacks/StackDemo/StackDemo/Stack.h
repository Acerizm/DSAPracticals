// List.h - Specification of List ADT

#pragma once
#include <iostream>
#include <string>
using namespace std;	


typedef int ItemType;

class Stack
{
private:
	struct Node {
		ItemType item;
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
	bool push(ItemType &item);

	//pop item from top of stack
	bool pop();

	//retrieve item from top of stack
	void getTop(ItemType &item);

	//retrieve and pop item from top of stack
	bool pop(ItemType &item);

	//display items in stack in order
	void displayInOrder();

	//display items in stack in order of insertion
	void displayInOrderOfInsertion();
	
	void evaluateInfix(ItemType infix); 
	
};
 
