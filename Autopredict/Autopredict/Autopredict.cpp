// Autopredict.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DLB.h"
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

string getPredictions(string totalInput)
{
	return "";
}

int main()
{
	cout << "initializing trie" << endl;
	DLB trie("dictionary.txt");
	cout << "done" << endl;
	string input;
	string totalInput;
	char current;
	chrono::steady_clock::time_point start;
	chrono::steady_clock::time_point end;

	while (true)
	{
		getline(cin, input);
		current = input[0];
		totalInput += current;

		if (current == '!')
		{
			cout << "\nBye!" << endl;
			return 0;
		}
		else if (current == '$')
		{
			cout << "Success!" << endl;
			totalInput = "";
			input = "";
			continue;
		}

		cout << "Input: " << totalInput << endl;
		start = chrono::high_resolution_clock::now();
		string prediction = trie.getClosest(totalInput, 5);
		end = chrono::high_resolution_clock::now();
		cout << "Time: " << ((double)chrono::duration_cast<chrono::nanoseconds>(end - start).count()) / 1000000 << " ms" << endl;
		cout << prediction << endl;
		input = "";
	}
	return 0;
}

