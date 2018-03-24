#pragma once
#include "Node.h"
#include <string>

using namespace std;

class DLB
{
private:
	Node* headNode;
	string Filename;
public:
	DLB();
	DLB(string filename);
	~DLB();
	void add(string word);
	string getClosest(string input, int count);
};

