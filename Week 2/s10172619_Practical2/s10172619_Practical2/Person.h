#pragma once
#include <string>
using namespace std;
// here is the interface for the whole ADT.
class Person
{
public:
	
	Person(); //Constructor
	~Person(); //de-constructor / destroyer
	Person(string n, string tn); //1st Constructor

	//declaration of get/set operation
	void setName(string n); //set
	string getName(); //get


	void setTelNo(string tn); //set
	string getTelNo(); //get



private:
	string name;
	string telNo;

};

