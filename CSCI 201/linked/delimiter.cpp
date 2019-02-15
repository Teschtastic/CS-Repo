/*
 Sean Tesch   CSCI 201    Assignment #2
 Due: Monday, September 21, 2015 @ Midnight
 
 To compile, write in the command line:
 g++ -o driver driver.cpp queue.cpp ItemType.cpp
 
 To run, write in the command line:
 ./driver
 */

#include <iostream>
#include "stack.h"

using namespace std;

void menu()
{
    cout << endl << "Main menu: " << endl << endl;
    cout << "1. Check to see if the stack is empty. " << endl;
    cout << "2. Get the depth of the stack. " << endl;
    cout << "3. Push element onto Stack. " << endl;
    cout << "4. Pop element from Stack. " << endl;
    cout << "5. Print the Stack. " << endl;
    cout << "6. Delete Stack. " << endl;
    cout << "7. Quit" << endl << endl;
    cout << "Enter your choice: ";
}

int main()
{
    int choice, item;
    Stack myStack;

    while (1)
    {
        menu();
        
        cin >> choice;
        if (cin.fail())
        {
            cout << "Error: Unsupported choice. " << endl;
            return 0;
        }
        cout << endl;
        
        switch (choice)
        {
            case 1:
                myStack.isEmpty();
                break;
            case 2:
                cout << "The depth of the stack is: " << myStack.getDepth() << endl;
                break;
            case 3:
                cout << "Enter an integer value to be pushed: ";
                cin >> item;
                if (cin.fail())
                {
                    cout << "Error: Wrong Item type. " << endl;
                    return 0;
                }
                cout << "Pushing item: " << item << endl;
                myStack.push(item);
                break;
            case 4:
                myStack.pop();
                break;
            case 5:
                myStack.printStack();
                break;
            case 6:
                cout << "Deleting stack... " << endl;
                myStack.~Stack();
                break;
            case 7:
                cout << "Exiting program... " << endl << endl;
                return 0;
                break;
            default:
                cout << "Invalid choice" << endl << endl;
                break;
        }
    }
    
    return 0;
}

