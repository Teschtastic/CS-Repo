#ifndef QUEUE
#define QUEUE

#include "ItemType.h"

class Queue
{
    public:
	Queue();			// Constructor
	~Queue();			// Destructor
	bool isEmpty();			// Empty queue test
	void enqueue(ItemType data);	// Insert data into queue
	ItemType dequeue(); 		// Delete data from the queue
	ItemType getFront();		// Retrieve data from the front of the queue
	void printQueue();		// Prints the contents of the queue
	int getLength(); 		// Retrieve the number of items in the queue
    private:
        struct QueueNode
        {
            ItemType item;
            QueueNode *next;
        };

    QueueNode *front, *back;
    int length;
};
#endif

