#include <ostream>
#ifndef STACK
#define STACK

class Stack
{
public:
    Stack();                        // Constructor
    ~Stack();                       // Destructor
    void push (int item);           // Push function
    bool isEmpty();                 // Checks if stack is empty
    int pop ();                     // Pop function
    void printStack ();             // Prints stack
    int getDepth();                 // Get the depth of stack
    
private:
    struct node
    {
        int info;
        struct node *next;
    };

	node *top;
    int depth;
};
#endif
