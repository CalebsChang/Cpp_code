//class template BinaryTree header file: BinaryTree.h
#ifndef _BINARY_TREE
#define _BINARY_TREE
#include"BinaryNode.h"
#include<iostream>
using namespace std;
template<class ItemType>
class BinaryTree
{
private:
	BinaryNode<ItemType>* rootPtr;
protected:
	BinaryNode<ItemType>* createBinaryTreeHelper(BinaryNode<ItemType>* treeRoot);
	void preOrderVisit(BinaryNode<ItemType>* treeRoot);
	void inOrderVisit(BinaryNode<ItemType>* treeRoot);
	void postOrderVisit(BinaryNode<ItemType>* treeRoot);
	//Assignemnt 4.3
	BinaryNode<ItemType>* addNewItemHelper(BinaryNode<ItemType>* treeRoot);
	ItemType getSumHelper(BinaryNode<ItemType>* treeRoot);
	int getNumberOfNodesHelper(BinaryNode<ItemType>* treeRoot);
	ItemType getMaxHelper(BinaryNode<ItemType>* treeRoot);
public:
	//Constructors
	BinaryTree();
	BinaryTree(const ItemType& rootItem);
	//Set and Get functions 
	ItemType getRootItem();
	void setRootItem(const ItemType& rootItem);
	//Other member functions
	bool isEmpty() const;
	void createBinaryTree();
	void displayPreorder();
	void displayInorder();
	void displayPostorder();
	//Assignment 4.3 Functions
	void addNewItem(ItemType &newItem);
	ItemType getSum();
	int getNumofNodes();
	ItemType getMax();
};
//Constructors
template<class ItemType>
BinaryTree<ItemType>::BinaryTree()
{
	rootPtr = NULL;
}
template<class ItemType>
BinaryTree<ItemType>::BinaryTree(const ItemType& rootItem)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
}
//Set and Get functions
template<class ItemType>
ItemType BinaryTree<ItemType>::getRootItem()
{
	if (rootPtr != NULL)
		return rootPtr->getItem();
	else {
		cout << "Empty tree!\n";
		exit(1);
	}
}
template<class ItemType>
void BinaryTree<ItemType>::setRootItem(const ItemType& rootItem)
{
	if (rootPtr != NULL)
		rootPtr->setItem(rootItem);
	else
		rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
}
template<class ItemType>
bool BinaryTree<ItemType>::isEmpty() const
{
	return(rootPtr == NULL);
}
//Assignment 15: Please complete following member functions
template<class ItemType>
BinaryNode<ItemType>* BinaryTree<ItemType>::createBinaryTreeHelper(BinaryNode<ItemType>* treeRoot)
{
	ItemType a;
	char b;
	cout << "Please enter a data item: " << endl;
	cin >> a;
	treeRoot = new BinaryNode<ItemType>(a);
	cout << "Continue to the left of " << a << "? Enter y for yes and n for no" << endl;
	cin >> b;
	if (b == 'y') {
		treeRoot->setLeftChildPtr(createBinaryTreeHelper(treeRoot->getLeftChildPtr()));
	}
	cout << "Continue to the right of " << a << "? Enter y for yes and n for no" << endl;
	cin >> b;
	if (b == 'y') {
		treeRoot->setRightChildPtr(createBinaryTreeHelper(treeRoot->getRightChildPtr()));
	}
	return treeRoot;
}
template<class ItemType>
void BinaryTree<ItemType>::preOrderVisit(BinaryNode<ItemType>* treeRoot)
{
	if (treeRoot != NULL) {
		cout << treeRoot->getItem() << endl;
		preOrderVisit(treeRoot->getLeftChildPtr());
		preOrderVisit(treeRoot->getRightChildPtr());
	}
}
template<class ItemType>
void BinaryTree<ItemType>::inOrderVisit(BinaryNode<ItemType>* treeRoot)
{
	if (treeRoot != NULL) {
		inOrderVisit(treeRoot->getLeftChildPtr());
		cout << treeRoot->getItem() << endl;
		inOrderVisit(treeRoot->getRightChildPtr());
	}
}
template<class ItemType>
void BinaryTree<ItemType>::postOrderVisit(BinaryNode<ItemType>* treeRoot)
{
	if (treeRoot != NULL) {
		postOrderVisit(treeRoot->getLeftChildPtr());
		postOrderVisit(treeRoot->getRightChildPtr());
		cout << treeRoot->getItem() << endl;
	}
}
template<class ItemType>
void BinaryTree<ItemType>::createBinaryTree()
{
	rootPtr = createBinaryTreeHelper(rootPtr);
}
template<class ItemType>
void BinaryTree<ItemType>::displayPreorder()
{
	preOrderVisit(rootPtr);
}
template<class ItemType>
void BinaryTree<ItemType>::displayInorder()
{
	inOrderVisit(rootPtr);
}
template<class ItemType>
void BinaryTree<ItemType>::displayPostorder()
{
	postOrderVisit(rootPtr);
}
//Assignment 4.3
template<class ItemType>
ItemType BinaryTree<ItemType>::getMaxHelper(BinaryNode<ItemType>* treeRoot)
{
	if (treeRoot == NULL) {
		cout << "It is an empty Tree! Program aborted." << endl;
		exit(1);
	}
	else {
		ItemType m1 = treeRoot->getItem();
		if (treeRoot->getLeftChildPtr() != NULL) {
			ItemType m2 = getMaxHelper(treeRoot->getLeftChildPtr());
			if (m2 > m1)
				m1 = m2;
		}
		if (treeRoot->getRightChildPtr() != NULL) {
			ItemType m3 = getMaxHelper(treeRoot->getRightChildPtr());
			if (m3 > m1)
				m1 = m3;
		}
		return m1;
	}
}
template<class ItemType>
ItemType BinaryTree<ItemType>::getMax()
{
	return getMaxHelper(rootPtr);
}
template<class ItemType>
BinaryNode<ItemType>* addNewItemHelper(BinaryNode<ItemType>* treeRoot, ItemType& newItem)
{
	char a; 
	if (treeRoot == NULL) {
		treeRoot = new BinaryNode<ItemType>(newItem);
	}
	else {
		cout << "Would you like to add a new node on the left or right of subtree? l for left, r for right" << endl;
		cin >> a;
		if (a == 'l')
			treeRoot->setLeftChildPtr(addNewItemHelper(treeRoot->getLeftChildPtr(), newItem));
		if (a == 'r')
			treeRoot->setRightChildPtr(addNewItemHelper(treeRoot->getRightChildPtr(), newItem));
	}
	return treeRoot;
}
template<class ItemType>
void BinaryTree<ItemType>::addNewItem(ItemType& newItem)
{
	rootPtr = addNewItemHelper(rootPtr, newItem);
}
template<class ItemType>
ItemType BinaryTree<ItemType>::getSumHelper(BinaryNode<ItemType>* treeRoot)
{
	ItemType sum;
	if (treeRoot == NULL) {
		cout << "Sum failed! Program aborted." << endl;
		exit(1);
	}
	else {
		if (treeRoot->getLeftChildPtr() != NULL) {
			ItemType leftTree = getSumHelper(treeRoot->getLeftChildPtr());
			sum += leftTree;
		}
		if (treeRoot->getRightChildPtr() != NULL) {
			ItemType rightTree = getSumHelper(treeRoot->getRightChildPtr());
			sum += rightTree;
		}
	}
	return sum;
}
template<class ItemType>
ItemType BinaryTree<ItemType>::getSum()
{
	return getSumHelper(rootPtr);
}
template<class ItemType>
int BinaryTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* treeRoot)
{
	if (treeRoot == NULL) {
		cout << "Its an empty Tree" << endl;
		exit(0);
	}
	else {
		return 1 + getNumberOfNodesHelper(treeRoot->getLeftChildPtr()) + getNumberOfNodesHelper(treeRoot->getRightChildPtr());
	}
}
template<class ItemType>
int BinaryTree<ItemType>::getNumofNodes()
{
	return getNumberOfNodesHelper(rootPtr);
} 
#endif 