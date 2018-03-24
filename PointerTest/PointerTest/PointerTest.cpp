// PointerTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Item.h"
#include <iostream>

using namespace std;

int main()
{
	//Object
	Item item(1);
	//Object Pointer
	Item *item2 = new Item(2);

	cout << item.GetNumber() << endl;
	cout << item2->GetNumber() << endl;

	delete(item2);

    return 0;
}

