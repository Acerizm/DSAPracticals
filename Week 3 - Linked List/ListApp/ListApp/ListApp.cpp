// ListApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	//3(a)
	List nameList;
	//3(b)
	nameList.add("Annie");
	//3(c)
	nameList.add("Jacky");
	//3(d)
	nameList.add("Wendy");
	//3(e)
	nameList.print();

	//3(f)
	nameList.add(2, "Brenda");
	//3(g)
	nameList.print();

	//3(h)
	nameList.remove(3);
	//3(i)
	nameList.print();
	//3(j)
	nameList.remove(1);
	//3(k)
	nameList.print();

	
}

