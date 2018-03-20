#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include "Gradebook.h"
#include "GradeStatistics.h"

using namespace std;

Gradebook::Gradebook()
{
	count = 0;
}

Gradebook::Gradebook(string name)
{
	this->name = name;
	count = 0;
}

int Gradebook::AddGrade(double grade)
{
	if (grade >= 0)
	{
		grades.push_back(grade);
		count++;
		return count;
	}
	else
	{
		return 0;
	}
}

GradeStatistics *Gradebook::ComputeStatistics()
{
	GradeStatistics *stats = new GradeStatistics();
	double sum = 0;
	double average = 0;
	double highest = 0;
	double lowest = 200;
	int i = 0;
	double current = 0;

	if (count > 0)
	{
		for (i = 0; i < count; i++)
		{
			current = grades.at(i);
			sum += current;
			if (current > highest)
			{
				highest = current;
			}
			if (current < lowest)
			{
				lowest = current;
			}

			average = sum / count;
			stats->SetStats(average, highest, lowest);
		}
	}

	return stats;
}

string Gradebook::GetName()
{
	return name;
}

int Gradebook::GetCount()
{
	return count;
}


