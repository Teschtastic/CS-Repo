#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack()                              // Constructor
{
    top = NULL;
    depth = 0;
}

Stack::~Stack()                             // Destructor
{
    node *temp;
    while (top != NULL)
    {
        temp = top;
        top = top -> next;
        delete(temp);
    }
    depth = 0;
}

void Stack::push(int item)      // Push an item onto the Stack
{
    node *temp;
    temp = new (node);
    temp -> next = top;
    temp -> info = item;
    top = temp;
    depth++;
}

bool Stack::isEmpty()                       // Empty Stack test
{
    if (top == NULL)
        cout << "The Stack is empty. " << endl;
    else
        cout << "The Stack is not empty. " << endl;
}

int Stack::pop()                 // Pop an item from the Stack
{
    node *temp;
    if (top == NULL)
    {
        cout << "The stack is empty. " << endl;
    }
    else
    {
        temp = top;
        cout << "Deleting element: "<< temp -> info << endl;
        top = top -> next;
        delete(temp);
        depth--;
    }
}

void Stack::printStack()           // Print the stack
{
    node *temp;
    temp = top;
    
    
    if (top == NULL)
    {
        cout << "Stack is empty. " << endl;
    }

    else
    {
        cout << "Stack elements: " << endl;
        while (temp != NULL)
        {
            cout << temp -> info << endl;
            temp = temp -> next;
        }
    }
    
}

int Stack::getDepth()
{
    return depth;
}

