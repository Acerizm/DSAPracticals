// SampleRecursiveFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#define max(x,y) ((x > y)? x: y) // max()
void writeBackward1(string s);
void writeBackward2(string s);
int maxArray(int array[], int n);

int main()
{

	int array[] = {33,66,11,12,22,44,99,88 };

	cout << maxArray(array, 6);
	/*string s = "123456789";
	cout << s.length() << endl;
	writeBackward1(s);
	cout << endl;
	
	writeBackward2(s);
	cout << endl;
	*/
	system("PAUSE");
	return 0;


}

int maxArray(int array[], int n) {

	if (n == 0)
		return array[0];
	else
		return max(array[n - 1], maxArray(array, n - 1));
	
}
void writeBackward1(string s) 
{
	int n = s.length();
	if (n == 0) //base case
	{
		// string is empty
	}
	else { // this is always true;
		
		cout << s[n - 1] << " ";
		writeBackward1(s.substr(0, n - 1));
		
	}
}

void writeBackward2(string s) {
	int n = s.length();

	if (n == 0) {}
	else {
		cout << s[0] << " ";
		writeBackward2(s.substr(1, n - 1));
	}
}

