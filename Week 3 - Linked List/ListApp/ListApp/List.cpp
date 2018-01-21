// List.cpp - Implementation of List ADT using Array
#include "stdafx.h"
#include "List.h"  // header file

// constructor
List::List() {  }
// i can access the private attribute which is items[Max_Size] 
// which is the array!

List::~List() {}

bool List::add(ItemType item) {
	Node *newNode = new Node; //Create a new node;
	newNode->item = item; //add the whole node object into the node object.
	newNode->next = NULL; // to not point to any variable.
	if (firstNode == NULL) { 
		// this means that the firstNode/head of the link
		//does not point to anything.
		firstNode = newNode; 
		// the address of the *firstNode will be 
		// the address of the newly created node
		// take note: firstNode != firstNode->next;
	}
	else {
		Node *current;
		current = firstNode;
		// THIS IS THE SAME AS
		// Node *current = firstNode;
		// create a current node to store the address of the firstNode
		// or simply means that current will point to the address
		// of the node that is created.

		while (current->next != NULL) {
			// this to check if there is a last node.
			// the last node will point to nothing.
			current = current->next;
			//the purpose of this code so that the current
			// will be exact.
			// the current will also start from THE BEGINNING
			//EVERYTIME? NO FASTER WAY?
		}
		current->next = newNode;
	}
	size++;

	return true;
}

int List::getLength() {
	return size;
}
bool List::isEmpty() {
	if (firstNode == NULL) {
		// just check if the address of the *firstNode is NULL
		// to see if the list is empty
		return true;
	}
	else {
		return false;
	}
}

void List::remove(int index) {
	bool success = (index >= 1) && (index <= size);
	if (index == 1)
		firstNode = firstNode->next;
	// why never remove the first node????????
	else {
		Node *current;
		current = firstNode;
		Node *previous;
		previous = firstNode;
		for (int i = 1; i < index; i++) {
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}
	size--;
}
ItemType List::get(int index) {
	ItemType item = "NULL";
	// ItemType represents string!;
	// the reason we did this so that the pointer's attributes
	// will have this value;
	bool success = (index >= 1) && (index <= size);
	// success will either return true or false;
	// if the index is found in the range;
	// then it will return true;
	if (success) { // if true;

		Node *current;
		current = firstNode;
		// always remember that the current will
		// always start from the firstNode HAHA;
		for (int i = 1; i < index; i++) {
			current = current->next;
		}
		item = current->item;
		// the item will represent the value;
		// that is pointed by the pointer variable;
		// no need to use pointers here.
		// item variable is local to the scope of the function;
	}
	return item; // returns the value;
}

bool List::add(int index, ItemType item) {
	// where index represents the index to be found
	// and ItemType represents string.
	// which is the value to be added to a node;
	bool success = (index >= 1) && (index <= size);
	// always remember to check if the value can be added
	// to the linked list;
	if (success) { // if true;
		Node *newNode;
		newNode = new Node;
		// remember to create a new node;
		newNode->item = item;
		newNode->next = NULL;

		if (index == 1) {
			newNode->next = firstNode;
			// make the newNode point to the firstNode's address
			firstNode = newNode;
			// need to check with my brain;
		}
		else {
			Node *temp;
			temp = firstNode;
			for (int i = 2; i < index; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		size++;
	}
	return success;
}

void List::print() {
	Node *temp;
	temp = firstNode;
	while (temp != NULL) {
		cout << temp->item << endl;
		temp = temp->next;
	}
}