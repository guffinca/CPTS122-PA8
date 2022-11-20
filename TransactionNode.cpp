#include "TransactionNode.h"

TransactionNode::TransactionNode()
{

}

TransactionNode::TransactionNode(string newData, int newUnits)
{
	mUnits = newUnits;
	this->setData(newData);


}

TransactionNode::~TransactionNode()
{

}

int TransactionNode::getUnits() const
{
	return mUnits;
}

void TransactionNode::setUnits(int newUnits)
{
	mUnits = newUnits;
}

//Overiding pure vitrual funcrtion in Node
void TransactionNode::print() 
{
	cout << "Data: " << getData()<<"; " << "Units: " << getUnits();;
	

}