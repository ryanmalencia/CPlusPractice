#include "stdafx.h"
#include "Item.h"

Item::Item()
{
}

Item::Item(int n)
{
	count = n;
}

Item::~Item()
{
}

bool Item::operator<(int i) const
{
	return count < i;
}

bool Item::operator<(Item const& p) const
{
	return count < p.count;
}

bool operator<(int i, Item const& p)
{
	return i < p.GetNumber();
}