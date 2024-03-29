// OperatorTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Item.h"
#include <iostream>
#include "Accum.h"

using namespace std;

template <class T>
T max(T const& t1, T const& t2)
{
	return t1 < t2 ? t2 : t1;
}

int main()
{
	//create two items
	Item *item = new Item(5);
	Item *item2 = new Item(6);

	//get max item
	cout << "Max: " << max(*item, *item2).GetNumber() << endl;

	//test less than operator
	if (*item < *item2)
	{
		cout << "Operator 1 works" << endl;
	}

	if (*item < 7)
	{
		cout << "Operator 2 works" << endl;
	}
	
	if (*item2 < 3)
	{
		cout << "Operator 3 failed" << endl;
	}
	else
	{
		cout << "Operator 3 works" << endl;
	}

	int x = item->GetNumber();
	cout << x << endl;

	Accum<int> integers(0);
	integers += 3;
	integers += 28;

	cout << integers.GetTotal() << endl;

	Accum<string> strings("");
	strings += "Yo";
	strings += " what's good?";
	cout << strings.GetTotal() << endl;

	Accum<Item> items(0);
	items += *item;
	items += *item2;
	cout << items.GetTotal() << endl;

	delete item;
	delete item2;

    return 0;
}

