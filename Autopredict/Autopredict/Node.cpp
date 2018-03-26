#include "stdafx.h"
#include "Node.h"

Node::Node()
{
	Child = nullptr;
	Sibling = nullptr;
	Parent = nullptr;
}

Node::~Node()
{
}

void Node::addCharacter(char c[], int l, bool leaf)
{
	if (Level == l && c[Level] == Character)
	{

	}
	else if (Level == l && c[Level] != Character)
	{
		if (Character == 0)
		{
			Character = c[l];
			ValidLeaf = leaf;
		}
		else if (Sibling == nullptr)
		{
			Node* theSibling = new Node(c[l], l, leaf, this->Parent);
			this->Sibling = theSibling;
		}
		else if (Sibling != nullptr)
		{
			Sibling->addCharacter(c, l, leaf);
		}
	}
	else if (Level != l && c[Level] == Character)
	{
		if (Child != nullptr)
		{
			Child->addCharacter(c, l, leaf);
		}
		else
		{
			Node* theChild = new Node(c[Level + 1], Level + 1, leaf);
			this->Child = theChild;
		}
	}
	else if (Level != l && c[Level] != Character)
	{
		if (Sibling == nullptr)
		{
			Node* theSibling = new Node(c[l], l, leaf, this->Parent);
			this->Sibling = theSibling;
		}
		Sibling->addCharacter(c, l, leaf);
	}
}

bool Node::Contains(char word[], int length)
{
	if (word[Level] == Character)
	{
		if (Level < (length - 1))
		{
			if (Child != nullptr)
			{
				return Child->Contains(word, length);
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (ValidLeaf)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		if (Sibling != nullptr)
		{
			return Sibling->Contains(word, length);
		}
		else
		{
			return false;
		}
	}
	return true;
}

string Node::getClosest(string input, int count)
{
	return "";
}

void Node::setChildNode(Node* child)
{
	Child = child;
}

void Node::setSiblingNode(Node* sibling)
{
	if (sibling != nullptr)
	{
		Sibling = sibling;
	}
	else
	{
		Sibling->setSiblingNode(sibling);
	}
}

Node* Node::nextSibling()
{
	return Sibling;
}

Node* Node::nextChild()
{
	return Child;
}

void Node::setCharacter(char c)
{
	Character = c;
}

char Node::getCharacter()
{
	return Character;
}

string Node::getRestOfWord()
{
	string word = "";
	word += Character;
	if (Child != nullptr)
	{
		word += Child->getRestOfWord();
	}
	return word;
}

string Node::newBest(Node* best, bool changeLast, int count)
{
	int begin = best->Level;
	string predictions = "";
	Node* temp;
	Node* valid = nextBestNode(best, changeLast, begin);
	if (valid != nullptr)
	{
		predictions = print(valid) + ":";
		if (best->Level != valid->Level)
		{
			changeLast = true;
		}
		temp = valid;
		for (int i = 1; i < count; i++)
		{
			temp = nextBestNode(temp, changeLast, begin);
			if (temp != nullptr)
			{
				predictions += print(temp) + ":";
			}
			else
			{
				break;
			}
		}
	}
	return predictions;
}

Node* Node::nextBestNode(Node* best, bool changeLast, int begin)
{
	string word = "";
	word += best->Character;
	Node* temp;

	if (best->Child != nullptr)
	{
		temp = best;
		while (temp->Level > (begin + 1))
		{
			temp = temp->Parent;
			word = temp->Character + word;
		}
		temp = best->Child;
		word += temp->Character;

		while (!temp->ValidLeaf)
		{
			temp = temp->Child;
			word += temp->Character;
		}
		return temp;
	}
	if (best->Sibling != nullptr && changeLast)
	{
		temp = best;
		while (temp->Level > (begin + 1))
		{
			temp = temp->Parent;
			word = temp->Character + word;
		}
		temp = best->Sibling;
		word = temp->Character;
		while (!temp->ValidLeaf)
		{
			temp = temp->Child;
			word += temp->Character;
		}
		return temp;
	}
}