#include "ItemType.h"

#ifndef MERGESORT
#define MERGESORT

class MergeSort
{
    public:
	MergeSort();
	~MergeSort();
	void mergeSort(ItemType dict[], int start, int end);
	void merge(ItemType dict[], int start, int mid, int end);
};
#endif
