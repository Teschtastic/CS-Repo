#include "queue.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
   char command;
   ifstream inFile;
   Queue myQ;
   ItemType myData;
   string comment;

   inFile.open("testdata.dat");

   inFile >> command;
   while (!inFile.eof())
   {
	switch (command)
	{
	    case 'N':
		cout << myQ.isEmpty() << endl;
	    break;

	    case 'L':
		cout << "The length of the queue is " << myQ.getLength() << endl;
	    break;

	    case 'F':
		myData = myQ.getFront();
		cout << "The front of the queue is " << myData << endl;
	    break;

	    case 'D':
		myData = myQ.dequeue();
		cout << "The data just dequeued is " << myData << endl;
	    break;

	    case 'P':
		myQ.printQueue();
	    break;

	    case 'X':
		myQ.~Queue();
	    break;

	    case 'E':
		inFile >> myData;
		myQ.enqueue(myData);
	    break;

	    case 'C':
		getline(inFile, comment);
		cout << comment << endl;
		break;

	    default:
		cout << "Bad data read from the input file: " << command << endl;
	    break;

	}
	if (command != 'C')
	    cout << endl;
	inFile >> command;
   }
   inFile.close();
}
