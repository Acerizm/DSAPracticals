// s10172619Practical7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int search(int dataArray[], int arraySize, int target);
int binarySearch(int dataArray[], int arraySize, int target);
int search(int dataArray[], int n, int start, int target);
int binarySearch(int dataArray[], int first, int last, int target);
static int comparisons = 0;

void main()
{
	
	cout << "********************" << endl;
	cout << " Question 2 ( using sequential iterative search): " << endl;
	int dataArray[1000];
	int arrayByteSize = sizeof(dataArray);
	//cout << arrayByteSize << endl;
	int elementByteSize = sizeof(dataArray[0]);
	//cout << elementByteSize << endl;
	int arraySize = (arrayByteSize / elementByteSize);
	//cout << arraySize << endl;
	for (int i = 0; i <= 999; i++) {
		dataArray[i] = (i + 1) * 2;
	}
	cout << "Please enter a target number to search: ";
	int target;
	cin >> target;
	if (search(dataArray, arraySize, target) != -1) {
		cout << target << +" is found!" << endl;
	}
	else {
		cout << target << " is not found" << endl;
	}
	cout <<"********************"<< endl;
	cout << " Question 2 ( using iterative binary search): " << endl;
	cout << "Please enter a target number to search: ";
	cin >> target;
	if (binarySearch(dataArray, arraySize, target) != -1)
		cout << target << +" is found!" << endl;
	else
		cout << target << +" is not found!" << endl;
	cout << "********************" << endl;
	cout << "Question 6: " << endl;
	comparisons = 0;
	int idx1 = search(dataArray, arraySize, target);
	if (idx1 != -1)
		cout << "Found" << endl;
	else
		cout << "Not Found" << endl;
	cout << "Sequential Search : " << comparisons << endl;

	comparisons = 0;
	int idx2 = binarySearch(dataArray, arraySize, target);
	if (idx2 != -1)
		cout << "Found" << endl;
	else
		cout << "Not Found" << endl;
	cout << "Binary Search : " << comparisons << endl;


	system("PAUSE");


}

// iterative sequential search
int search(int dataArray[], int arraySize, int target) {
	// this is a sequential search.
	for (int i = 0; i < arraySize; i++) {
		comparisons++;
		if (dataArray[i] == target) // found
		{
			return i;
		}
		else { // not found
			if (dataArray[i] > target)
				return -1;
		}
	}
	return -1;
}

// binary sequential search
int binarySearch(int dataArray[], int arraySize, int target) {
	int first = 0; // the first index
	int last = arraySize - 1; // the last index;
	while (first <= last) {
		comparisons++;
		int mid = (first + last) / 2;
		if (dataArray[mid] == target) { //found
			return mid;
		}
		else {
			if (target < dataArray[mid]) {
				last = mid - 1; // search the first half 
			}
				// since the target's number is lesser than the mid's number
			else {
				first = mid + 1; // search the second half
				// the last number remains.
			}
		}
	}
	return -1; // your mother die die also cannot find.
}

//Sequential search for sorted array (Recrusive version)
int search(int dataArray[], int n, int start, int target) {
	if (start > n - 1) // item is not found
		return -1;
	else {
		comparisons++;
		if (dataArray[start] == target) // item found
			return start;
		else
			if (dataArray[start] > target) // item not found
				return -1;
			else
				return search(dataArray, n, start + 2, target);
	}
}

//Binary Search for sorted array (Recursive function)
int binarySearch(int dataArray[], int first, int last, int target) {
	if (first > last) // item not found
		return -1;
	else {
		comparisons++;
		int mid = (first + last) / 2;
		if (dataArray[mid] == target) // item found
			return mid;
		else
			if (target < dataArray[mid]) // item is in the first half
				return binarySearch(dataArray, first, mid - 1, target); //search the 1st half
			else
				return binarySearch(dataArray, mid + 1, last, target); //search the 2nd half
	}
}
