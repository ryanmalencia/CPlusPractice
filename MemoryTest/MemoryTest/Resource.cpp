#include "stdafx.h"
#include "Resource.h"
#include <iostream>


Resource::Resource()
{
	cout << "Constructing resource" << endl;
}

Resource::Resource(string n)
{
	name = n;
	cout << "Constructing resource for " << name << endl;
}

Resource::~Resource()
{
	cout << "Destructing resource for " << name << endl;
}

string Resource::GetName()
{
	return name;
}
