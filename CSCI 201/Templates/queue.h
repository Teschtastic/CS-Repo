/*
 Sean Tesch   CSCI 201    Assignment #8
 Due: Monday, November 30, 2015 @ Midnight
 
 To compile, write in the command line:
 g++ -o driver driver.cpp ItemType.cpp
 
 To run, write in the command line:
 ./driver input.txt
 */

#include "ItemType.h"

using namespace std;

#ifndef QUEUE
#define QUEUE

/* - Create the queue class - */
template <typename QType>
class Queue
{
public:
    Queue();
    ~Queue();
    Queue(const Queue & origElement);
    const Queue & operator=(const Queue &rhs);
    bool isEmpty();
    void enqueue(QType data);
    QType dequeue();
    QType getFront();
    void printQueue();
    int getLength();
    
private:
    struct QueueNode
    {
        QType item;
        QueueNode *next;
    };
    
    QueueNode *front, *back;
    int length;
};

/* - Constructor - */
template <typename QType>
Queue<QType>::Queue()
{
    front = NULL;
    back = NULL;
    length = 0;
}

/* - Destructor - */
template <typename QType>
Queue<QType>::~Queue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

/* - Copy Constructor - */
template <typename QType>
Queue<QType>::Queue(const Queue & origElement)
{
    QueueNode *tempOrig, *tempThis;
    
    tempOrig = origElement.front;
    
    if (origElement.front != NULL)
    {
        front = new(QueueNode);
        front -> item = tempOrig -> item;
        front -> next = NULL;
        tempOrig = tempOrig -> next;
        tempThis = front;
        while (tempOrig != NULL)
        {
            tempThis -> next = new(QueueNode);
            tempThis = tempThis -> next;
            tempThis -> item = tempOrig -> item;
            tempThis -> next = NULL;
            tempOrig = tempOrig -> next;
        }
    }
    else
        front = NULL;
}

/* - Equals overload operation - */
template <typename QType>
const Queue<QType> & Queue<QType>::operator=(const Queue &rhs)
{
    QueueNode *tempRhs, tempThis;
    
    tempRhs = rhs.front;
    
    if (rhs.front != NULL)
    {
        front = new(QueueNode);
        front -> item = tempRhs -> item;
        front -> next = NULL;
        tempRhs = tempRhs -> next;
        tempThis = front;
        while (tempRhs != NULL)
        {
            tempThis -> next = new(QueueNode);
            tempThis = tempThis -> next;
            tempThis -> item = tempRhs -> item;
            tempThis -> next = NULL;
            tempRhs = tempRhs->next;
        }
    }
    else
        front = NULL;
    
}

/* - Checks to see if queue is empty - */
template <typename QType>
bool Queue<QType>::isEmpty()
{
    return(front == NULL);
}

/* - Put an item in the back of the queue - */
template <typename QType>
void Queue<QType>::enqueue(QType data)
{
    QueueNode *temp;
    
    temp = new(QueueNode);
    temp -> item = data;
    if (front == NULL)
        front = temp;
    else
        back -> next = temp;
    back = temp;
    length++;
}

/* - Deletes from the front of the queue - */
template <typename QType>
QType Queue<QType>::dequeue()
{
    QType retVal;
    QueueNode *temp;
    
    if (!isEmpty())
    {
        length--;
        retVal = front -> item;
        temp = front;
        front = front -> next;
        temp -> next = NULL;
        
        if (front == NULL)
            back = NULL;
        
        delete(temp);
    }
    
    return(retVal);
}

/* - Retrieves the front of the queue - */
template <typename QType>
QType Queue<QType>::getFront()
{
    QType retVal;
    
    if (!isEmpty())
    {
        retVal = front -> item;
    }
    
    return(retVal);
}

/* - Prints the contents of the queue - */
template <typename QType>
void Queue<QType>::printQueue()
{
    QueueNode *temp;
    
    cout << "The Queue contents are:\n";
    temp = front;
    if (!isEmpty())
    {
        while (temp != NULL)
        {
            cout << "\t" << temp -> item << endl;
            temp = temp -> next;
        }
    }
    else
        cout << "\tNothing\n";
}

/* - Gets the length of the queue - */
template <typename QType>
int Queue<QType>::getLength()
{
    return(length);
}

#endif
