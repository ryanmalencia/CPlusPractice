#pragma once
#include <string>

using namespace std;

class Node
{
private:
	Node* Child;
	Node* Sibling;
	Node* Parent;
	char Character;
	int Level;
	bool ValidLeaf;
public:
	Node();
	Node(int l) { Level = l; Node(); };
	Node(char c, int l)
	{
		Character = c;
		Level = l;
		Node();
	};
	Node(char c, int l, bool leaf)
	{
		Character = c;
		Level = l;
		ValidLeaf = leaf;
		Node();
	};
	Node(char c, int l, bool leaf, Node* parent)
	{
		Character = c;
		Level = l;
		ValidLeaf = leaf;
		Node();
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

