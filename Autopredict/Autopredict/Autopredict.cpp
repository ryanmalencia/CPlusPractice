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

	getline(cin, input);
	current = input[0];
	totalInput += current;

	if (current == '!')
	{
		cout << "Bye!" << endl;
		return 0;
	}

	cout << "Input: " << totalInput << endl;
	auto start = std::chrono::high_resolution_clock::now();
	string prediction = trie.getClosest(totalInput, 5);
	auto end = std::chrono::high_resolution_clock::now();
	cout << "Time: " << ((double)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count())/1000000 << " ms" << endl;
	cout << prediction << endl;

    return 0;
}

