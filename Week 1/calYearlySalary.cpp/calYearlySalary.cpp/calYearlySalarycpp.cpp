// calYearlySalarycpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Employee.h"
#include <string>;
#include <iostream>
using namespace std;


void main()
{
	//Create two Employee objects
	Employee e1("Haiqel", "Hanaffi", 10000);
	Employee e2("Someone", "Else", 1000);

	cout << "Name: " + e1.getFirstName() + ", Salary: " + to_string(e1.getMonthlySalary()) << endl;
	cout << "Name: " + e2.getFirstName() + ", Salary: " + to_string(e2.getMonthlySalary()) << endl;

	//Convert.ToString() in c# is to_string() in c++!
}

