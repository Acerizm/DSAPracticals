// s10172619Practical2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "List.h"// ADT List specifications
#include "Person.h"
#include <string>


// Declare all functions to be used in the future by the compiler.
// I need to decalre that a pointer variable will be used in the future in the functions declared.
void menu();
void listPhoneNumbers(List *); 
void addNewContact(List *);
void removeContact(List *);
void searchTelNo(List *);


//Main Program of c++
int main()
{
	List ContactList;
	//Declare and define the pointer to be used for the list.
	List *ptrList;
	ptrList = &ContactList;

	Person p1("John", "12345678");
	(*ptrList).add(p1);
	Person p2("Mary", "87654321");
	(*ptrList).add(p2);

	int userInput;
	int *UserInput;
	UserInput = &userInput;
	

	bool condition = true;
	bool *Condition;
	Condition = &condition;

	// I passed the address of ContactList through a pointer variable.
	//Why? So that i can pass by value to reference
	
	while (*Condition) {
		// ask the user to select the choice
		menu();
		cout << "Enter your option [0] - [4] : ";
		cin >> *UserInput; // can only get the user's values without any spacebar :(		
		cin.ignore();
		switch (*UserInput) {
		case 0:
			cout << "Thanks for using the program! " << endl;
			cout << "Hope to see you again!" << endl;
			(*Condition) = false;
			break;

		case 1:
			listPhoneNumbers((ptrList));
			break;
		case 2:
			addNewContact((ptrList));
			break;

		case 3:
			removeContact((ptrList));
			break;

		case 4:
			searchTelNo((ptrList));
			break;
		}
	}

}


//define functions here

// The main menu interface
void menu() {
	cout << " ----------------Main Menu--------------------"<< endl;
	cout << "[1] List the phone numbers\n[2] Add a new contact\n[3] Remove a contact\n[4] Search for a phone number\n[0] Exit" << endl;
	cout << " ----------------------------------------------" << endl;

}

//Function1 - listPhoneNums()
// i used "ContactList" as the pointerVariable reference so technically in the scope of the function below,
// *ContactList (arguement in function) == ptrList(pointer variable which is the address of ContactList in the main() )
// == ContactList(Variable in the main () which represents the values stored in ContactList(which is an address btw since 
//variables ==  addresses) !

void listPhoneNumbers(List (*ContactList)) {
	cout << "Phone number(s): " << endl;
	for (int i = 1; i <= (*ContactList).getLength(); i++) {
		// this is to print each telephone numbers from each Person object
		cout << (*ContactList).get(i).getTelNo() << endl;
	}
}

//Function 2 - addNewContact()
//This adds a new contact to the new contactList

void addNewContact(List (*ContactList)) {
	// declare local variables here
	string userInputName;
	string userInputTelNo;

	// Ask the user to input the name of the person
	cout << "What is the name of the person? : ";
	cin >> userInputName;

	//Ask the user what is the telephone number of the person
	cout << "What is the telephone number of the person? : ";
	cin >> userInputTelNo;

	//Instiantate a new Person class
	Person person(userInputName, userInputTelNo);

	//Add the instiantated person object into the contactList
	(*ContactList).add(person);

	//Inform the user that the instiantated object is added to the system.
	cout << userInputName + " has been added into the system!" << endl;
}

//Function3 - removeContact(List (*ContactList))
//removes the contact from the original list.
void removeContact(List(*ContactList)) {
	//declare local variables
	string userChoiceName; // the user will type the name of the contact to be removed.
	string userChoiceTelNo; // the user will enter the number of the contact.
	Person p;
	int searchResult;

	//define operations

	//Ask the user to enter the name of the contact.
	cout << "What is the contact's name to be removed? : ";
	cin >> userChoiceName;

	//Ask the user for the number of the contact.
	cout << "What is the contact's number to be removed? : ";
	cin >> userChoiceTelNo;

	// Seach for the user if the user exists in the repository (fake database)
	searchResult = (*ContactList).searchForRemove(userChoiceName, userChoiceTelNo);
	if (searchResult >= 0) {
		cout << "Removing " + userChoiceName + " -" + userChoiceTelNo;
		cout << userChoiceName + " has been removed!" << endl;
		(*ContactList).remove(searchResult+1); //.remove the first position == 1
	}
	else if (searchResult == -1) {
		cout << "There is no such user" << endl;
	}
}

//Function 4
//Search for the telephoneNumber
void searchTelNo(List(*ContactList)) {
	string userInput;
	cout << "What is the telephone number you would like to search" << endl;
	cin >> userInput;
	(*ContactList).search(userInput);
}









