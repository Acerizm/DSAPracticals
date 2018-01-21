#include "stdafx.h"
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;


Stack::~Stack()
{
	while(!isEmpty()) // pop until stack is empty
	{
		pop();
	}
	
}

Stack::Stack() {
	topNode = NULL;
}

bool Stack::isEmpty() {

	return topNode == NULL;
	/*// this is too slow
	if (topNode == NULL)
		return true;
	else
		return false;
		*/
}

bool Stack::push(ItemType1 &item) {
	try {
		Node *newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;
		if (topNode == NULL) {
			topNode = newNode;

			// push the node into the stack.

			// "return" to the user the item that has been addded.
			item = topNode->item;
		}
		else {
			// make the newNode point to the TopNode first.
			newNode->next = topNode;

			//topNode->next = newNode;
			// this is a wrong approach :D
			// it should be 
			topNode = newNode;
			// make the topNode point to the just recently "stacked" node.
			//topNode = newNode;
			item = topNode->item;
		}
		return true;
	}
	catch (exception ex){
		cout << "GGWP" << endl;
		return false;
	}
}

bool Stack::pop() {
	// pop the item from the top of the linked list.
	if (topNode != NULL) {
		Node* temp = new Node;
		temp = topNode;
		topNode = topNode->next;
		delete temp;
		return true;
	}
	else {
		cout << "There are no items in the stack!" << endl;
		return false;
	}
}

void Stack::getTop(ItemType1 &item) {
	// Updated and cleaner algo
	if (!isEmpty())
		item = topNode->item;
}
	/*// OR
	//Big O(1)
	if (topNode != NULL)
		item = topNode->item;
	else {
		item = NULL;
		cout << "There are no items in the stack!" << endl;
	}
	*/


bool Stack::pop(ItemType1 &item) {
	// pop the item from the top of the linked list.
	if (topNode != NULL) {
		Node* temp = new Node;
		temp = topNode;
		// this is the line to be added
		item = topNode->item;
		//
		topNode = topNode->next;
		delete temp;
		return true;
	}
	else {
		cout << "There are no items in the stack!" << endl;
		return false;
	}
}

void Stack::displayInOrder() {
	// check if the topNode == NULL;
	ItemType1 item;
	// even though the item variable is not assigned to any value.
	// the item will be assigned to a value
	// from getTop(item)
	// as it is passed by reference.
	if (!isEmpty()) {
		while (!isEmpty()) {
			getTop(item);
			pop();
			cout << item << endl;
		}
	}
}
	/*// display the nodes from the top to the bottom
	// big 0(n)
	if (topNode == NULL)
		cout << "There are no items in the stack!" << endl;
	else {
		bool success = true;
		while (success) {
			if (topNode->next != NULL) {
				cout << topNode->item << ", ";
				topNode = topNode->next;
			}
			else {
				cout << topNode->item << endl;
				success = false;
			}
		}
	}
}
// this approach is wrong because:
// 1. the topNode is a global variable and will point to the last node;
// 2. The code is too slow.
// the compiler prints from left to right
// whichever comes first will print from the left
*/

void Stack::displayInOrderOfInsertion() {
	// recently pushed to the beginning of time.
	ItemType1 item;
	Stack tempStack;
	// create a temporary stack to store the values from the
	if (!isEmpty()) {
		while (!isEmpty()) {
			getTop(item);
			// the item will have a value
			// that is found at the top of the stack.
			pop();
			// then i pop the topNode
			// aka remove it and delete it.
			tempStack.push(item);
			// push the topNode to become the bottomNode;
		}
		// the above while loop is just to add the topNode to become
		// the bottom node in the other stack for displaying purposes.
		while (!tempStack.isEmpty()) {
			// by now, the original stack has one less node
			tempStack.getTop(item);
			// gets the topNode of the tempStack;
			tempStack.pop();
			cout << item << endl;
			// there is a need to push the node back into the 
			push(item);
		}
	}
}
void Stack::evaluateInfix(ItemType1 infix) {
	// Create a temporary stack to store the operators
	Stack operatorStack;
	// Create a temporary stack for the values
	// that are going to be evaluated
	Stack valueStack;
	for (int i =0 ; i < infix.lenthg)
	

}
