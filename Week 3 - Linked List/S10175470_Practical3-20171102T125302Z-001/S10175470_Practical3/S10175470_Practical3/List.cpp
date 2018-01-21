#include "stdafx.h"
#include "List.h"

List::List()
{
}


List::~List()
{
}


bool List::add(ItemType item)
{
	Node *newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;
	if (firstNode == NULL)
	{
		firstNode = newNode;
	}
	else
	{
		Node *current = firstNode;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	size++;

	return true;
}
int List::getLength()
{
	return size;
}
bool List::isEmpty()
{
	if (firstNode == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void List::remove(int index)
{
	bool success = (index >= 1) && (index <= size);
	if (index == 1)
		firstNode = firstNode->next;
	else
	{
		Node* current = firstNode;
		Node* previous = firstNode;
		for (int i = 1; i < index; i++)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}
	size--;
}
ItemType List::get(int index)
{
	ItemType item = "NULL";
	bool success = (index >= 1) && (index <= size);
	if (success)
	{
		Node* current = firstNode;
		for (int i = 1; i < index; i++)
			current = current->next;
		item = current->item;
	}
	return item;

}
bool List::add(int index, ItemType item)
{
	bool success = (index >= 1) && (index <= size);
	if (success)
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;
		
		if (index == 1)
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			Node* temp = firstNode;
			for (int i = 2; i < index; i++)
			{
				temp = temp->next;

			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		size++;
	}
	return success;
}
void List::print()
{
	Node *temp = firstNode;
	while (temp != NULL)
	{
		cout << temp->item << endl;
		temp = temp->next;
	}

}