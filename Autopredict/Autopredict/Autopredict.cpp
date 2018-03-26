// Autopredict.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DLB.h"
#include <ctime>
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

string getPredictions(string totalInput)
{
	return "";
}

int main()
{
	DWORD start;
	DWORD end;
	DLB trie("dictionary.txt");
	cout << "done";
	string input;
	string totalInput;
	char current;

	getline(cin, input);
	current = input[0];
	totalInput += current;

	if (current == '!')
	{
		cout << "Bye!" << endl;
		return 0;
	}

	cout << "Input: " << totalInput << endl;

	string prediction = trie.getClosest(totalInput, 5);
	cout << prediction << endl;

    return 0;
}

