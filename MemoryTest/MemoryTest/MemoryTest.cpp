// MemoryTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vehicle.h"

int main()
{
	Vehicle one("YES");
	one.AddResource();
	one.SetName("WOW");
	one.AddResource();
	Vehicle two = one;
    return 0;
}

