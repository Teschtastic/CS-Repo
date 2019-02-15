#include "ItemType.h"

#ifndef BINARYSEARCH
#define BINARYSEARCH

class BinarySearch
{
    public:
	BinarySearch();
	~BinarySearch();
	ItemType binSearch(ItemType dict[], ItemType query, int numWords);
};
#endif
