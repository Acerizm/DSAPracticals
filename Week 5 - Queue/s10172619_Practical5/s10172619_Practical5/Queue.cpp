#include "stdafx.h"
#include "Queue.h"
#include <string>
#include <iostream>
using namespace std;

Queue::Queue() {
	frontNode = NULL;
	backNode = NULL;
}

Queue::~Queue() {
	
}
//check if the queue is empty
bool Queue::isEmpty() 
{
	return frontNode == NULL & backNode == NULL;
	// remember to PUT THE BLOODY ==
	// SIGN TWICE
	// :D
}

bool Queue::enqueue(ItemType &item) {
	//check first if the list is full
	if (!isEmpty())
	{
		Node *newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;
		//cout << frontNode << endl;
		// point the previous backNode to the new backNode
		backNode->next = newNode;
		//make the backNode now the currently added node.
		backNode = newNode;
		return true;
		// Checked already
	}
	else 
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;
		//cout << newNode << endl;
		frontNode = newNode;
		backNode = newNode;
		//cout << frontNode << endl;
		return true;
		//checked already!
	}
}

bool Queue::dequeue()  // to dequeue the frontNode
{
	if (!isEmpty()) {
		// Time complexity of 1
		// dequeue item from the front of the queue
		Node*temp = new Node;
		temp = frontNode;
		frontNode = frontNode->next;
		delete temp;
		return true;
		//checked already
	}
	else {
		cout << "There is nothing to dequeue!" << endl;
	}
}

bool Queue::dequeue(ItemType &item)
{
	if (!isEmpty()) 
	{
		// dequeue and retrieve the item from the front of the queue
		Node*temp = new Node;
		temp = frontNode;
		item = temp->item;
		frontNode = frontNode->next;
		delete temp;
		return true;
	}
	else 
	{
		cout << "There is nothing in the queue to dequeue!" << endl;
		return false;
	}

}

void Queue::getFront(ItemType &item) 
{
	//retrieve the item from the front of the queue
	// just get the front only lah
	if (!isEmpty()) 
	{
		item = frontNode->item;
	}
	else 
	{
		cout << "There are no item in the current queue!" << endl;
	}
	//Checked already
}

void Queue::displayItems() 
{
	// Time complexity of O(n);
	Node *currentNode = frontNode;
	bool success = true;
	while (success) 
	{
		if (currentNode != backNode) 
		{
			cout << currentNode->item << +" ";
			currentNode = currentNode->next;
		}
		else 
		{
			cout << currentNode->item << endl;
			cout << "These are the contents inside the queue!" << endl;
			success = false;
		}
	}
}