// s10172619Practical5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;


void main()
{
	ItemType item;
	ItemType1 item1;
	//a)
	// create an empty queue;
	cout << "a)" << endl;
	Queue q;
	// b)
	//cout << "b)" << endl;
	q.enqueue(item = 'a');
	// c)
	q.enqueue(item = 'b');
	// d)
	cout << "d)" << endl;
	q.getFront(item);
	cout << item << endl;
	// f)
	// Dequeue q
	q.dequeue();
	// g)
	// Display all items in q
	q.displayItems();

	// Create a stack to store the user's input in a stack
	Stack s1;

	//Create a different queue to store the user's input in a queue
	Queue q1;

	//Read the user input
	string userInput;
	cout << "" << endl;
	cout << "Please enter a word so that we can check if it's a palindrome: ";
	getline(cin, userInput);

	// do a for-loop
	for (int i = 0; i < userInput.length(); i++) {
		
		s1.push(item1 = userInput[i]);
		q1.enqueue(item = userInput[i]);
	}
	
	//check for palindrome
	int error = 0;
	for (int x = 0; x < userInput.length(); x++) 
	{
		
		s1.getTop(item1);
		q1.getFront(item);
		if (item == item1) 
		{
			s1.pop();
			q1.dequeue();
		}
		else 
		{
			s1.pop();
			q1.dequeue();
			error++;
			break;
		}
	}

	if (error == 0) 
	{
		cout << userInput << +" is a palindrome!" << endl;
	}
	else if (error != 0) {
		cout << userInput << +" is not a palidrome!" << endl;
	}


}

