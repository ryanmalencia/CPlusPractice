#include "stdafx.h"
#include "GradeStatistics.h"
#include <iostream>

using namespace std;

GradeStatistics::GradeStatistics()
{
}

int GradeStatistics::SetStats(double average, double highest, double lowest)
{
	AverageGrade = average;
	HighestGrade = highest;
	LowestGrade = lowest;
	return 0;
}

int GradeStatistics::Print()
{
	cout << "Average: " << AverageGrade << endl;
	cout << "Highest: " << HighestGrade << endl;
	cout << "Lowest: " << LowestGrade << endl;
	return 0;
}