#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class Employee
{
public:
	Employee(); //constructor
	~Employee(); //de-constructor
	Employee(string fn, string ln, int mS);

	//declare get/set methods;
	void setFirstName(string fn);
	string getFirstName();

	void setLastName(string ln);
	string getLastName();

	void setMonthlySalary(int mS);
	int getMonthlySalary();

private:
	string firstName;
	string lastName;
	int monthlySalary;


};

