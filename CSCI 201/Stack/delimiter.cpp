/*
 Sean Tesch   CSCI 201    Assignment #2
 Due: Monday, September 21, 2015 @ Midnight
 
 To compile, write in the command line:
 g++ -o driver driver.cpp queue.cpp ItemType.cpp
 
 To run, write in the command line:
 ./driver
 */

#include <iostream>
#include <ostream>
#include "ItemType.h"
#include "stack.h"
#include <cctype>
#include <string>

using namespace std;

int main()
{
    ItemType myData;
    string equation;                                // The variable the equation will be stored as
    Stack myStack;
    bool error;
    
    cout << "Enter statement here: " << endl;
    getline(cin, equation);
    while (!(equation.length() == 1 && (equation[0] == 'x' || equation[0] == 'X')))
    {
        error = false;
        for (int a = 0; a < equation.length() && !error; a++)
        {
            if (equation[a] != ' ' && equation[a] != '\t')
            {
                myData.decode(equation[a]);
                
                switch (myData.getToken())
                {
                    case LPAREN:
                        myData.setBlank(true);
                        myStack.push(myData);
                        break;
                        
                    case RPAREN:
                        if (!myStack.isEmpty() && myStack.item.getToken() == LPAREN)
                        {
                            if (myStack.item.getBlank())
                                cout << "Warning: Empty set of ()'s " << endl;
                            else
                                myStack.pop();
                        }
                        else
                        {
                            error = true;
                            cout << "Found a mismatched ')' " << endl;
                            myStack.~Stack();
                        }
                        break;
                        
                    case LSQUARE:
                        myData.setBlank(true);
                        myStack.push(myData);
                        break;
                        
                    case RSQUARE:
                        if (!myStack.isEmpty() && myStack.item.getToken() == LSQUARE)
                        {
                            if (myStack.item.getBlank())
                                cout << "Warning: Empty set of []'s " << endl;
                            else
                                myStack.pop();
                        }
                        else
                        {
                            error = true;
                            cout << "Found a mismatched ']' " << endl;
                            myStack.~Stack();
                        }
                        break;
                        
                    case LCURLY:
                        myData.setBlank(true);
                        myStack.push(myData);
                        break;
                        
                    case RCURLY:
                        if (!myStack.isEmpty() && myStack.item.getToken() == LCURLY)
                        {
                            if (myStack.item.getBlank())
                                cout << "Warning: Empty set of {}'s " << endl;
                            else
                                myStack.pop();
                        }
                        else
                        {
                            error = true;
                            cout << "Found a mismatched '}' " << endl;
                            myStack.~Stack();
                        }
                        break;
                        
                    case OTHER:
                        if (!(myStack.isEmpty()))
                        {
                            myData = myStack.pop();
                            myData.setBlank(false);
                            myStack.push(myData);
                        }
                        break;
                        
                    default:
                        break;
                }
            }
        }
        
        cout << endl;
    }
    return 0;
}

