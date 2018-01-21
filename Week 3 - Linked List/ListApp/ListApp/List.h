// List.h - Specification of List ADT

#pragma once
#include <iostream>
#include <string>
using namespace std;	


typedef string ItemType;

class List
{
private:
	struct Node {
		ItemType item;
		Node *next; // this allows me to store the address of the next node that i would like to link to!
	};

	Node *firstNode; //This is to declare the first node/ the head of the linked list 
	int size; //to show the number of items in the list;
	

public:

	// constructor
	List();

	~List();

	//add the first node to the list;
	// add an item to the back of the list (append)
	bool add(ItemType item);

	// add an item at a specified position in the list (insert)
	bool add(int index, ItemType item);

	// remove an item at a specified position in the list
	void remove(int index);

	// get an item at a specified position of the list (retrieve)
	ItemType get(int index);

	// check if the list is empty
	bool isEmpty();

	// check the size of the list
	int getLength();

	// display all the items in the list
	void print();


};