#pragma once
#include <string>
#include "GradeStatistics.h"
#include <vector>

using namespace std;
class Gradebook
{

protected:
	int count;
	vector<double> grades;
	string name;
public:
	Gradebook();
	Gradebook(string name);
	int AddGrade(double grade);
	int GetCount();
	string GetName();
	GradeStatistics *ComputeStatistics();
};

