#include "ItemType.h"
#include "Mergesort.h"

MergeSort::MergeSort()
{
}

MergeSort::~MergeSort()
{
}

void MergeSort::mergeSort(ItemType myArray[], int start, int end)
{
    int mid;
    
    /* - Check to see if start is greater than end - */
    if (start >= end)
        /* - If it is, error statement, then return error value - */
        cout << "Error: Start index is higher than End Index" << endl;
        return -1;
    else
    {
        /* - If not, call the mergeSorft and merge functions - */
        mid = (end + start) / 2;
        mergeSort(myArray, start, mid);
        mergeSort(myArray, (mid + 1), end);
        
        merge(myArray, start, mid, end);
    }
}

void MergeSort::merge(ItemType myArray[], int start, int mid, int end)
{
    ItemType buffer[end-start+1];
    int buffIndex = 0, left = start, right = mid + 1;

    while (left <= mid && right <= end)
    {
	if (myArray[left] < myArray[right])
	{
	    buffer[buffIndex] = myArray[left];
	    buffIndex++;
	    left++;
	}
	else
	{
	    buffer[buffIndex] = myArray[right];
	    buffIndex++;
	    right++;
	}
    }
    while (left <= mid)
    {
	buffer[buffIndex] = myArray[left];
	buffIndex++;
	left++;
    }
    while (right <= end)
    {
	buffer[buffIndex] = myArray[right];
	buffIndex++;
	right++;
    }

    buffIndex = 0;
    for (left = start; left <= end; left++)
    {
	myArray[left] = buffer[buffIndex];
	buffIndex++;
    }

    return;
}

