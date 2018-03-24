#pragma once
#include <string>
#include "Resource.h"

using namespace std;

class Vehicle
{
private:
	string name;
	int number;
	Resource* pResource;


public:
	Vehicle();
	~Vehicle();
	Vehicle(Vehicle const & p);
	Vehicle(string n) { name = n; };
	Vehicle& operator=(const Vehicle& p);
	void AddResource();
	void SetName(string n);
};

