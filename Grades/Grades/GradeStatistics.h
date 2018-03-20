#pragma once
class GradeStatistics
{
protected:
	double AverageGrade;
	double HighestGrade;
	double LowestGrade;
public:
	GradeStatistics();
	int SetStats(double average, double highest, double lowest);
	int Print();
};

