#pragma once
#include <string>

using namespace std;

class Resource
{
public:
	Resource(string p);
	Resource();
	~Resource();
	string name;
	string GetName();
};

