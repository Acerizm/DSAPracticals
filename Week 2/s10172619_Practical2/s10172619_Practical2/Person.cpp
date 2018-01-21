#include "stdafx.h"
#include "Person.h"
// Since we're using an interface, we need to

Person::Person() {} //Real constructor
Person::~Person() {} //real destructor

Person::Person(string n, string tn) // implementation of the person's 1st constructor.
{
	name = n; //define the attributes in the constructor
	telNo = tn;
}
void Person::setName(string n) { name = n; } //define the setter method
string Person::getName() { return name; } //define the getter method

void Person::setTelNo(string tn) { telNo = tn; } //define the setter method
string Person::getTelNo() { return telNo; } // define the getter method


