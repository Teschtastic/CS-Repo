#include "ItemType.h"
#include "binsearch.h"
#include <iostream>

using namespace std;

BinarySearch::BinarySearch()
{
}

BinarySearch::~BinarySearch()
{
}

ItemType BinarySearch::binSearch(ItemType dict[], ItemType query, int numWords)
{
    /*ItemType junk;

    junk.setWord("junk");
    junk.setDefinition("Garbage data with which to test");

    cout << "Report from inside the class looking for " << query << endl;
    for (int i = 0; i < numWords; i++)
	cout << dict[i] << endl;

    cout << junk << endl;
    return(junk); */
    
    int head = 0;
    int tail = numWords - 1;
    int mid = -1;
    
    while (head < tail)
    {
        mid = (tail + head) / 2;
        if (dict[mid] == query)
        {
            query.setDefinition(dict[mid].getDefinition());
            return (query);
        }
        else if (dict[mid] < query)
        {
            head = mid + 1;
        }
        else
        {
            tail = mid - 1;
        }
    }
}
