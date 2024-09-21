#ifndef _BINARYSEARCH_TREE
#define _BINARYSEARCH_TREE

#include"BinaryNode.h"
using namespace std;
template<class ItemType>
class BinarySearchTree
{
private:
    BinaryNode<ItemType>* rootPtr;
protected:
    void inOrderVisit(BinaryNode<ItemType>* treeRoot);
    BinaryNode<ItemType>* binarySearchAddHelper(BinaryNode<ItemType>* treeRoot, BinaryNode<ItemType>* newNodePtr);
    BinaryNode<ItemType>* getNode(BinaryNode<ItemType>* treeRoot, const ItemType& target) const;
    BinaryNode<ItemType>* removeEntry(BinaryNode<ItemType>* treeRoot, ItemType& target, bool& success);
    BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodeToBeRemoved);
    BinaryNode<ItemType>* removeLeftMost(BinaryNode<ItemType>* treeRoot, ItemType& nodeItem);
public:
    //Constructors
    BinarySearchTree();
    //Set and Get functions 
    ItemType getRootItem();
    void setRootItem(const ItemType& rootItem);
    //Other member functions
    bool isEmpty() const;
    void displayInorder();
    void binarySearchAdd(ItemType& newItem);
    bool binarySearchRemove(ItemType& anItem);
    //BinarySearch Notes: will remove data item, recursive functions will be removeEntry, removeNode, removeleftMost
};
//Constructor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
    rootPtr = NULL;
}
//Set and get functions for the item in the root
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootItem()
{
    if (rootPtr != NULL)
        return rootPtr->getItem();
    else {
        cout << "Empty tree!\n";
        exit(1);
    }
}
template<class ItemType>
void BinarySearchTree<ItemType>::setRootItem(const ItemType& rootItem)
{
    if (rootPtr != NULL)
        rootPtr->setItem(rootItem);
    else
        rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
}
//Protected functions
template<class ItemType>
void BinarySearchTree<ItemType>::inOrderVisit(BinaryNode<ItemType>* treeRoot)
{
    if (treeRoot == NULL)
        cout << "It is an empty tree!\n";
    else {
        if (treeRoot->getLeftChildPtr() != NULL)
            inOrderVisit(treeRoot->getLeftChildPtr());
        cout << treeRoot->getItem() << endl;
        if (treeRoot->getRightChildPtr() != NULL)
            inOrderVisit(treeRoot->getRightChildPtr());
    }
}
//Other public member functions
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
    return (rootPtr == NULL);
}
template<class ItemType>
void BinarySearchTree<ItemType>::displayInorder()
{
    inOrderVisit(rootPtr);
}
template<class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::binarySearchAddHelper(BinaryNode<ItemType>* treeRoot, BinaryNode<ItemType>* newNodePtr)
{
    if (treeRoot == NULL) {
        treeRoot = newNodePtr;
    }
    else {
        if (newNodePtr < treeRoot) {
            //on left subtree
            treeRoot->setLeftChildPtr(binarySearchAddHelper(treeRoot->getLeftChildPtr(), newNodePtr));
        }
        else if (newNodePtr > treeRoot) {
            //on right subtree
            treeRoot->setRightChildPtr(binarySearchAddHelper(treeRoot->getRightChildPtr(), newNodePtr)); 
        }

    }
    return treeRoot; 
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::getNode(BinaryNode<ItemType> * treeRoot, const ItemType& target) const
{
    //need to return a pointer that points to the node of that target
    //if not it will return NULL in the function
    if (treeRoot == NULL) {
        return NULL;
    }
    else {
        if (target == treeRoot->getItem()) {
            return getNode(treeRoot, target);
        }
        else {
            if (target < treeRoot->getItem()) {
                return getNode(treeRoot->getLeftChildPtr(), target);
            }
            else if (target > treeRoot->getItem()) {
                return getNode(treeRoot->getRightChildPtr(), target);
            }
        }
        
    }
    
}
template<class ItemType>
void BinarySearchTree<ItemType>::binarySearchAdd(ItemType& newItem)
{
    BinaryNode<ItemType>* newNode = new BinaryNode<ItemType>(newItem);
    rootPtr = binarySearchAddHelper(rootPtr, newNode);
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeEntry(BinaryNode<ItemType> * treeRoot, ItemType& target, bool& success)
{
    if (treeRoot == NULL) {
        //return false to the node success
        success = false; 
        return success;
    }
    else {
        if (target == treeRoot->getItem()) {
            treeRoot = removeNode(treeRoot);
        }
        else {
            if (target < treeRoot->getItem()) {
                treeRoot->setLeftChildPtr(removeEntry(treeRoot->getLeftChildPtr(), target, success));
            }
            else if (target > treeRoot->getItem()) {
                treeRoot->setRightChildPtr(removeEntry(treeRoot->getRightChildPtr(), target, success));
            }

        }
        success = true;
        return success;
    }
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType> * nodeToBeRemoved)
{
    //1. if node is a leaf (if(curNode->isLeaf()) then delete the node and return NULL
    BinaryNode<ItemType>* curNode = nodeToBeRemoved;
    if (curNode->isLeaf()) {
        delete(nodeToBeRemoved);
        return NULL;
    }
    //2. if node has only one child
    else {
        if (curNode->getLeftChildPtr() == NULL || curNode->getRightChildPtr() == NULL) {
            if (curNode->getLeftChildPtr() != NULL and curNode->getRightChildPtr() == NULL) {
                //has left subtree
                curNode->getLeftChildPtr();
                curNode->setLeftChildPtr(NULL);
                delete(nodeToBeRemoved);
            }
            else if (curNode->getRightChildPtr() != NULL and curNode->getLeftChildPtr() == NULL) {
                //has right subtree
                curNode->getRightChildPtr();
                curNode->setRightChildPtr(NULL);
                delete(nodeToBeRemoved); 
            }
        }
        else {
            //has two children
            ItemType leftMost;
            curNode->setRightChildPtr(removeLeftMost(curNode->getRightChildPtr(), leftMost));
            curNode->setItem(leftMost);
        }
        return curNode;
    }
}
template<class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::removeLeftMost(BinaryNode<ItemType>* treeRoot, ItemType& nodeItem)
{
    if (treeRoot->getLeftChildPtr() == NULL) {
        nodeItem = treeRoot->getItem();
        //then delete leftmost node
        treeRoot = removeNode(treeRoot);
        //then return treeRoot
        return treeRoot;
    }
    else if (treeRoot->getLeftChildPtr() != NULL) {
        removeLeftMost(treeRoot->getLeftChildPtr(), nodeItem);
        //the return value of this recursive function call is a pointer that points to the root of the subtre
      return treeRoot->setLeftChildPtr(removeLeftMost(treeRoot->getLeftChildPtr(), nodeItem));
    }
}
template<class ItemType>
bool BinarySearchTree<ItemType>::binarySearchRemove(ItemType& anItem)
{
    bool s = false; 
    rootPtr = removeEntry(rootPtr, anItem, s);
    return s;
}
#endif 