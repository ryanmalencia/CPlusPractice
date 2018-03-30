#include "stdafx.h"
#include "DLB.h"
#include <stdlib.h>
#include "Node.h"
#include <string>
#include <iostream>
#include <fstream>

DLB::DLB()
{
}

DLB::DLB(string filename)
{
	headNode = new Node();
	Filename = filename;
	ifstream inFile;
	string word;
	int i = 0;

	inFile.open(Filename);
	while (inFile >> word)
	{
		//cout << word << endl;
		if (word.length() > 0 && !headNode->Contains(word))
		{
			for (i = 0; i < (int)word.length(); i++)
			{
				if (i == (word.length() - 1))
				{
					headNode->addCharacter(word, i, true);
				}
				else
				{
					headNode->addCharacter(word, i, false);
				}
			}
		}
	}
	inFile.close();
}

DLB::~DLB()
{
	delete(headNode);
}

void DLB::add(string word)
{
	bool contains = headNode->Contains(word);
	int i = 0;

	if (!contains)
	{
		for (i = 0; i < (int)word.length() ; i++)
		{
			if (i == (word.length() - 1))
			{
				headNode->addCharacter(word, i, true);
			}
			else
			{
				headNode->addCharacter(word, i, false);
			}
		}
	}
}

string DLB::getClosest(string input, int count)
{
	return headNode->getClosest(input, count);
	return "";
}
