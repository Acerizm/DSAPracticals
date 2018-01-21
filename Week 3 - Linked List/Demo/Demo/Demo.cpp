// Demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Node;
void print(Node *List);
void add(Node * &list, string item);


struct Node {
	string item;
	Node *next; //decalre the pointer variable
				//next represents the address of the current node.
}; // structs must end with a semi-colon;


void main()
{
	/*Node node1; //Instiantate the node.
	node1.item = "Item1";
	node1.next = NULL;

	Node node2;
	node2.item = "item2";
	node2.next = NULL;
	*/
	Node* list = NULL;

	//node1.next = &node2;

	//Node *list = &node1;

	add(list, "Item1");

	/*while (list != NULL) {
		cout << list->item << endl;
		list = list->next;
	}
	*/
	print(list);
}


void print(Node* list) {
	Node* current = list;
	while (current != NULL) {
		cout << current->item << endl;
		current = current->next;
	}

}

void add(Node* &list, string item) {
	Node* newNode = new Node;
	//Node newNode = new Node;
	//&newNode->item = item
	newNode->item = item;
	newNode->next = NULL;

	if (list == NULL) {
		list = newNode;
	}
	else {
		Node* previous = list;
		Node* current = list;
		while (current != NULL) {
			previous = current;
			current = current->next;
		}
		previous->next = newNode;
	}
}
