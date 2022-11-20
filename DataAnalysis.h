
#pragma once
#include "BST.h"


using std::ifstream;

class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis();

private:

	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;
 void openmCsvStream();
	void readmCsvStream();
	void CompareAndInsert(int newUnits, string newData, string Transaction);
	void display();

	void displayTrends();


};