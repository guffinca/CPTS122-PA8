
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


using std::string;
using std::cout;
using std::endl;


class Node
{
public:
	Node(string newData = "");
	~Node();



	string getData();
	Node*& getmpRight();
	Node*& getmpLeft();

	void setData(string newData);
	void setmpRight(Node* newRight);
	void setmpLeft(Node* newLeft);

	virtual void print() = 0;


protected:

	string mData;
	Node* mpLeft;
	Node* mpRight;
};