#include "stdafx.h"
#include "IntegerStack.h"

IntegerStack::IntegerStack() { topNode == NULL; }

IntegerStack::~IntegerStack(){ }

bool IntegerStack::push(int item)
{
	Node *newNode = new Node;
	newNode->item = item;
	newNode->next = topNode;
	topNode = newNode;
	return true;
}

// version 1
bool IntegerStack::pop()
{
	bool success = !isEmpty();	// ensure stack is NOT empty
	if (success)
	{
		// stack is not empty; delete top
		Node* temp = topNode;		// to  return to the system
		topNode = topNode->next;
		// return deleted node to system
		delete temp;
		return true;
	}
	else
		return false;
}

// version 2
bool IntegerStack::pop(int &item)
{
	bool success = !isEmpty();	// ensure stack is NOT empty
	if (success)
		item = topNode->item;
	
	return pop();
}

// version 1
int IntegerStack::getTop()
{
	bool success = !isEmpty();	// ensure stack is NOT empty
	if (success)
		return topNode->item;
	else
		return -1;
}

// version 2
void IntegerStack::getTop(int &item)
{
	bool success = !isEmpty();	// ensure stack is NOT empty
	if (success)
		item = topNode->item;
}

bool IntegerStack::isEmpty() { return (topNode == NULL); }

void IntegerStack::displayInOrder()
{
	int item;
	IntegerStack tempStack;

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

void IntegerStack::displayInOrderOfInsertion()
{
	IntegerStack tempStack;
	int item;

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
