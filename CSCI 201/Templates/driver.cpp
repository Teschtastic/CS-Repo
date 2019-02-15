#include <iostream>
#include "queue.h"
#include "ItemType.h"

// g++ -o driver driver.cpp ItemType.cpp

using namespace std;

// Prototype for a generic function to decode the action to be taken
template <typename QType>
void takeAction(Queue<QType> &myQueue, char comm, QType data);

int main(int argc, char *argv[])
{
    char command, datatype, dummy;
    ifstream infile;
    
    // What types of stacks do we need?
    Queue<int> myIntQueue;
    int intData;
    Queue<char> myCharQueue;
    char charData;
    long longData;
    float floatData;
    double doubleData;
    string stringData;
    ItemType dictEntry;
    string inWord;
    string inDef;
    
    // Did we get an input filename on the command-line?
    if (argc != 2)
    {
        cout << "ERROR: Wrong number of parameters\n";
        cout << "Usage: " << argv[0] << " <input filename>\n";
        return(-1);
    }
    
    // Can we open the input filename?
    infile.open(argv[1]);
    if (infile.fail())
    {
        cout << "ERROR: Unable to open input file " << argv[1] << endl;
        return(-1);
    }
    
    infile >> datatype;  // Odd read to get infile.eof() to work correctly
    while (!infile.eof())
    {
        infile >> command;
        switch (datatype)
        {
            case 'i':
                // Get the integer data
                infile >> intData;
                // Call the generic stack action function
                takeAction(myIntQueue, command, intData);
                break;
                
            case 'l':  // That's a lowercase L!
                infile >> longData;
                break;
                
            case 'f':
                infile >> floatData;
                break;
                
            case 'd':
                infile >> doubleData;
                break;
                
            case 'c':
                // Get the character data
                infile >> charData;
                // Call the generic stack action function
                takeAction(myCharQueue, command, charData);
                break;
                
            case 'w':
                infile >> inWord;
                infile >> dummy;
                getline(infile, inDef);
                dictEntry.setWord(inWord);
                dictEntry.setDefinition(inDef);
                break;
                
            case 's':
                infile >> intData;
                break;
                
            default:
                cout << "ERROR: Unknown type identifier: " << datatype << endl;
        }
        infile >> datatype;
    }
    // Clean up the file stream after we're done reading
    infile.close();
    
    return 0;
}

template <typename QType>
void takeAction(Queue<QType> &myQueue, char comm, QType data)
{
    QType myData;
    string comment;
    
    switch (comm)
    {
        case 'N':
            if (myQueue.isEmpty())
                cout << "Empty" << endl;
            else
                cout << "Not Empty" << endl;
            break;
            
        case 'L':
            cout << "The length of the queue is " << myQueue.getLength() << endl;
            break;
            
        case 'F':
            myData = myQueue.getFront();
            cout << "The front of the queue is " << myData << endl;
            break;
            
        case 'D':
            myData = myQueue.dequeue();
            cout << "The data just dequeued is " << myData << endl;
            break;
            
        case 'P':
            myQueue.printQueue();
            break;
            
        case 'X':
            myQueue.~Queue<QType>();
            break;
            
        case 'E':
            myQueue.enqueue(data);
            break;
            
        default:
            cout << "ERROR: Bad action " << comm <<" read from input file\n";
            break;
    }
}
