#include <iostream>
#include "ItemType.h"
#include "stack.h"

using namespace std;

Stack::Stack()                  // Constructor
{
    top = NULL;
    depth = 0;
}

Stack::~Stack()                 // Destructor
{
    StackNode *dispose;
    dispose = top;
    while (top != NULL)
    {
        top = top -> next;
        delete(dispose);
        dispose = top;
    }
}

bool Stack::isEmpty()           // Empty Stack test
{
    return top == NULL;
}

void Stack::push(ItemType data) // Insert data into stack
{
    StackNode *add;
    add = new(StackNode);
    add -> next = top;
    add -> item = data;
    top = add;
    depth++;
}

ItemType Stack::pop()           // Delete data from stack
{
    StackNode *temp;
    temp = top;
    if (top = NULL)
        cout << "There is a possible error. Empty Stack." << endl;
    else
    {
        top = top -> next;
        delete(temp);
        temp = top;
    }
}

ItemType Stack::getTop()
{
    return(top -> item);
}

void Stack::printStack()
{
    ItemType data;                              // Declared the data variable
    cout << "Dumping the stack... " << endl;    // Output message
    StackNode *temp = top;                    // Setting a temp variable to the same as front
    while (temp != NULL)                        // While the temp file isn't null
    {
        data = temp -> item;                        // Set data to the value of item temp is pointing to
        cout << data << endl;                       // Output the value of data
        temp = temp -> next;                        // Set temp to the next item in the queue
    }
}

int Stack::getDepth()
{
    return depth;
}

