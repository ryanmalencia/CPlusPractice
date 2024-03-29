// Grades.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Gradebook.h"
#include "GradeStatistics.h"
#include <fstream>

using namespace std; 

int main(int argc, char *argv[])
{
	string name = argv[1];
	ifstream inFile;
	double x;
	Gradebook *book = new Gradebook();
	GradeStatistics *stats;

	inFile.open(name);

	while (inFile >> x)
	{
		book->AddGrade(x);
	}

	inFile.close();

	stats = book->ComputeStatistics();

	stats->Print();

    return 0;
}

