#include "Node.h"

Node:: ~Node()
{

}


Node::Node(string newData)
{
	this->mData = newData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

string Node:: getData() 
{
	return mData;
}
Node*& Node:: getmpRight()
{
	return mpRight;
}
Node*& Node::getmpLeft()
{
	return mpLeft;
}

void Node:: setData(string newData)
{
	mData = newData;
}
void Node::setmpRight(Node* newRight)
{
	mpRight = newRight;
}
void Node:: setmpLeft(Node* newLeft)
{
	mpLeft = newLeft;
}

void Node::print()
{
	cout <<"Data: "<< getData();
	

}