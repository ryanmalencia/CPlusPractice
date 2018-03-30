#pragma once
#include <string>

using namespace std;

class Node
{
private:
	Node * Child;
	Node* Sibling;
	Node* Parent;
	char Character;
	int Level;
	bool ValidLeaf;
public:
	Node();
	Node(int l) {
		Child = nullptr;
		Sibling = nullptr;
		Parent = nullptr;
		Level = l;
		Character = 0;
		ValidLeaf = false;
	};
	Node(char c, int l)
	{
		Child = nullptr;
		Sibling = nullptr;
		Parent = nullptr;
		ValidLeaf = false;
		Character = c;
		Level = l;
	};
	Node(char c, int l, bool leaf)
	{
		Child = nullptr;
		Sibling = nullptr;
		Parent = nullptr;
		Character = c;
		Level = l;
		ValidLeaf = leaf;
	};
	Node(char c, int l, bool leaf, Node* parent)
	{
		Child = nullptr;
		Sibling = nullptr;
		Character = c;
		Level = l;
		ValidLeaf = leaf;
		Parent = parent;
	}
	~Node();
	void setChildNode(Node* child);
	void setSiblingNode(Node* sibling);
	Node* nextSibling();
	Node* nextChild();
	void setCharacter(char c);
	bool Contains(string word);
	void addCharacter(string c, int l, bool leaf);
	char getCharacter();
	string print(Node* node);
	string getClosest(string input, int count);
private:
	string getRestOfWord();
	string newBest(Node* best, bool changeLast, int count);
	Node* nextBestNode(Node* best, bool changeLast, int begin);
};