#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{

}

DataAnalysis::~DataAnalysis()
{

}

void DataAnalysis::openmCsvStream()
{
	mCsvStream.open("data.csv");
	

}


void DataAnalysis::readmCsvStream()
{
	
	
	TransactionNode fileData;
	char lines[50] = "";
		//getting units from file
		mCsvStream.getline(lines, 50, ',');
		fileData.setUnits(atoi(lines));

		//getting and setting data
		mCsvStream.getline(lines, 50, ',');
		fileData.setData(lines);

		string Transaction;
		getline(mCsvStream, Transaction);

		CompareAndInsert(fileData.getUnits(), fileData.getData(), Transaction);


}

void DataAnalysis::CompareAndInsert(int newUnits, string newData, string Transaction)
{
	if (Transaction == "Sold")
	{
		mTreeSold.insert(newData, newUnits);
	}
	else
	{
		mTreePurchased.insert(newData, newUnits);
	}

}

void DataAnalysis::display()
{
	openmCsvStream();
	while (!mCsvStream.eof())
	{
		readmCsvStream();

	}
	cout << "mTreeSold List: " << endl;
	mTreeSold.inOrderTraversal();
	cout << endl;
	cout << "mTreePurcashed List: " << endl;
	mTreePurchased.inOrderTraversal();
}

void DataAnalysis::displayTrends()
{
	TransactionNode &SoldLargest = mTreeSold.findLargest(mTreeSold.getRoot());
	cout << endl;
	cout << "mTreeSold List the most: " << endl;
	cout << "Type: " << SoldLargest.getData() << "; " << SoldLargest.getUnits() << endl;
	
	TransactionNode& SoldLeast = mTreeSold.findSmallest(mTreeSold.getRoot());
	cout << endl;
	cout << "mTreeSold List the least: " << endl;
	cout << "Type: " << SoldLeast.getData() << "; " << SoldLeast.getUnits() << endl;
	

	TransactionNode& PurchasedLargest = mTreePurchased.findLargest(mTreePurchased.getRoot());
	cout << endl;
	cout << "mTreePurchased List the most: " << endl;
	cout << "Type: " << PurchasedLargest.getData() << "; " << PurchasedLargest.getUnits() << endl;
	
	 TransactionNode& PurchasedLeast = mTreePurchased.findSmallest(mTreePurchased.getRoot());
	 cout << endl;
	cout << "mTreePurchased List the least: " << endl;
	cout << "Type: " << PurchasedLeast.getData() << "; " << PurchasedLeast.getUnits() << endl;
	
}

void DataAnalysis::runAnalysis()
{
	display();
	displayTrends();
	

}