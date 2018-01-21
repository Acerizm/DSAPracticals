#include "stdafx.h"
#include "Employee.h"


Employee::Employee() //real constructor
{
}


Employee::~Employee() //real desctructor
{
}

Employee::Employee(string fn,string ln,int mS) {
	firstName = fn;
	lastName = ln;
	monthlySalary = mS;
}

//define the get/set methods
// the logic in applying get/set methods in c# and c++ is totally different.
// the variables used in the get/set methods has no co-relation between the variables defined in the constructor.
void Employee::setFirstName(string fn) {
	firstName = fn;
}
string Employee::getFirstName() {
	return firstName;
}

void Employee::setLastName(string ln) {
	lastName = ln;
}

string Employee::getLastName() {
	return lastName;
}

void Employee::setMonthlySalary(int mS) {
	if (mS < 0) {
		monthlySalary = 0;
	}
	else {
		monthlySalary = mS;
	}
	
}

int Employee::getMonthlySalary() {
	return monthlySalary;
}