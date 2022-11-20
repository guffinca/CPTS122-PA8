
#include "Node.h"
#include "TransactionNode.h"

class BST
{
public:
	~BST();
	BST();

	Node * getRoot() const;
	void setRoot(Node *newRoot);

	void insert(string newData, int newUnits );
	void inOrderTraversal();


	//I couldnt figure out how to just have it within public class, So i am doing it this way
	TransactionNode& findSmallest(Node* pRoot);
	TransactionNode& findLargest(Node* Root);

private:
	Node* mpRoot;

	void destroyTree(Node * tree);

	void insert(Node *& tree, string newData, int newUnits);
	void inOrderTraversal(Node *pRoot);

	
};
