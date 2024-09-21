// Class template PQueue header file: PQueue.h
#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE
#include"SortedListv2.h"
template<class ItemType>
class PQueue
{
private:
    SortedList<ItemType>* sortedListPtr;
public:
    PQueue();  //Default constructor
    PQueue(const PQueue& aPQueue); //Copy constructor
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peek();
    void displayQueue();
};
//Default constructor
template<class ItemType>
PQueue<ItemType>::PQueue()
{
    sortedListPtr = new SortedList<ItemType>;
}
//Copy constructor
template<class ItemType>
PQueue<ItemType>::PQueue(const PQueue& aPQueue)
{
    sortedListPtr = new SortedList<ItemType>;
    if (!aPQueue.isEmpty()) {
        int length = aPQueue.sortedListPtr->getLength();
        ItemType anEntry;
        for (int i = 1; i <= length; i++) {
            anEntry = aPQueue.sortedListPtr->getEntry(i);
            sortedListPtr->insertSorted(anEntry);
        }
    }
}
template<class ItemType>
bool PQueue<ItemType>::isEmpty() const
{
    return(sortedListPtr->isEmpty());
}
template<class ItemType>
bool PQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    sortedListPtr->insertSorted(newEntry);
}
template<class ItemType>
bool PQueue<ItemType>::dequeue()
{
    return sortedListPtr->remove(1);
}
template<class ItemType>
ItemType PQueue<ItemType>::peek()
{
    if (isEmpty()) {
        cout << "It's an Empty Queue" << endl;
        cout << "Program aborted!" << endl;
        exit(1);
    }
    return sortedListPtr->getEntry(1);
}
template<class ItemType>
void PQueue<ItemType>::displayQueue()
{
    if (isEmpty()) {
        cout << "Queue failed" << endl;
        exit(1);
    }
    else {
        cout << "Display what in the queue" << endl;
        sortedListPtr->displayList(); 
        }
    }
}
#endif