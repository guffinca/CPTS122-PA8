#include "BST.h"


BST::~BST()
{
	destroyTree(mpRoot);
}

BST::BST()
{
	this->mpRoot = nullptr;
}

Node* BST::getRoot() const
{
	return mpRoot;
}

void BST::setRoot(Node *newRoot)
{
	mpRoot = newRoot;
}

void BST::insert(string newData, int newUnits)
{
	insert(mpRoot, newData, newUnits);

}

void BST::inOrderTraversal()
{
	inOrderTraversal(this->mpRoot);

}



//Finding the node at the bottom of the search tree then returning a refrence to it
TransactionNode& BST::findSmallest(Node* pRoot)
{
	if (pRoot->getmpLeft() == nullptr)
	{
		TransactionNode * smallest = dynamic_cast<TransactionNode*> (pRoot);
		return *smallest;
	}
	else
	{
		 findSmallest(pRoot->getmpLeft());
	}


}

//Same thing as above except findind the largest
TransactionNode& BST::findLargest(Node* pRoot)
{
	//I keep on getting an exception thrown here and i 
	if (pRoot->getmpRight() == nullptr)
	{
		TransactionNode * smallest = dynamic_cast<TransactionNode*> (pRoot);
		return *smallest;
		
		
		
	}
	else
	{
		
		findLargest(pRoot->getmpRight());
		
		
		
	}
}


//function from Andy
void BST::destroyTree(Node* tree)
{
	if (tree != nullptr)
	{
		destroyTree(tree->getmpLeft());
		destroyTree(tree->getmpRight());
		delete tree;
	}

}

void BST:: insert(Node*& tree,string newData,int newUnits )
{
	//dynamically allocating a Transaction node
	TransactionNode* pTemp = dynamic_cast<TransactionNode*>(tree);

	if (tree == nullptr)
	{
		Node* pMem = new TransactionNode(newData, newUnits);
		tree = pMem;
	}
	
	else if(newUnits > pTemp->getUnits())
	{
		insert((tree->getmpRight()), newData, newUnits);
	}
	else if (newUnits < pTemp->getUnits())
	{
		insert((tree->getmpLeft()), newData, newUnits);
	}

}

void BST::inOrderTraversal(Node* pRoot)
{
	if (pRoot != nullptr)
	{
		inOrderTraversal(pRoot->getmpLeft());
		((TransactionNode*)pRoot)->print();
		cout << endl;
		inOrderTraversal(pRoot->getmpRight());
	}
	
}



