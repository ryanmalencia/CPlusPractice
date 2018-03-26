#include "stdafx.h"
#include "DLB.h"


DLB::DLB()
{
}

DLB::DLB(string filename)
{
	Filename = filename;
}

DLB::~DLB()
{
}

void DLB::add(string word)
{
	char characters[128];
	strcpy_s(characters, word.c_str());
	bool contains = headNode->Contains(characters, (int)word.length());
	if (!contains)
	{
		for (int i = 0; i < word.length() ; i++)
		{
			if (i == (word.length() - 1))
			{
				headNode->addCharacter(characters, i, true);
			}
			else
			{
				headNode->addCharacter(characters, i, false);
			}
		}
	}
}

string DLB::getClosest(string input, int count)
{
	return headNode->getClosest(input, count);
	return "";
}
