//
//  n squared sort.cpp
//  
//
//  Created by Sean Tesch on 9/11/17.
//
//

#include <stdio.h>

void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void selectionSort(int array[], int n)
{
    int i, j, min;
    
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
            if (array[j] < array[min])
                min_idx = j;
        
        swap(array[min], array[i]);
    }
}

void printArray(int array[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << array[i] << " ";
}

int main()
{
    int array[] = {64, 25, 12, 22, 11};
    int n = sizeof(array)/sizeof(array[0]);
    selectionSort(array, n);
    cout << "Sorted array" << endl;
    printArray(arr, n);
    return 0;
}
