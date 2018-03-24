#pragma once
class Item
{
private:
	int number = 0;
public:
	Item();
	~Item();
	Item(int i) { number = i; };
	int GetNumber() {
		return number;
	}
};

