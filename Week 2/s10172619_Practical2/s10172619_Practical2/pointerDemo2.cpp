#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//declare functions here
//a)	Write a function changeValue that receives two parameters :
	//	1)	x(of integer data type)
	//  2)	y(a pointer variable to a integer)

void changeValue(int x, int (*y)) {
	x += 10;
	*y += 10;

}

void main() {
	 //declare an int x and assign it to 30;
	int x = 30;
	// declare another int y;
	int y;
	y = x;

	//Make function call and pass in x and the address of y respectively.
	changeValue(x, &y);

	cout << x << endl;
	cout << y << endl;

	// x and y in the main is the same as compared to the x and y in the changeValue.


}