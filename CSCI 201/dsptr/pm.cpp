#include <iostream>

using namespace std;

struct LLStruct
{
    int data;
    LLStruct *next;
};

void LLInsert(LLStruct **parent, LLStruct *searchPtr, int insertData);

int main()
{
    LLStruct *head, *temp;

    head = NULL;
    LLInsert(&head, head, 42);
    LLInsert(&head, head, 16);
    LLInsert(&head, head, 55);
    LLInsert(&head, head, 23);
    temp = head;
    while (temp != NULL)
    {
	cout << temp->data << endl;
	temp = temp->next;
    }

    return 0;
}

void LLInsert(LLStruct **parent, LLStruct *searchPtr, int insertData)
{
    // LLInsert uses a pointer-to-a-pointer to perform
    // linked list insertion without using a trailing
    // single-* pointer. This allows us to eliminate the
    // special cases for inserting into an empty list,
    // inserting after the final node in the list,
    // and inserting in front of the root.
    // The code is much simpler due to the use of a **ptr.
    // Note that this is also a recursive LList insert.

    if (*parent == NULL)
    {
	*parent = new LLStruct;
	(*parent)->next = NULL;
	(*parent)->data = insertData;
    }
    else if (insertData < searchPtr->data)
    {
	*parent = new LLStruct;
        (*parent)->next = searchPtr;
        (*parent)->data = insertData;
    }
    else
	LLInsert(&(searchPtr->next), searchPtr->next, insertData);

    return;
}
