
#pragma once
#include "Node.h"

using std::string;
class TransactionNode : public Node
{
public:
	TransactionNode();
	TransactionNode(string newData, int newUnits);
	~TransactionNode();
	

	int getUnits() const;
	void setUnits(int newUnits);

	void print() override;

	

private:
	int mUnits;
};