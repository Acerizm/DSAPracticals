// s10172619Practical6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#define max(x,y) ((x>y)? x:y)
using namespace std;

long power(int a, int n);
int ReqSum(int array[], int n);
int SeqSum(int array[], int arraySize);

static int Sum = 0;

void main()
{
	cout << power(3, 3) << endl;
  

	int NumberArray[10];
	int ArrayBytes = sizeof(NumberArray);
	int arraySize = ArrayBytes / sizeof(NumberArray[0]);
	for (int i = 0; i < arraySize; i++)
		NumberArray[i] = i + 1;

	cout << "recursive Computation : " << ReqSum(NumberArray, arraySize) << endl;

	cout << "Sequential Iteration Computation : " << SeqSum(NumberArray, arraySize) << endl;
}

long power(int a, int n) {
	// code the base case
	if (n == 0)
		return 1;
	else {
		// a^n = a*a^(n-1)
		return a * power(a, n - 1);
	}
}

// compute (and return) the sum of an array of numbers
// recursive way
int ReqSum(int array[], int n) {

	// do the base case first
	if (n == 0)
		return 0;
	else
		return array[n - 1] + ReqSum(array, n - 1);
}
//------------------------------------------------------------------------
/*
------- In the stack -----------------------------------------------------
Top Of Stack
--------------------------------------------------------------------------
4. 4th processs
 - call reqSum(array,0)
 - the base case is executed;
 - if ( n==0 ):
	returrn 0 ;
--------------------------------------------------------------------------
3. 3rd process
 - call reqSum(array,1);
 - return array[1-1 = 0];
 - return 1 +
 - do ReqSun(array, 1-1 = 0);
--------------------------------------------------------------------------
2. 2nd process
 - call ReqSum(array, 2);
 - return array[2-1 = 1] + ReqSum(array, 2-1 = 1);
 - return 2 + 
 - do ReqSum(array,2-1 = 1);
--------------------------------------------------------------------------
1. 1st Process.
 - call ReqSum(array,arraySize =3);
 - return array[3-1 = 2] + ReqSum(array,3-1 = 2);
 - return 3 + 
 - do ReqSum(array, 3-1 = 2);
 -------------------------------------------------------------------------
 Bottom of Stack
 -------------------------------------------------------------------------

 What the compiler does:
 1. Call reqSum(array,0) ---> 0;
 2. Call reqSum(array,1) ---> 1 + 0 = 1
 3. Call reqSum(array,2) ---> 2 + 1 = 3
 4. Call reqSum(array,3) ---> 3 + 3 = 6

  All are done by doing the top of the stack first
*/
// the sequential itterative way
int SeqSum(int array[], int arraySize) {
	// no need base case
	// cut the bullcrap and continue the forloop.
	for (int i = 0; i < arraySize; i++) {
		// arraySize is used to measure the number of elements present in the array
		Sum += array[i];
		// this method is iterative;
	}
	return Sum;
}

// find (and return) the highest value in the array
int maxArray(int array[], int n) {
	if (n == 1) // base case
		return array[n - 1];
	else
		return max(array[n - 1], maxArray(array, n - 1));
}



// 2^2 = 2*2^(2-1)
// 2^3 = 2*2^(3-1) = 2*2^(2)


// power(2,1)

