#include <ostream>
#ifndef STACK
#define STACK

#include "ItemType.h"

class Stack
{
    public:
	Stack();                    // Constructor
	~Stack();                   // Destructor
	bool isEmpty();             // Empty stack test
	void push(ItemType data);	// Insert data into the stack
	ItemType pop();             // Delete data from the stack
	ItemType getTop();          // Retrieve the data at the top of the stack
	void printStack();          // Prettyprint the contents of the stack
	int getDepth();             // Retrieve the # of items in the stack

    private:
	struct StackNode
	{
	    ItemType item;
	    StackNode *next;
	};

	StackNode *top;
	int depth;
};
#endif
