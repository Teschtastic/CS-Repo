//  Sorting Algorithms
//  Selection, Merge, and Radix
//
//  Created by Sean Tesch on 9/11/17.

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

// Swap used for Selection Sort
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

// Function for Selection Sort
void selectionSort(int array[], int n)
{
    int i, j, min;
    
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            // if the current minimum elemtnt is > than j, set the min element to j
            if (array[min] > array[j])
                min = j;
        //Swapping the min element  and i
        swap(&array[i], &array[min]);
    }
}

// Function to merge
void merge(int array[], int start, int middle, int end)
{
    int i = 0, j = 0, k = start;
    int n1 = (middle - start) + 1;
    int n2 =  end - middle;
    int left[n1], right[n2];
    
    // set the start array to the next element in array
    for (i = 0; i < n1; i++)
        left[i] = array[start + i];
    
    // set the end array to the middle of array plus 1 and j
    for (j = 0; j < n2; j++)
        right[j] = array[middle + 1 + j];
    
    while (i < n1 && j < n2)
    {
        // if start element is smaller than the end
        if (left[i] <= right[j])
        {
            // set array to the i element and increment i
            array[k] = left[i]; i++;
        }
        else
            // else set the array to end and increment j
            array[k] = right[j]; j++;
        k++;
    }
    while (i < n1)
        // sets the array to the i element of left
        array[k] = left[i]; i++; k++;
    
    while (j < n2)
        // sets the array to the j element of right
        array[k] = right[j]; j++; k++;
}

// Recursive function for Merge Sort
void mergeSort(int array[], int start, int end)
{
    if (start < end)
    {
        // sets the middle partition
        int middle = start+(end-start)/2;
        
        // recurses merge sort from start to end
        mergeSort(array, start, middle);
        mergeSort(array, middle+1, end);
        
        // merges the partitions together
        merge(array, start, middle, end);
    }
}

// Get the maximum element in the array
int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

// Counts each digit
void counting(int array[], int n, int dec)
{
    int output[n];
    int i, count[10] = {0};
    
    // Stores a count for each base digit in array
    for (i = 0; i < n; i++)
        count[(array[i] / dec) % 10]++;
    
    // Stores the actual location of the digit in count
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Builds the Output array
    for (i = n - 1; i >= 0; i--)
    {
        // sets the output of the digit's location equal the the array element
        output[count[(array[i] / dec) % 10] - 1] = array[i];
        // Decrements the digit once it's in the output array
        count[(array[i]/dec) % 10]--;
    }
}

// The main Radix sort function
void radixSort(int array[], int n)
{
    // Gets the maximum element in the array
    int max = getMax(array, n);
    
    // runs the count sort for every digit in the array
    for (int dec = 1; max/dec > 0; dec *= 10)
        counting(array, n, dec);
}

// Times the sorting algorithm
float timing(clock_t end, clock_t start)
{
    float ticks = end - start;
    float ms = ticks / (CLOCKS_PER_SEC / 1000);
    return ms;
}

int main()
{
    int size = 10000;
    
    int array[size], sarray[size], marray[size], rarray[size];
    srand((unsigned)time(0));
    
    // Sets the arrays to the same random ints
    for(int i = 0; i < size; i++)
        array[i] = sarray[size] = marray[size] = rarray[size] = (rand() % size) + 1;
    
    int n = (int)sizeof(array) / sizeof(array[0]);
    
    // Timing Selection sort
    clock_t start = clock(); selectionSort(sarray, n); clock_t end = clock();
    cout << "Selection Sort took: " << timing(end, start) << " ms to complete on " << n << " items" << endl;
    
    // Timing Merge sort
    start = clock(); mergeSort(marray, 0, n -1); end = clock();
    cout << "Merge Sort took: " << timing(end, start) << " ms to complete on " << n << " items" << endl;
    
    // Timing Radix sort
    start = clock(); radixSort(rarray, n); end = clock();
    cout << "Radix Sort took: " << timing(end, start) << " ms to complete on " << n << " items" << endl;
    
    return 0;
}
