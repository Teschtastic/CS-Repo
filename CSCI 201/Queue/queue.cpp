/*
 Sean Tesch   CSCI 201    Assignment #1
 Due: Friday, September 11, 2015 @ Midnight
 
 To compile, write in the command line:
 g++ -o driver driver.cpp queue.cpp ItemType.cpp
 
 To run, write in the command line:
 ./driver
*/

#include "ItemType.h"
#include "queue.h"


Queue::Queue()
{
	front = back = NULL;                        // Set the front and back to null
	length = 0;                                 // Set the length to null
}

Queue::~Queue()
{
	while (front != NULL)                       // While the front isn't equal to null
    {
        dequeue();                              // Call the dequeue function
    }
}

bool Queue::isEmpty()
{
    return(front == NULL);                      // Return the front being set to null
}

void Queue::enqueue(ItemType data)
{
    QueueNode *temp;
    temp = new(QueueNode);
    temp -> item = data;                        // Set the item temp is pointing to to the next item
    
    if (front == NULL)                          // If front equals null
        front = temp;                           // Set front to temp
    else                                        // If not
        back -> next = temp;                    // Set next being pointed to by back equal to temp
    
    back = temp;                                // Set back to temp
    length++;                                   // Increment length
    cout << "Enqueue data: " << data << endl;   // Output the enqueue message
}

ItemType Queue::dequeue()
{
    ItemType dummy;
    QueueNode *temp;

    if (!isEmpty())
	{
	    dummy = front -> item;                  // Grab the data out of the first item in the queue
                                                // and put it in the dummy variable
        temp = front;                           // Set pointer variable to front and unlink it
        front = front -> next;                  // Check to see if the tail should be set to null
        temp -> next = NULL;
	    
	    if (front == NULL)                      // If the front is null
	    {
		back = NULL;                            // Set the back to null
	    }
	    delete(temp);                           // delete unlinked node
	    length--;                               // reduce the length by one
	}

    return(dummy);                              // Return the value of dummy
}

ItemType Queue::getFront()
{
    ItemType dummy;                             // Initialize dummy
    return(dummy);                              // Return the value of dummy
}

void Queue::printQueue()
{
    ItemType data;                              // Declared the data variable
    cout << "Dumping the queue... " << endl;    // Output message
    QueueNode *temp = front;                    // Setting a temp variable to the same as front
    while (temp != NULL)                        // While the temp file isn't null
    {
    data = temp -> item;                        // Set data to the value of item temp is pointing to
	cout << data << endl;                       // Output the value of data
    temp = temp -> next;                        // Set temp to the next item in the queue
    }
}


int Queue::getLength()
{
    return(length);                             // Return the length of the queue
}

