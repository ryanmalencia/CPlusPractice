#pragma once
#include <string>
class Item
{
private:
	int count;

public:
	Item();
	Item(int n);
	~Item();
	bool operator<(Item const& p) const;
	bool operator<(int i) const;
	int GetNumber() const { return count; }
	int SetNumber(int number) {
		count = number;
		return count;
	}
};

bool operator<(int i, Item const& p);
