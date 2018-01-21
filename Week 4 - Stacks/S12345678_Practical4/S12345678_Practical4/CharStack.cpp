#include "stdafx.h"
#include "CharStack.h"

CharStack::CharStack() { topNode == NULL; }

CharStack::~CharStack(){ }

bool CharStack::push(char item)
{
	Node *newNode = new Node;
	newNode->item = item;
	newNode->next = topNode;
	topNode = newNode;
	return true;
}

// version 1
bool CharStack::pop()
{
	bool success = !isEmpty();	// ensure stack is NOT empty
	if (success)
	{
		// stack is not empty; delete top
		Node* temp = topNode;
		topNode = topNode->next;
		// return deleted node to system
		delete temp;
		return true;
	}
	else
		return false;
}

// version 2
bool CharStack::pop(char &item)
{
	bool success = !isEmpty();	// ensure stack is NOT empty
	if (success)
		item = topNode->item;

	return pop();
}

// version 1
char CharStack::getTop()
{
	bool success = !isEmpty();	// ensure stack is NOT empty
	if (success)
		return topNode->item;
	else
	{
		// cout << "The stack is empty!" << endl;
		return ' ';  // space character
	}
};

// version 2
void CharStack::getTop(char &item)
{
	bool success = !isEmpty();	// ensure stack is NOT empty
	if (success)
		item = topNode->item;
};

bool CharStack::isEmpty() { return (topNode == NULL); }

void CharStack::displayInOrder()
{
	char item;
	CharStack tempStack;

	if (!isEmpty())
	{
		// put items into reversed order and display the stack items
		while (!isEmpty())
		{
			item = getTop();			// get the top item
			cout << item << endl;		// display the item
			tempStack.push(item);		// save the item to tempStack
			pop();						// remove the item from current stack
		}
		// restore the original stack
		while (!tempStack.isEmpty())
		{
			item = tempStack.getTop();
			push(item);
			tempStack.pop();
		}
	}
	else
		cout << "The stack is empty." << endl;
};

void CharStack::displayInOrderOfInsertion()
{
	char item;
	CharStack tempStack;

	if (!isEmpty())
	{
		// put items into reversed order and display the stack items
		while (!isEmpty())
		{
			item = getTop();
			tempStack.push(item);
			pop();
		}
		// restore the original stack
		while (!tempStack.isEmpty())
		{
			item = tempStack.getTop();
			cout << item << endl;
			push(item);
			tempStack.pop();
		}
	}
	else
		cout << "The stack is empty." << endl;
}

