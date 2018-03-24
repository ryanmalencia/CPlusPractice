#include "stdafx.h"
#include "Vehicle.h"

Vehicle::Vehicle()
{
	pResource = nullptr;
}

Vehicle::~Vehicle()
{
	delete pResource;
}

Vehicle::Vehicle(Vehicle const & p)
{
	pResource = new Resource(p.pResource->GetName());
}

Vehicle& Vehicle::operator=(const Vehicle& p)
{
	delete pResource;
	pResource = new Resource(p.pResource->GetName());
	return *this;
}

void Vehicle::AddResource()
{
	delete pResource;
	pResource = new Resource(name);
}

void Vehicle::SetName(string n)
{
	name = n;
}